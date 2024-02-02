#include "AddItem.h"

AddItem::AddItem() {}

void AddItem::visit(Sensor& sensor)
{
    LocatorController::StorageControllerInstance()->GetStorage()->addSensor(&sensor);
}

void AddItem::visit(Category& category)
{
    LocatorController::StorageControllerInstance()->GetStorage()->addCategory(&category);
}