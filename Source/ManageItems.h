// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef MANAGE_ITEMS_H
#define MANAGE_ITEMS_H

#include <QWidget.h>
#include <QtWidgets/QListWidget.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ManageItems; }
QT_END_NAMESPACE

/**
 * Manage items object.
 * This object manages the items registered in the application.
 */
class ManageItems : public QWidget
{
	Q_OBJECT

public:
	/**
	 * Construct the object using the application state and parent.
	 *
	 * @param pApplicationState The application state pointer.
	 * @param parent The parent pointer. Default is nullptr.
	 */
	ManageItems(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent = nullptr);

	/**
	 * Refresh the tab information.
	 */
	void Refresh();

private slots:
	/**
	 * Function to handle add to list button click.
	 */
	void HandleAddToList();

	/**
	 * Function to handle remove button click.
	 */
	void HandleRemove();

	/**
	 * Handle the item select event.
	 *
	 * @param pItem The item pointer.
	 */
	void HandleItemSelect(QListWidgetItem* pItem);

private:
	/**
	 * Remove an item from the item list.
	 */
	void RemoveItem(const QString& name);

	/**
	 * Get an item from the item list.
	 *
	 * @param name The name of the item.
	 * @return The const item.
	 */
	const Item GetItem(const QString& name) const;

	/**
	 * Clear the item information fields.
	 */
	void ClearItemInformation();

private:
	std::unique_ptr<Ui::ManageItems> pManageItems = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	int mSelectedItem = -1;
};

#endif	// MANAGE_ITEMS_H
