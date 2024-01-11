#ifndef SMARTSENSORS_ABSTRACTSINGLEVIEW_H
#define SMARTSENSORS_ABSTRACTSINGLEVIEW_H

#include <QLabel>
#include <QPushButton>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"

class AbstractSingleView : public AbstractView {
    Q_OBJECT
private:
    QLabel *title_, *description_;
    QWidget * group_buttons_;
    QPushButton * delete_btn_, *modify_btn_;
    QVector<QPushButton*> button_list_;
public:
    explicit AbstractSingleView(QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_ABSTRACTSINGLEVIEW_H
