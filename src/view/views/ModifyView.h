#ifndef SMARTSENSORS_MODIFYVIEW_H
#define SMARTSENSORS_MODIFYVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"

// Model
#include "../../model/core/AbstractItem.h"
#include "../widgets/SensorFormWidget.h"
#include "../widgets/InformationWidget.h"

class ModifyView : public AbstractView {
Q_OBJECT
private:
    InformationWidget * information_widget_;
    SensorFormWidget * form_;
    AbstractItem* item_;
public:
    explicit ModifyView(AbstractItem* item, QLayout * layout = nullptr, QWidget *parent = nullptr);
    void update();

    void setItem(AbstractItem* item);
};

#endif //SMARTSENSORS_MODIFYVIEW_H
