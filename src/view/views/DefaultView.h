#ifndef SMARTSENSORS_DEFAULTVIEW_H
#define SMARTSENSORS_DEFAULTVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"

class DefaultView : public AbstractView {
    Q_OBJECT
public:
    explicit DefaultView(QWidget* parent = nullptr);
};

#endif //SMARTSENSORS_DEFAULTVIEW_H
