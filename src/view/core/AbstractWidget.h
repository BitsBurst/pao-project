#ifndef SMARTSENSORS_ABSTRACTWIDGET_H
#define SMARTSENSORS_ABSTRACTWIDGET_H

#include <QVBoxLayout>
#include "AbstractGraphicalElement.h"

class AbstractWidget : public AbstractGraphicalElement {
    Q_OBJECT
private:
public:
    explicit AbstractWidget(QLayout * layout = new QVBoxLayout(), QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_ABSTRACTWIDGET_H
