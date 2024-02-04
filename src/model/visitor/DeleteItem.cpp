#include "DeleteItem.h"
/**
 * @brief Constructor
 */
DeleteItem::DeleteItem() {}
/**
 * @brief Visit a sensor and remove it from the list of sensors
 * @param sensor Sensor to be removed
 */
void DeleteItem::visit(Sensor& sensor)
{
    LocatorController::StorageControllerInstance()->GetStorage()->removeSensor(&sensor);
}
/**
 * @brief Visit a category and remove it from the list of categories
 * @param category Category to be removed
 */
void DeleteItem::visit(Category& category)
{
    LocatorController::StorageControllerInstance()->GetStorage()->removeCategory(&category);
}