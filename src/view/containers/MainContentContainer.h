#ifndef SMARTSENSORS_MAINCONTENTCONTAINER_H
#define SMARTSENSORS_MAINCONTENTCONTAINER_H

#include <QLabel>
#include "../core/AbstractContainer.h"

class MainContentContainer : public AbstractContainer {
    Q_OBJECT

private:
public:
    explicit MainContentContainer(QStackedWidget * current_view = new QStackedWidget(), QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_MAINCONTENTCONTAINER_H
