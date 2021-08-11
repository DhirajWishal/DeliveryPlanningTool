#include "ViewRoutes.h"
#include "../ui_ViewRoutes.h"

#include "ManageRoutes.h"

ViewRoutes::ViewRoutes(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QWidget(parent)
	, pApplicationState(pApplicationState)
	, pViewRoutes(std::make_unique<Ui::ViewRoutes>())
{
	pViewRoutes->setupUi(this);

	// Setup callbacks.
	QObject::connect(pViewRoutes->manage, &QPushButton::pressed, this, &ViewRoutes::HandleManage);

	// Setup routes.
	const auto routes = pApplicationState->GetRoutes();
	for (const auto route : routes)
		pViewRoutes->routeList->addItem(("Route number: " + std::to_string(route.GetNumber()) + " ").c_str() + route.GetFormattedDateString());
}

void ViewRoutes::HandleManage()
{
	ManageRoutes* pRoutes = new ManageRoutes(pApplicationState, this);
	pRoutes->show();
}

void ViewRoutes::DeleteChild(QMainWindow* pChildWindow)
{
	delete pChildWindow;
}

void ViewRoutes::Refresh()
{
	pViewRoutes->routeList->clear();

	const auto routes = pApplicationState->GetRoutes();
	for (const auto route : routes)
		pViewRoutes->routeList->addItem(("Route number: " + std::to_string(route.GetNumber()) + " ").c_str() + route.GetFormattedDateString());
}
