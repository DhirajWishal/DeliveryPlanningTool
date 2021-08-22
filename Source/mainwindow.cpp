// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "MainWindow.h"
#include "../ui_MainWindow.h"

#include "EditLocations.h"
#include "ManageTrucks.h"
#include "ManageItems.h"
#include "ViewRoutes.h"
#include "Checkout.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, pMainWindow(new Ui::MainWindow)
	, pApplicationState(std::make_shared<ApplicationState>())
	, pTabWidget(std::unique_ptr<QTabWidget>())
{
	pMainWindow->setupUi(this);

	// Setup callbacks.
	QObject::connect(pMainWindow->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(HandleTabChange(int)));

	// Setup the tabs.
	pMainWindow->tabWidget->clear();
	pMainWindow->tabWidget->addTab(new EditLocations(pApplicationState, this), "Locations");
	pMainWindow->tabWidget->addTab(new ManageTrucks(pApplicationState, this), "Trucks");
	pMainWindow->tabWidget->addTab(new ManageItems(pApplicationState, this), "Items");
	pMainWindow->tabWidget->addTab(new ViewRoutes(pApplicationState, this), "Routes");
	pMainWindow->tabWidget->addTab(new Checkout(pApplicationState, this), "Checkout");
}

MainWindow::~MainWindow()
{
	delete pMainWindow;
}

void MainWindow::DeleteChild(QMainWindow* pChildWindow)
{
	delete pChildWindow;
}

void MainWindow::DeleteChild(QWidget* pChildWindow)
{
	delete pChildWindow;
}

void MainWindow::HandleTabChange(int index)
{
	if (index == 0)
		static_cast<EditLocations*>(pMainWindow->tabWidget->currentWidget())->Refresh();

	else if (index == 1)
		static_cast<ManageTrucks*>(pMainWindow->tabWidget->currentWidget())->Refresh();

	else if (index == 2)
		static_cast<ManageItems*>(pMainWindow->tabWidget->currentWidget())->Refresh();

	else if (index == 3)
		static_cast<ViewRoutes*>(pMainWindow->tabWidget->currentWidget())->Refresh();

	else if (index == 4)
		static_cast<Checkout*>(pMainWindow->tabWidget->currentWidget())->Refresh();
}

