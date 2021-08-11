#include "EditLocations.h"
#include "../ui_EditLocations.h"

#include "MainWindow.h"
#include <QtWidgets/QMessageBox.h>

#include <algorithm>
#include <stdexcept>

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
	// Notify the main window to update the location list.
	MainWindow* pMainWindow = static_cast<MainWindow*>(parent());
	pMainWindow->UpdateLocationList();
	pMainWindow->DeleteChild(this);
}

void EditLocations::HandleAddToListEvent()
{
	try
	{
		const auto locationName = pEditLocations->locationName->toPlainText();

		// Check if the location name is empty.
		if (locationName.isEmpty())
			throw std::runtime_error("The location name should not be empty!");

		// Add the location to the list.
		pEditLocations->locationList->addItem(locationName);
		pApplicationState->RegisterLocation(Location(locationName.toStdString()));
	}
	catch (std::exception e)
	{
		QMessageBox issueWarning;
		issueWarning.setText(e.what());
		issueWarning.exec();
	}

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

	mSelectedItemRow--;
}

void EditLocations::HandleWidgetItemSelect(QListWidgetItem* pItem)
{
	mSelectedItemRow = pEditLocations->locationList->indexFromItem(pItem).row();
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
