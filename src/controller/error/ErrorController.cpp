#include <QMessageBox>
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
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, QString("Error: %1").arg(exception.getMessage()));
	QMessageBox deleteConfirm;
	deleteConfirm.setText("Errore");
	deleteConfirm.setInformativeText(exception.getMessage());
	deleteConfirm.setStandardButtons(QMessageBox::Ok);
	deleteConfirm.setDefaultButton(QMessageBox::Ok);
}
/**
 * @brief ErrorController::manageException
 * @param exception
 */
void ErrorController::manageException(FatalException exception)
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, QString("Fatal error: %1").arg(exception.getMessage()));
	QMessageBox deleteConfirm;
	deleteConfirm.setText("Errore Grave");
	deleteConfirm.setInformativeText(exception.getMessage());
	deleteConfirm.setStandardButtons(QMessageBox::Ok);
	deleteConfirm.setDefaultButton(QMessageBox::Ok);
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
