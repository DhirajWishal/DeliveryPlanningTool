#include "MainWindow.h"
#include "../ui_MainWindow.h"

#include "CreateRoute.h"
#include "EditLocations.h"
#include "ManageTrucks.h"
#include "ManageItems.h"
#include "ManageRoutes.h"

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
	QObject::connect(pMainWindow->manageRoute, &QPushButton::pressed, this, &MainWindow::HandleManageRoutes);

	// Register all the locations stored in the .ui file to the application state.
	// This is because the locations are initially stored there.
	for(int row = 0; row < pMainWindow->locationList->count(); row++)
		pApplicationState->RegisterLocation(pMainWindow->locationList->item(row)->text().toStdString());

	// We do the same with skin care items. Here we assign a pre defined set of sizes.
	for(int row = 0; row < pMainWindow->itemList->count(); row++)
		pApplicationState->RegisterItem(Item(pMainWindow->itemList->item(row)->text().toStdString(), ItemSizes[row]));

	// Set the routes.
	const auto routes = pApplicationState->GetRoutes();
	for (const auto route : routes)
		pMainWindow->routeList->addItem(("Route number: " + std::to_string(route.GetNumber())).c_str());
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
	// Clear the list widget to set the updated truck list.
	pMainWindow->truckList->clear();

	const auto trucks = pApplicationState->GetTrucks();
	for (const auto truck : trucks)
		pMainWindow->truckList->addItem(("Truck: " + std::to_string(truck.GetID())).c_str());
}

void MainWindow::UpdateItemList()
{
	// Clear the list widget to set the updated item list.
	pMainWindow->itemList->clear();

	const auto items = pApplicationState->GetItems();
	for (const auto item : items)
		pMainWindow->itemList->addItem(item.GetName().c_str());
}

void MainWindow::UpdateRouteList()
{
	pMainWindow->routeList->clear();

	const auto routes = pApplicationState->GetRoutes();
	for (const auto route : routes)
		pMainWindow->routeList->addItem(("Route number: " + std::to_string(route.GetNumber())).c_str());
}

void MainWindow::DeleteChild(QMainWindow* pChildWindow)
{
	delete pChildWindow;
	//show();
}

void MainWindow::HandleLocationEdit()
{
	EditLocations* pEditLocations = new EditLocations(pApplicationState, this);
	pEditLocations->show();
	//hide();
}

void MainWindow::HandleListItemSelect(QListWidgetItem* pItem)
{
}

void MainWindow::HandleManageTrucks()
{
	ManageTrucks* pManageTrucks = new ManageTrucks(pApplicationState, this);
	pManageTrucks->show();
	//hide();
}

void MainWindow::HandleManageItems()
{
	ManageItems* pManageItems = new ManageItems(pApplicationState, this);
	pManageItems->show();
	//hide();
}

void MainWindow::HandleManageRoutes()
{
	ManageRoutes* pRoutes = new ManageRoutes(pApplicationState, this);
	pRoutes->show();
	//hide();
}

