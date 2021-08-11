#include "CreateRoute.h"
#include "../ui_CreateRoute.h"

CreateRoute::CreateRoute(QWidget* parent)
	: QMainWindow(parent)
	, pCreateRoute(std::make_unique<Ui::CreateRoute>())
{
	pCreateRoute->setupUi(this);
}
