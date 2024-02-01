#include "WindowController.h"
#include "../LocatorController.h"
/**
 * @brief WindowController::WindowController
 * @details This class is responsible for the main window of the application.
 * It is responsible for the initialization of the main window
 */
WindowController::WindowController()
{
	content_stack_ = new QStackedWidget;
	sidebar_stack_ = new QStackedWidget;

	main_window_ = new MainView(content_stack_, sidebar_stack_);
	setDisabled(true);
}
/**
 * @brief WindowController::setDisabled
 * @param b
 * @details This method is used to set the main window to disabled or enabled.
 * This is used to prevent the user from interacting with the application while
 * the application is loading.
 */
void WindowController::setDisabled(bool b)
{
	main_window_->setDisabled(b);
}
/**
 * @brief WindowController::Init
 * @return
 * @details This method is used to initialize the main window.
 */
bool WindowController::Init()
{
	main_window_->show();

    LocatorController::BusinessControllerInstance()->setDataField(main_window_, content_stack_, sidebar_stack_);

	return true;
}
/**
 * @brief WindowController::Destroy
 * @details This method is used to destroy the main window.
 */
void WindowController::Destroy()
{

}
