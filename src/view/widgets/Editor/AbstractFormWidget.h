#ifndef SMARTSENSORS_ABSTRACTFORMWIDGET_H
#define SMARTSENSORS_ABSTRACTFORMWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../../core/AbstractWidget.h"

class AbstractFormWidget : public AbstractWidget {
    Q_OBJECT
protected:
    // QLabel * name_, *description_;
    QLineEdit * name_edit_, * description_edit_;

public:
    AbstractFormWidget(QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_ABSTRACTFORMWIDGET_H
