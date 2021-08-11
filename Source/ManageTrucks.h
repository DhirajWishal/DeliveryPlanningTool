#ifndef MANAGE_TRUCKS_H
#define MANAGE_TRUCKS_H

#include <QMainWindow.h>
#include <QtWidgets/QListWidget.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ManageTrucks; }
QT_END_NAMESPACE

/**
 * Manage trucks object.
 * This object is used to manage all the registered trucks.
 */
class ManageTrucks : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * Construct the object using the application state and parent.
	 * 
	 * @param pApplicationState The application state pointer.
	 * @param parent The parent object pointer. Default is nullptr.
	 */
	ManageTrucks(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent = nullptr);

	/**
	 * The close event override.
	 * This function is used to notify the main window to do certain tasks.
	 *
	 * @param event The close events.
	 */
	virtual void closeEvent(QCloseEvent* event) override;

private slots:
	/**
	 * Function to handle add to list button press.
	 */
	void HandleAddToListEvent();

	/**
	 * Function to handle list widget item selection.
	 * 
	 * @param pItem The selected item pointer.
	 */
	void HandleItemSelection(QListWidgetItem* pItem);

	/**
	 * Function to handle remove button press.
	 */
	void HandleRemoveItem();

private:
	/**
	 * Check if a truck exist in the vector.
	 *
	 * @param compare The truck object to compare/ check with.
	 * @return Boolean value stating if it exists or not.
	 */
	const bool DoesTruckExist(const Truck& compare) const;

	/**
	 * Remove the truck from the vector.
	 * 
	 * @param id The truck ID.
	 */
	void RemoveTruck(int id);

	/**
	 * Find a truck from the list.
	 * 
	 * @param ID The truck ID.
	 * @return The truck.
	 */
	const Truck FindTruck(int ID) const;

private:
	std::unique_ptr<Ui::ManageTrucks> pManageTrucks = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	int mSelectedRow = -1;
};

#endif