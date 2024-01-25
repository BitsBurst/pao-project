#ifndef SMARTSENSORS_ABSTRACTVIEW_H
#define SMARTSENSORS_ABSTRACTVIEW_H

#include <QWidget>
#include <QLayout>
#include "AbstractGraphicalElement.h"

class AbstractView : public AbstractGraphicalElement {
    Q_OBJECT
protected:
public:
    explicit AbstractView(QLayout * layout, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_ABSTRACTVIEW_H
