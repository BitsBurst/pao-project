#ifndef SMARTSENSORS_MODIFYVIEW_H
#define SMARTSENSORS_MODIFYVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"

// Model
#include "../../model/core/AbstractItem.h"

class ModifyView : public AbstractView {
Q_OBJECT
private:
    QLabel *label1_, *label2_;
    AbstractItem* item_;
public:
    explicit ModifyView(AbstractItem* item, QLayout * layout = nullptr, QWidget *parent = nullptr);
    void show();
    void update();

    void setItem(AbstractItem* item);
};

#endif //SMARTSENSORS_MODIFYVIEW_H
