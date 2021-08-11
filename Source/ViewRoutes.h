#ifndef VIEW_ROUTES_H
#define VIEW_ROUTES_H

#include <QMainWindow.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewRoutes; }
QT_END_NAMESPACE

/**
 * View routes class.
 * This object displays route information to the main window tab.
 */
class ViewRoutes : public QWidget
{
	Q_OBJECT

public:
	/**
	 * Construct the object using application state and parent.
	 *
	 * @param pApplicationState The application state pointer.
	 * @param parent The parent object pointer. Default is nullptr.
	 */
	ViewRoutes(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent = nullptr);

	/**
	 * Delete a child object created by this.
	 *
	 * @param pChildWindow The child window pointer.
	 */
	void DeleteChild(QMainWindow* pChildWindow);

	/**
	 * Refresh the tab information.
	 */
	void Refresh();

private slots:
	/**
	 * Function to handle the manage button press.
	 */
	void HandleManage();

private:
	std::unique_ptr<Ui::ViewRoutes> pViewRoutes = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;
};

#endif
