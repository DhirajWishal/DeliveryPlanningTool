#include "MainWindow.h"
#include "../ui_MainWindow.h"

#include "CreateRoute.h"
#include "EditLocations.h"
#include "ManageTrucks.h"
#include "ManageItems.h"

constexpr int ItemSizes[] = {
	1, 1, 2,
	1, 1, 3
};

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, pMainWindow(new Ui::MainWindow)
	, pApplicationState(std::make_shared<ApplicationState>())
{
	pMainWindow->setupUi(this);

	// Add the button press handler to the button.
	QObject::connect(pMainWindow->manageLocationsButton, &QPushButton::pressed, this, &MainWindow::HandleLocationEdit);

	// Set the skin care item list click callback.
	QObject::connect(pMainWindow->itemList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleListItemSelect(QListWidgetItem*)));

	QObject::connect(pMainWindow->manageTrucksButton, &QPushButton::pressed, this, &MainWindow::HandleManageTrucks);
	QObject::connect(pMainWindow->manageItemsButton, &QPushButton::pressed, this, &MainWindow::HandleManageItems);

	// Register all the locations stored in the .ui file to the application state.
	// This is because the locations are initially stored there.
	for(int row = 0; row < pMainWindow->locationList->count(); row++)
		pApplicationState->RegisterLocation(pMainWindow->locationList->item(row)->text().toStdString());

	// We do the same with skin care items. Here we assign a pre defined set of sizes.
	for(int row = 0; row < pMainWindow->itemList->count(); row++)
		pApplicationState->RegisterItem(Item(pMainWindow->itemList->item(row)->text().toStdString(), ItemSizes[row]));
}

MainWindow::~MainWindow()
{
	delete pMainWindow;
}

void MainWindow::UpdateLocationList()
{
	// Clear the list widget to set the updated location list.
	pMainWindow->locationList->clear();

	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		pMainWindow->locationList->addItem(QString(location.GetName().c_str()));
}

void MainWindow::UpdateTruckList()
{
	// Clear the list widget to set the updated location list.
	pMainWindow->truckList->clear();

	const auto locations = pApplicationState->GetTrucks();
	for (const auto location : locations)
		pMainWindow->truckList->addItem(("Truck: " + std::to_string(location.GetID())).c_str());
}

void MainWindow::DeleteChild(QMainWindow* pChildWindow) const
{
	delete pChildWindow;
}

void MainWindow::HandleLocationEdit()
{
	EditLocations* pEditLocations = new EditLocations(pApplicationState, this);
	pEditLocations->show();
}

void MainWindow::HandleListItemSelect(QListWidgetItem* pItem)
{
}

void MainWindow::HandleManageTrucks()
{
	ManageTrucks* pManageTrucks = new ManageTrucks(pApplicationState, this);
	pManageTrucks->show();
}

void MainWindow::HandleManageItems()
{
	ManageItems* pManageItems = new ManageItems(pApplicationState, this);
	pManageItems->show();
}

