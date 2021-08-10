#include "mainwindow.h"
#include "../ui_mainwindow.h"

#include "CreateRoute.h"
#include "EditLocations.h"

constexpr int ItemSizes[] = {
	1, 1, 2,
	1, 1, 3,
	4, 2, 6
};

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, pMainWindow(std::make_unique<Ui::MainWindow>())
	, pApplicationState(std::make_shared<ApplicationState>())
{
	pMainWindow->setupUi(this);

	// Add the button press handler to the button.
	QObject::connect(pMainWindow->pushButton, &QPushButton::pressed, this, &MainWindow::HandleLocationEdit);

	// Set the skin care item list click callback.
	QObject::connect(pMainWindow->listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleListItemSelect(QListWidgetItem*)));

	// Register all the locations stored in the .ui file to the application state.
	// This is because the locations are initially stored there.
	int rowCounter = 0;
	while (pMainWindow->listWidget->item(rowCounter) != nullptr)
		pApplicationState->RegisterLocation(pMainWindow->listWidget->item(rowCounter++)->text().toStdString());

	// We do the same with items. Here we assign a pre defined set of sizes.
	rowCounter = 0;
	while (pMainWindow->listWidget_2->item(rowCounter) != nullptr)
		pApplicationState->RegisterItem(Item(pMainWindow->listWidget_2->item(rowCounter++)->text().toStdString(), ItemSizes[rowCounter]));
}

MainWindow::~MainWindow()
{
}

void MainWindow::UpdateLocationList()
{
	// Clear the list widget to set the updated location list.
	pMainWindow->listWidget->clear();

	const auto locations = pApplicationState->GetLocations();
	for (const auto location : locations)
		pMainWindow->listWidget->addItem(QString(location.GetName().c_str()));
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

