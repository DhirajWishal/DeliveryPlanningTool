// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "ApplicationState.h"

#include <QFile.h>
#include <QXmlStream.h>
#include <fstream>

ApplicationState::ApplicationState()
{
	// Load data if possible. If failed, add the defaults.
	if (LoadData() == false)
	{
		mLocations.push_back(Location("Top Beauty Inc.", "370 Alden Rd, Markham, ON L3R 4C1, Canada"));
		mLocations.push_back(Location("Hair Granted Beauty Supply Inc.", "200 Queens Plate Dr, Etobicoke, ON M9W 6V1, Canada"));
		mLocations.push_back(Location("MAC Cosmetics", "368 Queen St W, Toronto, ON M5V 2A2, Canada"));
		mLocations.push_back(Location("Aesop", "880 Queen St W, Toronto, ON M6J 1G3, Canada"));
		mLocations.push_back(Location("LUSH", "312 Queen St W, Toronto, ON M5V 2A2, Canada"));
		mLocations.push_back(Location("The Detox Market", "116 Spadina Ave., Toronto, ON M5V 2K6, Canada"));
		mLocations.push_back(Location("Ellemoor Cosmetics", "803 Bloor St W, Toronto, ON M6G 1L8, Canada"));
		mLocations.push_back(Location("The Body Shop", "2366 Bloor St W, Toronto, ON M6S 1P3, Canada"));
	}
}

ApplicationState::~ApplicationState()
{
	DumpData();
}

const Truck ApplicationState::FindTruck(int ID) const
{
	for (const auto truck : mTrucks)
		if (truck.GetID() == ID)
			return truck;

	return Truck();
}

const Location ApplicationState::FindLocation(const QString& location) const
{
	for (const auto element : mLocations)
		if (element.GetName() == location)
			return element;

	return Location();
}

const bool ApplicationState::IsLocationPresent(const Location& location) const
{
	for (const auto element : mLocations)
		if (element == location)
			return true;

	return false;
}

const Item ApplicationState::FindItem(const QString& itemName) const
{
	for (const auto item : mItems)
		if (item.GetName() == itemName)
			return item;

	return Item();
}

const Route ApplicationState::FindRoute(int number) const
{
	for (const auto route : mRoutes)
		if (route.GetNumber() == number)
			return route;

	return Route();
}

void ApplicationState::RemoveRoute(int number)
{
	for (auto itr = mRoutes.begin(); itr != mRoutes.end(); ++itr)
	{
		if (itr->GetNumber() == number)
		{
			mRoutes.erase(itr);
			return;
		}
	}
}

const bool ApplicationState::IsRoutePresent(int number) const
{
	for (const auto route : mRoutes)
		if (route.GetNumber() == number)
			return true;

	return false;
}

bool ApplicationState::LoadData()
{
	QFile sessionFile("session.xml");

	// Try and open the file. Return false if failed.
	if (!sessionFile.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;

	// Read the session xml.
	QXmlStreamReader sessionReader(&sessionFile);

	// Parse the xml file.
	while (!sessionReader.atEnd() || !sessionReader.hasError())
	{
		QXmlStreamReader::TokenType token = sessionReader.readNext();

		// Skip if the current token is the document start.
		if (token == QXmlStreamReader::StartDocument)
			continue;

		// Parse if the token is a start element.
		if (token == QXmlStreamReader::StartElement)
		{
			QString name = sessionReader.name().toString();
			auto attributes = sessionReader.attributes();

			// Skip if we are at the root node.
			if (name.compare("application", Qt::CaseInsensitive) == 0)
				continue;

			// Add truck if the tag is truck.
			if (name.compare("truck", Qt::CaseInsensitive) == 0)
				mTrucks.push_back(Truck(attributes.value("id").toInt(), attributes.value("capacity").toInt()));

			// Add location.
			if (name.compare("location", Qt::CaseInsensitive) == 0)
				mLocations.push_back(Location(attributes.value("name").toString(), sessionReader.readElementText()));

			// Add the item.
			if (name.compare("item", Qt::CaseInsensitive) == 0)
				mItems.push_back(Item(attributes.value("name").toString(), attributes.value("size").toInt()));

			// Add route.
			if (name.compare("route", Qt::CaseInsensitive) == 0)
			{
				int routeNumber = attributes.value("number").toInt();
				int truckID = attributes.value("truck").toInt();
				QDateTime dateTime;

				// Read the date adn time information.
				sessionReader.readNextStartElement();
				name = sessionReader.name().toString();
				attributes = sessionReader.attributes();

				if (name.compare("datetime", Qt::CaseInsensitive) == 0)
					dateTime = QDateTime::fromString(sessionReader.readElementText(), "dd.MM.yyyy hh:mm:ss");

				Route route(routeNumber, FindTruck(truckID), dateTime);

				// Handle all the orders
				while (sessionReader.readNextStartElement())
				{
					name = sessionReader.name().toString();
					attributes = sessionReader.attributes();

					// Handle open tags.
					Order order;
					if (name.compare("order", Qt::CaseInsensitive) == 0)
					{
						QString locationName = attributes.value("location").toString();
						order = Order(FindLocation(locationName));
					}

					// Handle all the packages.
					while (sessionReader.readNextStartElement())
					{
						name = sessionReader.name().toString();
						attributes = sessionReader.attributes();

						// Add the package to the order.
						if (name.compare("package", Qt::CaseInsensitive) == 0)
							order.mPackages.push_back(Package(FindItem(attributes.value("item").toString()), attributes.value("quantity").toInt()));

						sessionReader.skipCurrentElement();
					}

					// Add the order to the route.
					route.AddOrder(order);
				}

				mRoutes.push_back(route);
			}
		}
	}

	// Set the result as true if parsed correctly.
	bool result = true;
	if (sessionReader.hasError())
		result = false;

	// Close and clear the parser and file.
	sessionReader.clear();
	sessionFile.close();

	return result;
}

void ApplicationState::DumpData() const
{
	std::ofstream outputFile("session.xml");

	// Exit if we couldn't open the file.
	if (!outputFile.is_open())
		return;

	outputFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
	outputFile << "<application>" << std::endl;

	// Dump all trucks.
	for (const auto truck : mTrucks)
		outputFile << "<truck id=\"" << truck.GetID() << "\" capacity=\"" << truck.GetTotalCapacity() << "\" />" << std::endl;

	// Dump all locations.
	for (const auto location : mLocations)
	{
		outputFile
			<< "<location name=\"" << location.GetName().toStdString() << "\" >"
			<< location.GetAddress().toStdString() << std::endl
			<< "</location>" << std::endl;
	}

	// Dump all items.
	for (const auto item : mItems)
		outputFile << "<item name=\"" << item.GetName().toStdString() << "\" size=\"" << item.GetSize() << "\" />" << std::endl;

	// Dump all routes.
	for (const auto route : mRoutes)
	{
		outputFile << "<route number=\"" << route.GetNumber() << "\" truck=\"" << route.GetTruck().GetID() << "\" >" << std::endl;
		outputFile << "<datetime>" << route.GetFormattedDateTimeString().toStdString() << "</datetime>" << std::endl;

		// Dump all the orders.
		for (const auto order : route.GetOrders())
		{
			outputFile << "<order location=\"" << order.mLocation.GetName().toStdString() << "\" >" << std::endl;

			// Dump all packages.
			for (const auto package : order.mPackages)
				outputFile << "<package item=\"" << package.mItem.GetName().toStdString() << "\" quantity=\"" << package.mQuantity << "\" />" << std::endl;

			outputFile << "</order>" << std::endl;
		}

		outputFile << "</route>" << std::endl;
	}

	outputFile << "</application>" << std::endl;

	outputFile.close();
}
