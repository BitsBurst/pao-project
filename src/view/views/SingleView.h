#ifndef SMARTSENSORS_SINGLEVIEW_H
#define SMARTSENSORS_SINGLEVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"

class SingleView : public AbstractView {
    Q_OBJECT
private:
public:
    explicit SingleView(QLayout * layout = nullptr, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_SINGLEVIEW_H
