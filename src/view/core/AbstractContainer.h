

#ifndef SMARTSENSORS_ABSTRACTCONTAINER_H
#define SMARTSENSORS_ABSTRACTCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include "../utility/CustomElements.h"
#include "AbstractView.h"
#include "AbstractGraphicalElement.h"

class AbstractContainer : public AbstractGraphicalElement {
    Q_OBJECT
protected:
    AbstractView * current_view_;

public:
    explicit AbstractContainer(AbstractView * current_view = nullptr, QWidget * parent = nullptr);

    void show();
    void hide();
    void update();

    AbstractView* getCurrentView() const;
    void setCurrentView(AbstractView* current_view);
};

#endif //SMARTSENSORS_ABSTRACTCONTAINER_H
