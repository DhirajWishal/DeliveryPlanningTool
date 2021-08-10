#include "CreateRoute.h"
#include "ui_CreateRoute.h"

CreateRoute::CreateRoute(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::CreateRoute)
{
	ui->setupUi(this);
}

CreateRoute::~CreateRoute()
{
	delete ui;
}