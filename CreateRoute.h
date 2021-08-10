#ifndef CREATE_ROUTE_H
#define CREATE_ROUTE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CreateRoute; }
QT_END_NAMESPACE

class CreateRoute : public QMainWindow
{
	Q_OBJECT

public:
	CreateRoute(QWidget* parent = nullptr);
	~CreateRoute();

private:
	Ui::CreateRoute* ui;
};

#endif