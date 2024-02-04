#include "AddItem.h"
/**
 * @brief AddItem
 * Constructor for the AddItem class.
 */
AddItem::AddItem() {}
/**
 * @brief ~AddItem
 * Destructor for the AddItem class.
 */
void AddItem::visit(Sensor& sensor)
{
    LocatorController::StorageControllerInstance()->GetStorage()->addSensor(&sensor);
}
/**
 * @brief ~AddItem
 * Destructor for the AddItem class.
 */
void AddItem::visit(Category& category)
{
    LocatorController::StorageControllerInstance()->GetStorage()->addCategory(&category);
}