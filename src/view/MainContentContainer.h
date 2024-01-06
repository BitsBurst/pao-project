#ifndef SMARTSENSORS_MAINCONTENTCONTAINER_H
#define SMARTSENSORS_MAINCONTENTCONTAINER_H

#include "AbstractContainer.h"

class MainContentContainer : public AbstractContainer {
    Q_OBJECT

private:
public:
    explicit MainContentContainer(AbstractView * current_view = nullptr, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_MAINCONTENTCONTAINER_H
