#include "WindowController.h"
#include "../LocatorController.h"

WindowController::WindowController()
{
    content_stack_ = new QStackedWidget;
    sidebar_stack_ = new QStackedWidget;

    main_window_ = new MainView(content_stack_, sidebar_stack_);
}
bool WindowController::Init()
{
	main_window_->show();

    LocatorController::BusinessControllerInstance()->setDataFiel(main_window_, content_stack_, sidebar_stack_);

	return true;
}
