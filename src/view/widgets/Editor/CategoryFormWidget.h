#ifndef SMARTSENSORS_CATEGORYFORMWIDGET_H
#define SMARTSENSORS_CATEGORYFORMWIDGET_H

#include <QSpinBox>
#include "AbstractFormWidget.h"

class CategoryFormWidget : public AbstractFormWidget {
    Q_OBJECT
private:
    QLabel *max_range_, * min_range_;
    QSpinBox *max_range_edit_, * min_range_edit_;
public:
    explicit CategoryFormWidget(QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_CATEGORYFORMWIDGET_H
