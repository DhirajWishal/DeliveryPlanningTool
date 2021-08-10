#ifndef EDIT_LOCATIONS_H
#define EDIT_LOCATIONS_H

#include <QMainWindow>
#include <QtWidgets/qlistwidget.h>

#include "ApplicationState.h"

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class EditLocations; }
QT_END_NAMESPACE

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
	~EditLocations();

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
	std::unique_ptr<Ui::EditLocations> pEditLocations = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	int mSelectedItemRow = 0;
};

#endif
