

#ifndef SMARTSENSORS_ABSTRACTCONTAINER_H
#define SMARTSENSORS_ABSTRACTCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include "AbstractView.h"

class AbstractContainer : public QWidget {
    Q_OBJECT

protected:
    AbstractView * current_view_;
    QVBoxLayout * layout_;

public:
    explicit AbstractContainer(AbstractView * current_view = nullptr, QWidget * parent = nullptr);

    AbstractView* getCurrentView() const;
    void setCurrentView(AbstractView* current_view);
};

#endif //SMARTSENSORS_ABSTRACTCONTAINER_H
