#include "ErrorController.h"
/**
 * @brief ErrorController::ErrorController
 * @details This class is used to manage the exceptions thrown by the application.
 * It is a singleton class.
 */
ErrorController::ErrorController()
{

}
/**
 * @brief ErrorController::Init
 * @return true
 */
bool ErrorController::Init()
{
	return true;
}
/**
 * @brief ErrorController::manageException
 * @param exception
 */
void ErrorController::manageException(NormalException exception)
{

}
/**
 * @brief ErrorController::manageException
 * @param exception
 */
void ErrorController::manageException(FatalException exception)
{

}
/**
 * @brief ErrorController::Destroy
 */
void ErrorController::Destroy()
{

}
/**
 * @brief ErrorController::~ErrorController
 */
ErrorController::~ErrorController()
= default;
