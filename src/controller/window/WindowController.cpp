#include "WindowController.h"
WindowController::WindowController()
{
	main_window_ = new MainWindow();
}
bool WindowController::Init()
{
	main_window_->show();
	return true;
}
