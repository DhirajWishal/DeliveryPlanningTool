#ifndef MANAGE_ITEMS_H
#define MANAGE_ITEMS_H

#include <QMainWindow.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ManageItems; }
QT_END_NAMESPACE

/**
 * Manage items object.
 * This object manages the items registered in the application.
 */
class ManageItems : public QMainWindow
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
	 * The close event override.
	 * This function is used to notify the main window to do certain tasks.
	 *
	 * @param event The close events.
	 */
	virtual void closeEvent(QCloseEvent* event) override;

private:
	std::unique_ptr<Ui::ManageItems> pManageItems = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;
};

#endif
