#include "EditLocations.h"
#include "../ui_EditLocations.h"

#include "mainwindow.h"

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

EditLocations::~EditLocations()
{
}

void EditLocations::closeEvent(QCloseEvent* event)
{
	// Clear all the locations because we are updating the list.
	pApplicationState->ClearLocations();

	int rowCounter = 0;
	while (pEditLocations->listWidget->item(rowCounter) != nullptr)
		pApplicationState->RegisterLocation(pEditLocations->listWidget->item(rowCounter++)->text().toStdString());

	// Notify the main window to update the location list.
	MainWindow* pMainWindow = static_cast<MainWindow*>(parent());
	pMainWindow->UpdateLocationList();
	pMainWindow->DeleteChild(this);
}

void EditLocations::HandleAddToListEvent()
{
	auto locationName = pEditLocations->textEdit->toPlainText();

	// Do not add the location to the list if the name is empty.
	if (!locationName.isEmpty())
		pEditLocations->listWidget->addItem(locationName);

	// Reset the text edit field value.
	pEditLocations->textEdit->setText("");
}

void EditLocations::HandleRemoveItemEvent()
{
	pEditLocations->listWidget->takeItem(mSelectedItemRow);
}

void EditLocations::HandleWidgetItemSelect(QListWidgetItem* pItem)
{
	mSelectedItemRow = pEditLocations->listWidget->indexFromItem(pItem).row();
}
