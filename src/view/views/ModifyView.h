#ifndef SMARTSENSORS_MODIFYVIEW_H
#define SMARTSENSORS_MODIFYVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"

class ModifyView : public AbstractView {
Q_OBJECT
private:
    QLabel *label1_, *label2_;
public:
    explicit ModifyView(QLayout * layout = nullptr, QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_MODIFYVIEW_H
