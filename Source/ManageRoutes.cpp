#include "ManageRoutes.h"
#include "ui_ManageRoutes.h"

#include "MainWindow.h"
#include "ItemSelection.h"

#include <QtWidgets/QMessageBox.h>

#include <stdexcept>

ManageRoutes::ManageRoutes(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QMainWindow(parent)
	, pManageRoutes(std::make_unique<Ui::ManageRoutes>())
	, pApplicationState(pApplicationState)
{
	pManageRoutes->setupUi(this);

	// Set the routes.
	const auto routes = pApplicationState->GetRoutes();
	for (const auto route : routes)
		pManageRoutes->routeList->addItem(("Route number: " + std::to_string(route.GetNumber())).c_str());

	// Set trucks.
	const auto trucks = pApplicationState->GetTrucks();
	for (const auto truck : trucks)
	{
		QVariant varient = truck.GetID();
		pManageRoutes->truckSelection->addItem(("Truck " + std::to_string(truck.GetID())).c_str(), varient);
	}

	// Set the locations.
	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		pManageRoutes->locationList->addItem(location.GetName().c_str());

	// Setup callbacks.
	QWidget::connect(pManageRoutes->truckSelection, SIGNAL(currentIndexChanged(int)), this, SLOT(HandleTruckSelection(int)));
	QWidget::connect(pManageRoutes->routeList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleRouteSelection(QListWidgetItem*)));
	QObject::connect(pManageRoutes->locationList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleLocationSelection(QListWidgetItem*)));
	QObject::connect(pManageRoutes->selectedLocations, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleSelectedLocationSelection(QListWidgetItem*)));
	QObject::connect(pManageRoutes->removeFromSelected, &QPushButton::pressed, this, &ManageRoutes::HandleRemoveFromSelected);
	QObject::connect(pManageRoutes->remove, &QPushButton::pressed, this, &ManageRoutes::HandleRemoveFromRoutes);
	QObject::connect(pManageRoutes->addToList, &QPushButton::pressed, this, &ManageRoutes::HandleAddToList);
}

void ManageRoutes::closeEvent(QCloseEvent* event)
{
	MainWindow* pMainWindow = static_cast<MainWindow*>(parent());
	pMainWindow->UpdateRouteList();
	pMainWindow->DeleteChild(this);
}

void ManageRoutes::DeleteChild(QWidget* pChild)
{
	delete pChild;
}

void ManageRoutes::SubmitOrder(const Order& order, const QString& location)
{
	mOrderMap[location] = order;
}

void ManageRoutes::HandleRouteSelection(QListWidgetItem* pItem)
{
	mSelectedRoute = pManageRoutes->routeList->indexFromItem(pItem).row();
	UpdateInformation();
}

void ManageRoutes::HandleLocationSelection(QListWidgetItem* pItem)
{
	ItemSelection* pItemSelection = new ItemSelection(pItem->text().toStdString(), pApplicationState, this);
	pItemSelection->show();

	pManageRoutes->selectedLocations->addItem(pManageRoutes->locationList->takeItem(pManageRoutes->locationList->indexFromItem(pItem).row()));
}

void ManageRoutes::HandleSelectedLocationSelection(QListWidgetItem* pItem)
{
	mSelectedLocationToRemove = pManageRoutes->selectedLocations->indexFromItem(pItem).row();
}

void ManageRoutes::HandleTruckSelection(int index)
{
	// Do nothing for now.
}

void ManageRoutes::HandleRemoveFromSelected()
{
	// Skip if the user have not selected a location to remove.
	if (mSelectedLocationToRemove < 0)
		return;

	const auto pItem = pManageRoutes->selectedLocations->takeItem(mSelectedLocationToRemove);
	pManageRoutes->locationList->addItem(pItem);
	mSelectedLocationToRemove--;

	// Remove the item from the order map.
	mOrderMap.erase(pItem->text());
}

void ManageRoutes::HandleRemoveFromRoutes()
{
	// Skip if the user have not selected a route.
	if (mSelectedRoute < 0)
		return;

	const auto pItem = pManageRoutes->routeList->takeItem(mSelectedRoute);
	pApplicationState->RemoveRoute(std::stoi(std::string(pItem->text().toStdString()).substr(14)));
	mSelectedRoute--;
}

void ManageRoutes::HandleAddToList()
{
	try
	{
		// Get the route number.
		bool isConversionSuccessful = false;
		const auto routeNumber = pManageRoutes->addRouteNumber->toPlainText().toInt(&isConversionSuccessful);

		// Check if the route number is an integer.
		if (isConversionSuccessful == false)
			throw std::runtime_error("The route number should be a number!");

		int truckIndex = pManageRoutes->truckSelection->currentIndex();

		// Check if a truck is selected.
		if (truckIndex < 0)
			throw std::runtime_error("Make sure to select a truck!");

		// Check if the route number is unique.
		if (pApplicationState->IsRoutePresent(routeNumber))
			throw std::runtime_error("A route with the same route number is present within the application. Make sure that the route number is unique!");

		// Create the new route.
		Route newRoute(routeNumber, pApplicationState->FindTruck(pManageRoutes->truckSelection->currentData().toInt()));

		// Set the locations.
		for (int row = 0; row < pManageRoutes->selectedLocations->count(); row++)
			newRoute.AddOrder(mOrderMap[pManageRoutes->selectedLocations->item(row)->text()]);

		// Register the new route.
		pApplicationState->RegisterRoute(newRoute);

		// Update the route list.
		pManageRoutes->routeList->clear();

		const auto routes = pApplicationState->GetRoutes();
		for (const auto route : routes)
			pManageRoutes->routeList->addItem(("Route number: " + std::to_string(route.GetNumber())).c_str());
	}
	catch (std::exception e)
	{
		QMessageBox issueWarning;
		issueWarning.setText(e.what());
		issueWarning.exec();
	}

	pManageRoutes->truckSelection->setCurrentIndex(-1);
	ClearInformation();
}

void ManageRoutes::UpdateInformation()
{
	// Skip if the user have not selected a route.
	if (mSelectedRoute < 0)
		return;

	ClearInformation();

	// Get the route.
	const auto pRoute = pManageRoutes->routeList->item(mSelectedRoute);
	const auto route = pApplicationState->GetRoutes()[std::stoi(std::string(pRoute->text().toStdString()).substr(14))];

	// Select the correct truck.
	int truckIndex = pManageRoutes->truckSelection->findData(QVariant(route.GetTruck().GetID()));
	pManageRoutes->truckSelection->setCurrentIndex(truckIndex);

	// Setup the locations.
	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
	{
		if (route.IsInRoute(location))
			pManageRoutes->selectedLocations->addItem(location.GetName().c_str());
		else
			pManageRoutes->locationList->addItem(location.GetName().c_str());
	}

	// Set other information.
	pManageRoutes->routeNumber->setText(std::to_string(route.GetNumber()).c_str());
	pManageRoutes->locationCount->setText(std::to_string(route.GetOrders().size()).c_str());
	pManageRoutes->itemCount->setText(std::to_string(route.GetTotalItemCount()).c_str());
	pManageRoutes->truckCapacity->setText(std::to_string(route.GetTruck().GetTotalCapacity()).c_str());
	pManageRoutes->currentCapacity->setText(std::to_string(route.GetCurrentLoad()).c_str());
}

void ManageRoutes::ClearInformation()
{
	pManageRoutes->addRouteNumber->clear();
	pManageRoutes->routeNumber->clear();
	pManageRoutes->locationCount->clear();
	pManageRoutes->itemCount->clear();
	pManageRoutes->truckCapacity->clear();
	pManageRoutes->currentCapacity->clear();
}
