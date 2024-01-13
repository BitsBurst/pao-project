#ifndef SMARTSENSORS_ABSTRACTSINGLEVIEW_H
#define SMARTSENSORS_ABSTRACTSINGLEVIEW_H

#include <QLabel>
#include <QPushButton>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"
#include "../widgets/InformationWidget.h"

class AbstractSingleView : public AbstractView {
    Q_OBJECT
private:
    InformationWidget * information_widget_;
    const AbstractItem& item_;
public:
    explicit AbstractSingleView(const AbstractItem& item, bool check_add_btn = false, QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_ABSTRACTSINGLEVIEW_H
