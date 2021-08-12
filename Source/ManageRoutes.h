// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef MANAGE_ROUTES_H
#define MANAGE_ROUTES_H

#include <QMainWindow.h>
#include <QtWidgets/QListWidget.h>
#include <QtWidgets/QComboBox.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ManageRoutes; }
QT_END_NAMESPACE

/**
 * Manage routes object.
 * This object is used to manage routes, including creating new routes and editing them.
 */
class ManageRoutes : public QMainWindow
{
	Q_OBJECT

public:
	ManageRoutes(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent = nullptr);

	/**
	 * The close event override.
	 * This function is used to notify the main window to do certain tasks.
	 *
	 * @param event The close events.
	 */
	virtual void closeEvent(QCloseEvent* event) override;

	/**
	 * Delete a child.
	 * 
	 * @param pChild The child pointer to delete.
	 */
	void DeleteChild(QWidget* pChild);

	/**
	 * Submit a order after selecting its items and quantities.
	 * 
	 * @param order The order which is being submitted.
	 */
	void SubmitOrder(const Order& order, const QString& location);

private slots:
	/**
	 * Function to handle route selection.
	 *
	 * @param pItem The item pointer.
	 */
	void HandleRouteSelection(QListWidgetItem* pItem);

	/**
	 * Function to handle location item selection.
	 *
	 * @param pItem The item pointer.
	 */
	void HandleLocationSelection(QListWidgetItem* pItem);

	/**
	 * Function to handle selected location item selection.
	 *
	 * @param pItem The item pointer.
	 */
	void HandleSelectedLocationSelection(QListWidgetItem* pItem);

	/**
	 * Function to handle truck selection.
	 *
	 * @param index The index of the item
	 */
	void HandleTruckSelection(int index);

	/**
	 * Function to remove a selected location from the selected location list.
	 */
	void HandleRemoveFromSelected();

	/**
	 * Function to handle remove from routes.
	 */
	void HandleRemoveFromRoutes();

	/**
	 * Function to handle add to list button press.
	 */
	void HandleAddToList();

private:
	/**
	 * Update information about a route.
	 */
	void UpdateInformation();

	/**
	 * Clear information.
	 */
	void ClearInformation();

	/**
	 * Get a location using its name.
	 * 
	 * @param name The name of the location.
	 * @return The location.
	 */
	const Location GetLocation(const std::string& name);

private:
	std::unordered_map<QString, Order> mOrderMap = {};

	std::unique_ptr<Ui::ManageRoutes> pManageRoutes = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	int mSelectedRoute = -1;
	int mSelectedLocationToRemove = -1;
};

#endif
