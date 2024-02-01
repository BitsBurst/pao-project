#include "DeleteItem.h"

DeleteItem::DeleteItem() {}

void DeleteItem::visit(Sensor& sensor)
{
    LocatorController::StorageControllerInstance()->GetStorage()->removeSensor(&sensor);
}

void DeleteItem::visit(Category& category)
{
    LocatorController::StorageControllerInstance()->GetStorage()->removeCategory(&category);
}