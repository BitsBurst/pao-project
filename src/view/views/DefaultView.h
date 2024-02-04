#ifndef SMARTSENSORS_DEFAULTVIEW_H
#define SMARTSENSORS_DEFAULTVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"
#include "../utility/CustomElements.h"
/**
 * @brief DefaultView is a class that inherits from AbstractView and is used to display the default view of the application.
 */
class DefaultView : public AbstractView {
    Q_OBJECT
public:
    explicit DefaultView(QWidget* parent = nullptr);
};

#endif //SMARTSENSORS_DEFAULTVIEW_H
