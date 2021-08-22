// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "Checkout.h"
#include "../ui_Chekout.h"

#include <qpdfwriter.h>
#include <qtextdocument.h>
#include <qprinter.h>

/**
 * Daily allocation limit.
 * This is the maximum time a truck can have for a day in minutes.
 */
constexpr float DailyAllocationLimit = 60.0f * 8.0f;

Checkout::Checkout(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QWidget(parent)
	, pCheckout(std::make_unique<Ui::Checkout>())
	, pApplicationState(pApplicationState)
{
	pCheckout->setupUi(this);

	// Set the current date.
	pCheckout->dateLabel->setText(QDateTime::currentDateTime().date().toString());

	// Set trucks.
	const auto trucks = pApplicationState->GetTrucks();
	for (const auto truck : trucks)
	{
		QVariant varient = truck.GetID();
		pCheckout->truckSelect->addItem(("Truck " + std::to_string(truck.GetID())).c_str(), varient);
	}

	// Setup callbacks.
	QObject::connect(pCheckout->truckSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(HandleTruckSelect(int)));
	QObject::connect(pCheckout->generateDocuments, &QPushButton::pressed, this, &Checkout::HandleGenerateDocument);
}

void Checkout::Refresh()
{
	pCheckout->truckSelect->clear();
	pCheckout->dateLabel->setText(QDateTime::currentDateTime().date().toString());

	// Set trucks.
	const auto trucks = pApplicationState->GetTrucks();
	for (const auto truck : trucks)
	{
		QVariant varient = truck.GetID();
		pCheckout->truckSelect->addItem(("Truck " + std::to_string(truck.GetID())).c_str(), varient);
	}

	mCurrentTruckIndex = -1;
}

void Checkout::HandleTruckSelect(int index)
{
	// Skip if the index is less than 0 (invalid).
	if (index < 0)
		return;

	mCurrentTruckIndex = index;
	DisplayInformation();
}

void Checkout::HandleGenerateDocument()
{
	// Skip if a truck is not selected.
	if (mCurrentTruckIndex < 0)
		return;

	std::vector<Route> finalRoutes;
	auto data = pCheckout->truckSelect->itemData(mCurrentTruckIndex);
	const auto truck = pApplicationState->FindTruck(data.value<int>());

	float totalTime = 0.0f;
	bool isFinalized = false;

	// Display route, location and item information.
	const auto routes = pApplicationState->GetRoutes();
	for (const auto route : routes)
	{
		if (route.GetTruck() == truck && route.GetDateTime().date() == QDateTime::currentDateTime().date())
		{
			// If finalized, set the next date to the route.
			if (isFinalized || totalTime >= DailyAllocationLimit)
			{
				pApplicationState->FindRoute(route.GetNumber()).SetNextDate();
				continue;
			}

			// Get the route's estimated delivery time.
			float routeTime = route.GetEstimatedDeliveryTime();

			// If the route takes more time than what is allowed, check if we can deliver any goods, if not assign this route to the next day.
			if (totalTime + routeTime > DailyAllocationLimit)
			{
				Route temporaryRoute(route.GetNumber(), truck, route.GetDateTime());

				auto orders = route.GetOrders();
				for (const auto order : orders)
				{
					// If we cant add more items, set add the temporary route if we have data in it, set the next date to the current route and exit.
					if (totalTime + (order.mPackages.size() * 10) + 30.0f > DailyAllocationLimit)
					{
						if (temporaryRoute.GetCurrentLoad() > 0)
						{
							finalRoutes.push_back(temporaryRoute);
							isFinalized = true;
						}

						// If the route cannot be included, increment the date.
						pApplicationState->FindRoute(route.GetNumber()).SetNextDate();
						break;
					}
					else
					{
						// If we can have the order, add it to the list.
						temporaryRoute.AddOrder(order);
						totalTime += (order.mPackages.size() * 10.0f) + 30.0f;

						pApplicationState->FindRoute(route.GetNumber()).RemoveOrder(order.mLocation.GetName());
					}
				}

				if (!isFinalized)
				{
					finalRoutes.push_back(temporaryRoute);
					pApplicationState->FindRoute(route.GetNumber()).SetNextDate();
				}

				if (pApplicationState->FindRoute(route.GetNumber()).GetCurrentLoad() == 0)
					pApplicationState->RemoveRoute(route.GetNumber());
			}
			else
			{
				// If there is space to fit the route, add it to the list.
				finalRoutes.push_back(route);
				pApplicationState->RemoveRoute(route.GetNumber());

				totalTime += routeTime;
			}
		}
	}

	// Generate the documents and display the information.
	GenerateDocuments(truck, finalRoutes);
	DisplayInformation();
}

void Checkout::DisplayInformation()
{
	// Clear all the existing information.
	ClearInformation();

	// Get the relevant data.
	auto data = pCheckout->truckSelect->itemData(mCurrentTruckIndex);
	const auto truck = pApplicationState->FindTruck(data.value<int>());
	pCheckout->truckCapacity->setText(std::to_string(truck.GetTotalCapacity()).c_str());

	int itemsToDeliver = 0, currentTotalLoad = 0;
	float estimatedTime = 0;

	// Display route, location and item information.
	for (const auto route : pApplicationState->GetRoutes())
	{
		if (route.GetTruck() == truck && route.GetDateTime().date() == QDateTime::currentDateTime().date())
		{
			pCheckout->routes->addItem(("Route number: " + std::to_string(route.GetNumber())).c_str());
			estimatedTime += route.GetEstimatedDeliveryTime();

			for (const auto order : route.GetOrders())
			{
				// Do not add the location if already within the list.
				if (pCheckout->locations->findItems(order.mLocation.GetName(), Qt::MatchFlag::MatchCaseSensitive).isEmpty())
					pCheckout->locations->addItem(order.mLocation.GetName());

				for (const auto package : order.mPackages)
				{
					// Do not add the item if already within the list.
					if (pCheckout->items->findItems(package.mItem.GetName(), Qt::MatchFlag::MatchCaseSensitive).isEmpty())
						pCheckout->items->addItem(package.mItem.GetName());

					itemsToDeliver++;
					currentTotalLoad += package.GetSize();
				}
			}
		}
	}

	// Set the additional information.
	pCheckout->itemsToDeliver->setText(std::to_string(itemsToDeliver).c_str());
	pCheckout->totalLoad->setText(std::to_string(currentTotalLoad).c_str());
	pCheckout->estimatedTime->setText((std::to_string(static_cast<int>(estimatedTime / 60)) + "h").c_str());
}

void Checkout::ClearInformation()
{
	pCheckout->routes->clear();
	pCheckout->locations->clear();
	pCheckout->items->clear();
	pCheckout->itemsToDeliver->clear();
	pCheckout->truckCapacity->clear();
	pCheckout->totalLoad->clear();
	pCheckout->estimatedTime->clear();
	pCheckout->truckSelect->setCurrentIndex(mCurrentTruckIndex);
}

void Checkout::GenerateDocuments(const Truck truck, const std::vector<Route> routesForTheDay)
{
	const QString routeDocumentFile = "RouteDocument-" + QString(std::to_string(truck.GetID()).c_str()) + "-" + QDateTime::currentDateTime().toString("dd-MM-yy") + ".pdf";
	const QString loadingOrderDocumentFile = "LoadingOrderDocument-" + QString(std::to_string(truck.GetID()).c_str()) + "-" + QDateTime::currentDateTime().toString("dd-MM-yy") + ".pdf";

	// Setup the strings to hold the document information.
	QString routeDocumentContent = "<h1>Route Information Document - Truck ID: " + QString(std::to_string(truck.GetID()).c_str()) + "</h1>";
	QString loadingOrderDocumentContent = "<h1>Loading Order Document - Truck ID: " + QString(std::to_string(truck.GetID()).c_str()) + "</h1>";

	// Iterate through the routes and add their content to the strings.
	for (const auto route : routesForTheDay)
	{
		routeDocumentContent += "<h2>Route: " + QString(std::to_string(route.GetNumber()).c_str()) + "</h2>";
		routeDocumentContent += "<dl style=\"font-size: large;\">";

		// Iterate through the orders.
		for (auto order : route.GetOrders())
		{
			routeDocumentContent += "<dt>" + order.mLocation.GetName() + " <br> - Address: " + order.mLocation.GetAddress() + "</dt>";

			loadingOrderDocumentContent += "<h2>Location: " + order.mLocation.GetName() + " <br> - Address: " + order.mLocation.GetAddress() + "</h2>";
			loadingOrderDocumentContent += "<ol style=\"font-size: large;\">";

			// Sort the orders.
			order.Sort();

			// Iterate through the packages.
			for (const auto package : order.mPackages)
			{
				routeDocumentContent += "<dd>"
					+ package.mItem.GetName()
					+ " <br> - Unit size: "
					+ QString(std::to_string(package.mItem.GetSize()).c_str())
					+ " <br> - Quantity: "
					+ QString(std::to_string(package.mQuantity).c_str())
					+ "</dd> <br>";

				loadingOrderDocumentContent += "<li>"
					+ package.mItem.GetName()
					+ " <br> - Unit size: "
					+ QString(std::to_string(package.mItem.GetSize()).c_str())
					+ " <br> - Quantity: "
					+ QString(std::to_string(package.mQuantity).c_str())
					+ "</li>";
			}

			loadingOrderDocumentContent += "</ol>";
		}

		routeDocumentContent += "</dl>";
	}

	// Create the printer object to support printing to a pdf file.
	QPrinter printer(QPrinter::PrinterResolution);
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setPageSize(QPageSize(QPageSize::A4));
	printer.setPageMargins(QMarginsF(15, 15, 15, 15));

	// Create the text document object to store and print the pdf file.
	QTextDocument document;

	// Print the route document.
	document.setHtml(routeDocumentContent);
	printer.setOutputFileName(routeDocumentFile);
	document.print(&printer);

	// Print the loading order document.
	document.setHtml(loadingOrderDocumentContent);
	printer.setOutputFileName(loadingOrderDocumentFile);
	document.print(&printer);
}
