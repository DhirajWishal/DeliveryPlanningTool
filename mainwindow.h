#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qlistwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();


private slots:
	/**
	 * Handle the location button press.
	 */
	void HandleLocationEdit();

	/**
	 * Handle the list item select event.
	 */
	void HandleListItemSelect(QListWidgetItem* pItem);

private:
	Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
