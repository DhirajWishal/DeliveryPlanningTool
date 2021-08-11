#ifndef ITEM_SELECTION_H
#define ITEM_SELECTION_H

#include <QMainWindow.h>
#include <QtWidgets/QListWidget.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ItemSelection; }
QT_END_NAMESPACE

/**
 * Item selection object.
 * This object gathers user information to select the items required for a location/ shop.
 */
class ItemSelection : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * Construct the object using its location, application state and parent.
	 * 
	 * @param location The location to which the items are added.
	 * @param pApplicationState The application state pointer.
	 * @param parent The parent object which created this. Default is nullptr.
	 */
	ItemSelection(const std::string& location, const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent = nullptr);

	/**
	 * The close event override.
	 * This function is used to notify the main window to do certain tasks.
	 *
	 * @param event The close events.
	 */
	virtual void closeEvent(QCloseEvent* event) override;

private slots:
	/**
	 * Function to handle the OK button press.
	 */
	void HandleOkButton();

	/**
	 * Function to handle the Cancel button press.
	 */
	void HandleCancelButton();

	/**
	 * Function to handle the Add button press.
	 */
	void HandleAddButton();

	/**
	 * Function to handle the Remove button press.
	 */
	void HandleRemoveButton();

	/**
	 * Function to handle the Item selection.
	 * 
	 * @param pItem The item pointer of the selected item.
	 */
	void HandleSelectItem(QListWidgetItem* pItem);

	/**
	 * Function to handle the remove item selection.
	 *
	 * @param pItem The item pointer of the selected item.
	 */
	void HandleRemoveItem(QListWidgetItem* pItem);

private:
	std::string mLocation = {};
	Order mCurrentOrder = {};

	std::unordered_map<QString, Package> mPackages;

	std::unique_ptr<Ui::ItemSelection> pItemSelection = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	int mTotalLoad = 0;
	int mSelectedItemIndex = -1;
	int mRemoveItemIndex = -1;
};

#endif
