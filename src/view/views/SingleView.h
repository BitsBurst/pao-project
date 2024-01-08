#ifndef SMARTSENSORS_SINGLEVIEW_H
#define SMARTSENSORS_SINGLEVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"

class SingleView : public AbstractView {
    Q_OBJECT
private:
    QLabel *label1_, *label2_;
public:
    explicit SingleView(QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_SINGLEVIEW_H
