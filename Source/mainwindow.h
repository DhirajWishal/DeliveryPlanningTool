// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QListWidget.h>
#include <QtWidgets/QTabWidget.h>

#include "ApplicationState.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * Main window object.
 * This object holds and handles the main window.
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * Default constructor.
	 * Construct the object using its parent.
	 * 
	 * @param parent The parent object pointer. Default is nullptr.
	 */
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	/**
	 * Delete a child object created by this.
	 *
	 * @param pChildWindow The child window pointer.
	 */
	void DeleteChild(QMainWindow* pChildWindow);

	/**
	 * Delete a child object created by this.
	 *
	 * @param pChildWindow The child window pointer.
	 */
	void DeleteChild(QWidget* pChildWindow);

private slots:
	/**
	 * Function to handle tab change.
	 * 
	 * @param index The tab index.
	 */
	void HandleTabChange(int index);

private:
	Ui::MainWindow* pMainWindow = nullptr;
	std::shared_ptr<ApplicationState> pApplicationState = nullptr;

	std::unique_ptr<QTabWidget> pTabWidget = nullptr;
};
#endif // MAINWINDOW_H
