#ifndef CREATE_ROUTE_H
#define CREATE_ROUTE_H

#include <QMainWindow>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class CreateRoute; }
QT_END_NAMESPACE

/**
 * Create route object.
 * This object is used to plan and create a new route for a truck.
 * First the truck must be selected from the main window.
 */
class CreateRoute : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * Default constructor.
	 * 
	 * @param parent The parent object pointer. Default is nullptr.
	 */
	CreateRoute(QWidget* parent = nullptr);

private:
	std::unique_ptr<Ui::CreateRoute> pCreateRoute = nullptr;
};

#endif