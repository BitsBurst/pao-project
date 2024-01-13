#ifndef SMARTSENSORS_INFORMATIONWIDGET_H
#define SMARTSENSORS_INFORMATIONWIDGET_H

#include <QLabel>
#include <QPushButton>
#include "../core/AbstractWidget.h"

// Model
#include "../../model/core/AbstractItem.h"

class InformationWidget : public AbstractWidget {
    Q_OBJECT
private:
    QLabel *title_, *description_;
    QWidget * group_buttons_;
    QPushButton * delete_btn_, *modify_btn_, *add_btn_;

public:
    explicit InformationWidget(const AbstractItem& item, bool check_add_btn = false, QWidget * parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_INFORMATIONWIDGET_H
