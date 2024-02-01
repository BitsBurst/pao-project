#ifndef SMARTSENSORS_DELETEITEM_H
#define SMARTSENSORS_DELETEITEM_H

#include "IVisitor.h"
#include "../../controller/LocatorController.h"

class DeleteItem : public IVisitor{
public:
    explicit DeleteItem();
    void visit(Sensor& sensor) override;
    void visit(Category& category) override;
};

#endif //SMARTSENSORS_DELETEITEM_H
