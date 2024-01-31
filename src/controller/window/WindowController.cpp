#include "WindowController.h"
#include "../LocatorController.h"

WindowController::WindowController()
{
	content_stack_ = new QStackedWidget;
	sidebar_stack_ = new QStackedWidget;

	main_window_ = new MainView(content_stack_, sidebar_stack_);
}
void WindowController::setDisabled(bool b)
{
	main_window_->setDisabled(b);
}

bool WindowController::Init()
{
	main_window_->show();

    LocatorController::BusinessControllerInstance()->setDataField(main_window_, content_stack_, sidebar_stack_);

	return true;
}
void WindowController::Destroy()
{

}
