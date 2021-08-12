// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef EDIT_LOCATIONS_H
#define EDIT_LOCATIONS_H

#include <QWidget>
#include <QtWidgets/QListWidget.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EditLocations; }
QT_END_NAMESPACE

/**
 * Edit locations class.
 * This object contains and handles the edit location window.
 * The edit location window is used to add or remove a location from the application.
 */
class EditLocations : public QWidget
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
	 * Refresh the tab information.
	 */
	void Refresh();

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
