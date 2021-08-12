// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "EditLocations.h"
#include "../ui_EditLocations.h"

#include "MainWindow.h"

#include <QtWidgets/QMessageBox.h>
#include <stdexcept>

EditLocations::EditLocations(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QWidget(parent),
	pEditLocations(std::make_unique<Ui::EditLocations>()),
	pApplicationState(pApplicationState)
{
	pEditLocations->setupUi(this);

	// Setup callbacks.
	QObject::connect(pEditLocations->addToList, &QPushButton::pressed, this, &EditLocations::HandleAddToListEvent);
	QObject::connect(pEditLocations->removeButton, &QPushButton::pressed, this, &EditLocations::HandleRemoveItemEvent);
	QObject::connect(pEditLocations->locationList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleWidgetItemSelect(QListWidgetItem*)));

	// Add the location names from the application state.
	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		pEditLocations->locationList->addItem(QString(location.GetName()));
}

void EditLocations::Refresh()
{
	// Skip if the edit locations pointer is not set.
	if (pEditLocations)
		return;

	pEditLocations->locationList->clear();

	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		pEditLocations->locationList->addItem(QString(location.GetName()));
}

void EditLocations::HandleAddToListEvent()
{
	try
	{
		const auto locationName = pEditLocations->locationName->toPlainText();
		const auto locationAddress = pEditLocations->address->toPlainText();

		// Check if the location name is empty.
		if (locationName.isEmpty() || locationAddress.isEmpty())
			throw std::runtime_error("The location name and address should not be empty!");

		// Create the new location.
		Location newLocation(locationName, locationAddress);

		// Check if the location is registered.
		if (pApplicationState->IsLocationPresent(newLocation))
			throw std::runtime_error("The location is registered in the application!");

		// Add the location to the list.
		pEditLocations->locationList->addItem(locationName);
		pApplicationState->RegisterLocation(Location(locationName, locationAddress));
	}
	catch (std::exception e)
	{
		QMessageBox issueWarning;
		issueWarning.setText(e.what());
		issueWarning.exec();
	}

	// Reset the text edit field value.
	pEditLocations->locationName->clear();
	pEditLocations->address->clear();
}

void EditLocations::HandleRemoveItemEvent()
{
	// Skip if an item is not selected.
	if (mSelectedItemRow < 0)
		return;

	// Remove the location from the list.
	const auto pItem = pEditLocations->locationList->takeItem(mSelectedItemRow);
	RemoveLocation(pItem->text());

	mSelectedItemRow--;
}

void EditLocations::HandleWidgetItemSelect(QListWidgetItem* pItem)
{
	mSelectedItemRow = pEditLocations->locationList->indexFromItem(pItem).row();

	// Get the location to display its data.
	const auto location = GetLocation(pItem->text());
	pEditLocations->labelAddress->setText(location.GetAddress());
}

const Location EditLocations::GetLocation(const QString& locationName) const
{
	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		if (location.GetName() == locationName)
			return location;

	return Location();
}

void EditLocations::RemoveLocation(const QString& name)
{
	auto& locations = pApplicationState->GetLocations();
	for (auto itr = locations.begin(); itr != locations.end(); ++itr)
	{
		if (itr->GetName() == name)
		{
			locations.erase(itr);
			break;
		}
	}

	// Remove the location from the routes.
	for (auto& route : pApplicationState->GetRoutes())
	{
		auto& orders = route.GetOrders();
		for (auto itr = orders.begin(); itr != orders.end(); ++itr)
		{
			if (itr->mLocation.GetName() == name)
			{
				orders.erase(itr);
				break;
			}
		}
	}

	pEditLocations->labelAddress->clear();
}
