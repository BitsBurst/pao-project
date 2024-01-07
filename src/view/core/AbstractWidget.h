#ifndef SMARTSENSORS_ABSTRACTWIDGET_H
#define SMARTSENSORS_ABSTRACTWIDGET_H

#include "AbstractView.h"

class AbstractWidget : public AbstractView {
    Q_OBJECT
private:
public:
    explicit AbstractWidget(QLayout * layout = nullptr, QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_ABSTRACTWIDGET_H
