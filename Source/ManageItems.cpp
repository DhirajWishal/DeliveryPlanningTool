#include "ManageItems.h"
#include "../ui_ManageItems.h"

#include "MainWindow.h"

#include <QtWidgets/QMessageBox.h>
#include <stdexcept>

ManageItems::ManageItems(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent)
	: QWidget(parent)
	, pManageItems(std::make_unique<Ui::ManageItems>())
	, pApplicationState(pApplicationState)
{
	pManageItems->setupUi(this);

	// Setup callbacks.
	QObject::connect(pManageItems->itemList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(HandleItemSelect(QListWidgetItem*)));
	QObject::connect(pManageItems->addToList, &QPushButton::pressed, this, &ManageItems::HandleAddToList);
	QObject::connect(pManageItems->removeButton, &QPushButton::pressed, this, &ManageItems::HandleRemove);

	// Add items to the item list.
	const auto items = pApplicationState->GetItems();
	for (const auto item : items)
		pManageItems->itemList->addItem(item.GetName().c_str());
}

void ManageItems::closeEvent(QCloseEvent*)
{
	MainWindow* pMainWindow = static_cast<MainWindow*>(parent());
	pMainWindow->DeleteChild(this);
}

void ManageItems::Refresh()
{
	pManageItems->itemList->clear();

	const auto items = pApplicationState->GetItems();
	for (const auto item : items)
		pManageItems->itemList->addItem(item.GetName().c_str());
}

void ManageItems::HandleAddToList()
{
	// Get the user inputs from the text fields.
	const auto itemName = pManageItems->itemName->toPlainText();
	const auto itemSize = pManageItems->itemSize->toPlainText();

	try
	{
		// Check if the item name and size is empty.
		if (itemName.isEmpty() || itemSize.isEmpty())
			throw std::runtime_error("Item name and size should not be empty!");

		// Add the item to the item list.
		pApplicationState->RegisterItem(Item(itemName.toStdString(), itemSize.toInt()));
		pManageItems->itemList->addItem(itemName);
	}
	catch (std::exception e)
	{
		QMessageBox issueWarning;
		issueWarning.setText(e.what());
		issueWarning.exec();
	}

	pManageItems->itemName->clear();
	pManageItems->itemSize->clear();
}

void ManageItems::HandleRemove()
{
	// Skip if no item is selected.
	if (mSelectedItem < 0)
		return;

	// Remove the item from the item list(s).
	const auto pItem = pManageItems->itemList->takeItem(mSelectedItem);
	RemoveItem(pItem->text().toStdString());

	mSelectedItem--;
}

void ManageItems::HandleItemSelect(QListWidgetItem* pItem)
{
	mSelectedItem = pManageItems->itemList->indexFromItem(pItem).row();

	pManageItems->labelItemName->setText("Item name: " + pItem->text());
	pManageItems->labelItemSize->setText(("Size: " + std::to_string(GetItem(pItem->text().toStdString()).GetSize())).c_str());
}

void ManageItems::RemoveItem(const std::string& name)
{
	auto& items = pApplicationState->GetItems();
	for (auto itr = items.begin(); itr != items.end(); ++itr)
	{
		if (itr->GetName() == name)
		{
			items.erase(itr);
			return;
		}
	}

	ClearItemInformation();
}

const Item ManageItems::GetItem(const std::string& name) const
{
	const auto items = pApplicationState->GetItems();
	for (const auto item : items)
		if (item.GetName() == name)
			return item;

	return Item();
}

void ManageItems::ClearItemInformation()
{
	pManageItems->labelItemName->clear();
	pManageItems->labelItemSize->clear();
}
