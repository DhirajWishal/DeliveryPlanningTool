#include "CreateRoute.h"
#include "../ui_CreateRoute.h"

CreateRoute::CreateRoute(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QMainWindow(parent)
	, pCreateRoute(std::make_unique<Ui::CreateRoute>())
	, pApplicationState(pApplicationState)
{
	pCreateRoute->setupUi(this);
}
