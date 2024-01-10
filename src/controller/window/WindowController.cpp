#include "WindowController.h"
WindowController::WindowController()
    : main_window_(new MainView())
{}
void WindowController::setDisabled(bool b)
{
	main_window_->setDisabled(b);
}
bool WindowController::Init()
{
	main_window_->show();
	return true;
}
void WindowController::Destroy()
{

}
