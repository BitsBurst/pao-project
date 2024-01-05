#ifndef SMARTSENSORS_MAINCONTENTWIDGET_H
#define SMARTSENSORS_MAINCONTENTWIDGET_H

#include "AbstractContainer.h"

class MainContentWidget : public AbstractContainer {
    Q_OBJECT

private:
public:
    explicit MainContentWidget(QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_MAINCONTENTWIDGET_H
