#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qlistwidget.h>

#include "ApplicationState.h"

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * Main window object.
 * This object holds and handles the main window.
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * Default constructor.
	 * Construct the object using its parent.
	 * 
	 * @param parent The parent object pointer. Default is nullptr.
	 */
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	/**
	 * Update the location list.
	 */
	void UpdateLocationList();

	/**
	 * Update the truck list.
	 */
	void UpdateTruckList();

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

	/**
	 * Function to handle manage trucks button press.
	 */
	void HandleManageTrucks();

	/**
	 * Function to handle manage items button press.
	 */
	void HandleManageItems();

private:
	Ui::MainWindow* pMainWindow = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;
};
#endif // MAINWINDOW_H
