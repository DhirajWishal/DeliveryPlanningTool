// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "ManageTrucks.h"
#include "../ui_ManageTrucks.h"

#include "MainWindow.h"

#include <QtWidgets/QMessageBox.h>
#include <stdexcept>

ManageTrucks::ManageTrucks(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QWidget(parent)
	, pManageTrucks(std::make_unique<Ui::ManageTrucks>())
	, pApplicationState(pApplicationState)
{
	pManageTrucks->setupUi(this);

	// Setup callbacks.
	QObject::connect(pManageTrucks->addToList, &QPushButton::pressed, this, &ManageTrucks::HandleAddToListEvent);
	QObject::connect(pManageTrucks->remove, &QPushButton::pressed, this, &ManageTrucks::HandleRemoveItem);
	QObject::connect(pManageTrucks->truckList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleItemSelection(QListWidgetItem*)));

	// List all the trucks from the application state.
	const auto trucks = pApplicationState->GetTrucks();
	for (const auto truck : trucks)
		pManageTrucks->truckList->addItem(QString("Truck: ") + QString::number(truck.GetID()));
}

void ManageTrucks::Refresh()
{
	pManageTrucks->truckList->clear();

	const auto trucks = pApplicationState->GetTrucks();
	for (const auto truck : trucks)
		pManageTrucks->truckList->addItem(QString("Truck: ") + QString::number(truck.GetID()));

	pManageTrucks->labelTruckID->clear();
	pManageTrucks->labelTruckCapacity->clear();
}

void ManageTrucks::HandleAddToListEvent()
{
	// Register the truck.
	try
	{
		bool isValidID = false;
		const auto trucks = pApplicationState->GetTrucks();
		const Truck newTruck = Truck(pManageTrucks->truckID->toPlainText().toInt(&isValidID), pManageTrucks->truckCapacity->toPlainText().toInt());

		// If the id is not valid (aka: contains text), throw an exception.
		if (!isValidID)
			throw std::runtime_error("Truck ID should be an integer!");

		// Check if the truck exists.
		if (!DoesTruckExist(newTruck))
			pApplicationState->RegisterTruck(newTruck);
		else
			throw std::runtime_error("A truck with the same truck ID exists!");

		// Update the truck list.
		pManageTrucks->truckList->addItem(QString("Truck: ") + std::to_string(newTruck.GetID()).c_str());
	}
	catch (std::exception e)
	{
		QMessageBox issueWarning;
		issueWarning.setText(e.what());
		issueWarning.exec();
	}

	// Clear the entered values.
	pManageTrucks->truckID->clear();
	pManageTrucks->truckCapacity->clear();
}

void ManageTrucks::HandleItemSelection(QListWidgetItem* pItem)
{
	mSelectedRow = pManageTrucks->truckList->indexFromItem(pItem).row();

	// Set the truck information.
	pManageTrucks->labelTruckID->setText(pItem->text());
	pManageTrucks->labelTruckCapacity->setText(("Capacity: " + std::to_string(pApplicationState->FindTruck(pItem->text().mid(7).toInt()).GetID())).c_str());
}

void ManageTrucks::HandleRemoveItem()
{
	if (mSelectedRow < 0)
		return;

	const auto pItem = pManageTrucks->truckList->takeItem(mSelectedRow);
	RemoveTruck(pItem->text().mid(6).toInt());

	mSelectedRow--;

	// Reset item information.
	pManageTrucks->labelTruckID->clear();
	pManageTrucks->labelTruckCapacity->clear();
}

const bool ManageTrucks::DoesTruckExist(const Truck& compare) const
{
	const auto trucks = pApplicationState->GetTrucks();
	for (const Truck truck : trucks)
		if (truck.GetID() == compare.GetID())
			return true;

	return false;
}

void ManageTrucks::RemoveTruck(int id)
{
	auto& trucks = pApplicationState->GetTrucks();
	for (auto itr = trucks.begin(); itr != trucks.end(); ++itr)
	{
		if (itr->GetID() == id)
		{
			trucks.erase(itr);
			break;
		}
	}

	// Remove the truck from the routes.
	auto& routes = pApplicationState->GetRoutes();
	for (auto itr = routes.begin(); itr != routes.end(); ++itr)
	{
		if (itr->GetTruck().GetID() == id)
		{
			routes.erase(itr);

			// Return if the erase would empty the array.
			if (routes.empty())
				return;
		}
	}
}

const Truck ManageTrucks::FindTruck(int ID) const
{
	const auto trucks = pApplicationState->GetTrucks();
	for (const Truck truck : trucks)
		if (truck.GetID() == ID)
			return truck;

	return Truck();
}
