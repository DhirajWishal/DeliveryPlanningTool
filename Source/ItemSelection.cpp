// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "ItemSelection.h"
#include "ui_ItemSelection.h"

#include "ManageRoutes.h"

#include <QtWidgets/QMessageBox.h>
#include <stdexcept>

ItemSelection::ItemSelection(const Location& location, const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QMainWindow(parent)
	, mLocation(location)
	, pApplicationState(pApplicationState)
	, pItemSelection(std::make_unique<Ui::ItemSelection>())
{
	pItemSelection->setupUi(this);
	mCurrentOrder.mLocation = mLocation;

	// Set the location title.
	pItemSelection->locationTitle->setText(mLocation.GetName());

	// Setup callbacks.
	QObject::connect(pItemSelection->okButton, &QPushButton::pressed, this, &ItemSelection::HandleOkButton);
	QObject::connect(pItemSelection->cancelButton, &QPushButton::pressed, this, &ItemSelection::HandleCancelButton);
	QObject::connect(pItemSelection->addToList, &QPushButton::pressed, this, &ItemSelection::HandleAddButton);
	QObject::connect(pItemSelection->remove, &QPushButton::pressed, this, &ItemSelection::HandleRemoveButton);
	QObject::connect(pItemSelection->itemList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleSelectItem(QListWidgetItem*)));
	QObject::connect(pItemSelection->selectedItems, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleRemoveItem(QListWidgetItem*)));

	// Add items to the item list.
	const auto items = pApplicationState->GetItems();
	for (const auto item : items)
		pItemSelection->itemList->addItem(item.GetName());
}

void ItemSelection::closeEvent(QCloseEvent*)
{
	static_cast<ManageRoutes*>(parent())->DeleteChild(this);
}

void ItemSelection::HandleOkButton()
{
	// Resolve packages.
	for (int row = 0; row < pItemSelection->selectedItems->count(); row++)
		mCurrentOrder.mPackages.push_back(mPackages[pItemSelection->selectedItems->item(row)->text()]);

	// Sort the packages in the order.
	mCurrentOrder.Sort();

	// Submit the order and close the window.
	static_cast<ManageRoutes*>(parent())->SubmitOrder(mCurrentOrder, pItemSelection->locationTitle->text());
	close();
}

void ItemSelection::HandleCancelButton()
{
	close();
}

void ItemSelection::HandleAddButton()
{
	// Skip if the user has not selected any item.
	if (mSelectedItemIndex < 0)
		return;

	try
	{
		// Get the quantity.
		bool isConversionSuccessful = false;
		const int quantity = pItemSelection->quantity->toPlainText().toInt(&isConversionSuccessful);

		// Validate the quantity.
		if (isConversionSuccessful == false && quantity <= 0)
			throw std::runtime_error("The quantity should only be an integer and greater than 0!");

		const auto pItem = pItemSelection->itemList->takeItem(mSelectedItemIndex);
		const auto item = pApplicationState->FindItem(pItem->text());

		// Add the package to the map.
		mPackages[pItem->text()] = Package(item, quantity);
		mTotalLoad += item.GetSize() * quantity;

		// Add the item to the selected items list.
		pItemSelection->selectedItems->addItem(pItem);
		mSelectedItemIndex--;

		// Reset the info.
		pItemSelection->quantity->clear();
		pItemSelection->itemName->clear();
		pItemSelection->ItemSize->clear();

		pItemSelection->totalSize->setText(("Total order size: " + std::to_string(mTotalLoad)).c_str());
	}
	catch (std::exception e)
	{
		QMessageBox issueWarning;
		issueWarning.setText(e.what());
		issueWarning.exec();
	}
}

void ItemSelection::HandleRemoveButton()
{
	// Skip if the user has not selected any item to remove.
	if (mRemoveItemIndex < 0)
		return;

	const auto pItem = pItemSelection->selectedItems->takeItem(mRemoveItemIndex);
	const auto item = pApplicationState->FindItem(pItem->text());

	// Reduce the size and remove the package.
	mTotalLoad -= item.GetSize() * mPackages[pItem->text()].mQuantity;
	mPackages.erase(pItem->text());

	pItemSelection->itemList->addItem(pItem);
	mRemoveItemIndex--;

	pItemSelection->totalSize->setText(("Total order size: " + std::to_string(mTotalLoad)).c_str());
}

void ItemSelection::HandleSelectItem(QListWidgetItem* pItem)
{
	mSelectedItemIndex = pItemSelection->itemList->indexFromItem(pItem).row();

	// Display the item information.
	pItemSelection->itemName->setText(pItem->text());
	pItemSelection->ItemSize->setText(("Item's unit size: " + std::to_string(pApplicationState->FindItem(pItem->text()).GetSize())).c_str());
}

void ItemSelection::HandleRemoveItem(QListWidgetItem* pItem)
{
	mRemoveItemIndex = pItemSelection->selectedItems->indexFromItem(pItem).row();
}
