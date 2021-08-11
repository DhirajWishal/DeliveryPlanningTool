#ifndef EDIT_LOCATIONS_H
#define EDIT_LOCATIONS_H

#include <QMainWindow>
#include <QtWidgets/qlistwidget.h>

#include "ApplicationState.h"

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class EditLocations; }
QT_END_NAMESPACE

/**
 * Edit locations class.
 * This object contains and handles the edit location window.
 * The edit location window is used to add or remove a location from the application.
 */
class EditLocations : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * Construct the edit location class using its default values.
	 *
	 * @param pApplicationState The application state pointer.
	 * @param parent The parent QWidget pointer. Default is nullptr.
	 */
	EditLocations(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent = nullptr);

	/**
	 * The close event override.
	 * This function is used to notify the main window to do certain tasks.
	 *
	 * @param event The close events.
	 */
	virtual void closeEvent(QCloseEvent* event) override;

private slots:
	/**
	 * Function to handle the "Add to list" event.
	 */
	void HandleAddToListEvent();

	/**
	 * Function to handle the "Remove item" event.
	 */
	void HandleRemoveItemEvent();

	/**
	 * Function to handle the widget item select event.
	 *
	 * @param pItem The item pointer.
	 */
	void HandleWidgetItemSelect(QListWidgetItem* pItem);

private:
	/**
	 * Clear all orders in the information panel.
	 */
	void ClearOrders();

	/**
	 * Update the order information panel.
	 */
	void UpdateOrders(QListWidgetItem* pItem);

	/**
	 * Get the location using its name.
	 *
	 * @param locationName The name of the location.
	 * @return The const location.
	 */
	const Location GetLocation(const std::string& locationName) const;

	/**
	 * Remove a location from the application state.
	 *
	 * @param name The name of the location.
	 */
	void RemoveLocation(const std::string& name);

private:
	std::unique_ptr<Ui::EditLocations> pEditLocations = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	int mSelectedItemRow = -1;
};

#endif
