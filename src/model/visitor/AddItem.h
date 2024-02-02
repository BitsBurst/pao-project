#ifndef SMARTSENSORS_ADDITEM_H
#define SMARTSENSORS_ADDITEM_H


#include "IVisitor.h"
#include "../../controller/LocatorController.h"

class AddItem : public IVisitor{
public:
    explicit AddItem();
    void visit(Sensor& sensor) override;
    void visit(Category& category) override;
};

#endif //SMARTSENSORS_ADDITEM_H
