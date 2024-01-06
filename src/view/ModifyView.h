

#ifndef SMARTSENSORS_MODIFYVIEW_H
#define SMARTSENSORS_MODIFYVIEW_H

#include <QLabel>
#include "AbstractView.h"

class ModifyView : public AbstractView {
Q_OBJECT
private:
public:
    explicit ModifyView(QLayout * layout = nullptr, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_MODIFYVIEW_H
