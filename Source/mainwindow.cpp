// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "MainWindow.h"
#include "../ui_MainWindow.h"

#include "EditLocations.h"
#include "ManageTrucks.h"
#include "ManageItems.h"
#include "ViewRoutes.h"

constexpr int ItemSizes[] = {
	1, 1, 2,
	1, 1, 3
};

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
	pMainWindow->tabWidget->addTab(new EditLocations(pApplicationState, this), tr("Locations"));
	pMainWindow->tabWidget->addTab(new ManageTrucks(pApplicationState, this), tr("Trucks"));
	pMainWindow->tabWidget->addTab(new ManageItems(pApplicationState, this), tr("Items"));
	pMainWindow->tabWidget->addTab(new ViewRoutes(pApplicationState, this), tr("Routes"));
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
	//pMainWindow->tabWidget->currentIndex();
	if (index == 0)
		static_cast<EditLocations*>(pMainWindow->tabWidget->currentWidget())->Refresh();

	else if (index == 1)
		static_cast<ManageTrucks*>(pMainWindow->tabWidget->currentWidget())->Refresh();

	else if (index == 2)
		static_cast<ManageItems*>(pMainWindow->tabWidget->currentWidget())->Refresh();

	else if (index == 3)
		static_cast<ViewRoutes*>(pMainWindow->tabWidget->currentWidget())->Refresh();
}

