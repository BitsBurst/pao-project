

#ifndef SMARTSENSORS_ABSTRACTCONTAINER_H
#define SMARTSENSORS_ABSTRACTCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "../utility/CustomElements.h"
#include "AbstractView.h"
#include "AbstractGraphicalElement.h"

class AbstractContainer : public AbstractGraphicalElement {
    Q_OBJECT
protected:
    QStackedWidget * current_view_;

public:
    explicit AbstractContainer(QStackedWidget * current_view = nullptr, QWidget * parent = nullptr);

    int getCurrentView() const;
    void setCurrentView(int id);
};

#endif //SMARTSENSORS_ABSTRACTCONTAINER_H
