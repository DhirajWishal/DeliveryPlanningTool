// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QtWidgets/QWidget.h>
#include <QtWidgets/QMainWindow.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Checkout; }
QT_END_NAMESPACE

/**
 * Checkout object.
 * This object handles information regarding the checkout page.
 * 
 * When generating the optimal delivery plan, we assume that every package takes approximately 10 minutes to unload, and 30 minutes spent on a single location (handling files maybe..?).
 * The algorithm takes this into consideration and assigns a route (since a truck can deliver all the good in one go without the need to reload). If a location takes more time,
 * than whats available, that location is added to the next day.
 */
class Checkout : public QWidget
{
	Q_OBJECT

public:
	/**
	 * Default constructor.
	 * 
	 * @param pApplicationState The application state pointer.
	 * @param parent The parent object pointer.
	 */
	Checkout(const std::shared_ptr<ApplicationState>& pApplicationState, QWidget* parent = nullptr);

	/**
	 * Refresh the tab information.
	 */
	void Refresh();

private slots:
	/**
	 * Function to handle truck select.
	 */
	void HandleTruckSelect(int index);

	/**
	 * Function to handle generate document button press.
	 */
	void HandleGenerateDocument();

private:
	/**
	 * Display information to the user.
	 */
	void DisplayInformation();

	/**
	 * Clear the displaying information.
	 */
	void ClearInformation();

	/**
	 * Generate routes using the routes allocated for today.
	 * 
	 * @param truck The truck to generate the documents to.
	 * @param routesForTheDay The routes the truck would take.
	 */
	void GenerateDocuments(const Truck truck, const std::vector<Route> routesForTheDay);

private:
	std::unique_ptr<Ui::Checkout> pCheckout = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	int mCurrentTruckIndex = -1;
};

#endif	// CHEKOUT_H
