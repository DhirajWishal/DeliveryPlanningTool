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
	QWidget::connect(pEditLocations->pushButton, &QPushButton::pressed, this, &EditLocations::HandleAddToListEvent);
	QWidget::connect(pEditLocations->removeButton, &QPushButton::pressed, this, &EditLocations::HandleRemoveItemEvent);
	QObject::connect(pEditLocations->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleWidgetItemSelect(QListWidgetItem*)));

	// Add the location names from the application state.
	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		pEditLocations->listWidget->addItem(QString(location.GetName().c_str()));
}

void EditLocations::closeEvent(QCloseEvent* event)
{
	// Clear all the locations because we are updating the list.
	pApplicationState->ClearLocations();

	for (int row = 0; row < pEditLocations->listWidget->count(); row++)
		pApplicationState->RegisterLocation(pEditLocations->listWidget->item(row)->text().toStdString());

	// Notify the main window to update the location list.
	MainWindow* pMainWindow = static_cast<MainWindow*>(parent());
	pMainWindow->UpdateLocationList();
	pMainWindow->DeleteChild(this);
}

void EditLocations::HandleAddToListEvent()
{
	auto locationName = pEditLocations->textEdit->toPlainText();

	// Return if the location name is empty.
	if (locationName.isEmpty())
	{
		QMessageBox issueWarning;
		issueWarning.setText("Location name should not be empty!");
		issueWarning.exec();

		return;
	}

	pEditLocations->listWidget->addItem(locationName);

	// Reset the text edit field value.
	pEditLocations->textEdit->clear();
}

void EditLocations::HandleRemoveItemEvent()
{
	// Skip if an item is not selected.
	if (mSelectedItemRow < 0)
		return;

	pEditLocations->listWidget->takeItem(mSelectedItemRow);
	mSelectedItemRow = -1;
}

void EditLocations::HandleWidgetItemSelect(QListWidgetItem* pItem)
{
	mSelectedItemRow = pEditLocations->listWidget->indexFromItem(pItem).row();
}
