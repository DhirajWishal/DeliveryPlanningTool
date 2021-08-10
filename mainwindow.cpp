#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "CreateRoute.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Add the button press handler to the button.
	QObject::connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::HandleLocationEdit);

	// Set the skin care item list click callback.
	QObject::connect(ui->listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleListItemSelect(QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::HandleLocationEdit()
{
	CreateRoute* pCreateRoute = new CreateRoute();
	pCreateRoute->show();
}

void MainWindow::HandleListItemSelect(QListWidgetItem* pItem)
{
}

