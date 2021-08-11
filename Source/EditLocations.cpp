#include "EditLocations.h"
#include "../ui_EditLocations.h"

#include "MainWindow.h"
#include <QtWidgets/QMessageBox.h>

#include <algorithm>

EditLocations::EditLocations(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QMainWindow(parent),
	pEditLocations(std::make_unique<Ui::EditLocations>()),
	pApplicationState(pApplicationState)
{
	pEditLocations->setupUi(this);

	// Setup callbacks.
	QWidget::connect(pEditLocations->addToList, &QPushButton::pressed, this, &EditLocations::HandleAddToListEvent);
	QWidget::connect(pEditLocations->removeButton, &QPushButton::pressed, this, &EditLocations::HandleRemoveItemEvent);
	QObject::connect(pEditLocations->locationList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleWidgetItemSelect(QListWidgetItem*)));

	// Add the location names from the application state.
	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		pEditLocations->locationList->addItem(QString(location.GetName().c_str()));
}

void EditLocations::closeEvent(QCloseEvent* event)
{
	// Clear all the locations because we are updating the list.
	pApplicationState->ClearLocations();

	for (int row = 0; row < pEditLocations->locationList->count(); row++)
		pApplicationState->RegisterLocation(pEditLocations->locationList->item(row)->text().toStdString());

	// Notify the main window to update the location list.
	MainWindow* pMainWindow = static_cast<MainWindow*>(parent());
	pMainWindow->UpdateLocationList();
	pMainWindow->DeleteChild(this);
}

void EditLocations::HandleAddToListEvent()
{
	auto locationName = pEditLocations->locationName->toPlainText();

	// Return if the location name is empty.
	if (locationName.isEmpty())
	{
		QMessageBox issueWarning;
		issueWarning.setText("Location name should not be empty!");
		issueWarning.exec();

		return;
	}

	pEditLocations->locationList->addItem(locationName);

	// Reset the text edit field value.
	pEditLocations->locationName->clear();
}

void EditLocations::HandleRemoveItemEvent()
{
	// Skip if an item is not selected.
	if (mSelectedItemRow < 0)
		return;

	// Remove the location from the list.
	const auto pItem = pEditLocations->locationList->takeItem(mSelectedItemRow);
	RemoveLocation(pItem->text().toStdString());

	ClearOrders();
	mSelectedItemRow = -1;
}

void EditLocations::HandleWidgetItemSelect(QListWidgetItem* pItem)
{
	mSelectedItemRow = pEditLocations->locationList->indexFromItem(pItem).row();
	UpdateOrders(pItem);
}

void EditLocations::ClearOrders()
{
	pEditLocations->itemList->clear();
}

void EditLocations::UpdateOrders(QListWidgetItem* pItem)
{
	ClearOrders();

	// Get the location using the name.
	const Location location = GetLocation(pItem->text().toStdString());
	const auto itemList = location.GetItemList();

	// Insert items to the item list.
	for (const auto item : itemList)
		pEditLocations->itemList->addItem(item.GetName().c_str());
}

const Location EditLocations::GetLocation(const std::string& locationName) const
{
	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		if (location.GetName() == locationName)
			return location;

	return Location();
}

void EditLocations::RemoveLocation(const std::string& name)
{
	auto& locations = pApplicationState->GetLocations();
	for (auto itr = locations.begin(); itr != locations.end(); ++itr)
	{
		if (itr->GetName() == name)
		{
			locations.erase(itr);
			return;
		}
	}
}
