#include "ManageItems.h"
#include "../ui_ManageItems.h"

#include "MainWindow.h"

ManageItems::ManageItems(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QMainWindow(parent)
	, pManageItems(std::make_unique<Ui::ManageItems>())
	, pApplicationState(pApplicationState)
{
	pManageItems->setupUi(this);
}

void ManageItems::closeEvent(QCloseEvent* event)
{
	MainWindow* pMainWindow = static_cast<MainWindow*>(parent());
	//pMainWindow->UpdateTruckList();
	pMainWindow->DeleteChild(this);
}
