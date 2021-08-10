#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qlistwidget.h>

#include "ApplicationState.h"

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	/**
	 * Update the location list.
	 */
	void UpdateLocationList();

	/**
	 * Delete a child object created by this.
	 * 
	 * @param pChildWindow The child window pointer.
	 */
	void DeleteChild(QMainWindow* pChildWindow) const;

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
	std::unique_ptr<Ui::MainWindow> pMainWindow = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;
};
#endif // MAINWINDOW_H
