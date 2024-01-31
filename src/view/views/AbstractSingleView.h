#ifndef SMARTSENSORS_ABSTRACTSINGLEVIEW_H
#define SMARTSENSORS_ABSTRACTSINGLEVIEW_H

#include <QLabel>
#include <QPushButton>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"
#include "../widgets/InformationWidget.h"

class AbstractSingleView : public AbstractView {
    Q_OBJECT

signals:
    void changeToModifyView(AbstractItem* item);

private:
    InformationWidget * information_widget_;
    AbstractItem* item_;

    void handleEvents();

public:
    explicit AbstractSingleView(AbstractItem* item, bool check_add_btn = false, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_ABSTRACTSINGLEVIEW_H
