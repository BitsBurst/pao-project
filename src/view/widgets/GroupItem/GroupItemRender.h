#ifndef SMARTSENSORS_GROUPITEMRENDER_H
#define SMARTSENSORS_GROUPITEMRENDER_H

#include "../../../model/visitor/IConstVisitor.h"
#include "GroupItemWidget.h"

class GroupItemRender : public IConstVisitor {
private:
    GroupItemWidget * item_widget_;

public:
    explicit GroupItemRender(GroupItemWidget* item_widget);
    void visit(const Sensor& sensor) override;
    void visit(const Category& category) override;
};

#endif //SMARTSENSORS_GROUPITEMRENDER_H
