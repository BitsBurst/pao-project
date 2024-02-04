#ifndef SMARTSENSORS_CREATEVIEW_H
#define SMARTSENSORS_CREATEVIEW_H

#include <QLabel>
#include "../utility/CustomElements.h"
#include "../core/AbstractView.h"
/**
 * @brief The CreateView class
 */
class CreateView : public AbstractView {
    Q_OBJECT
private:
    QLabel *label1_, *label2_;
public:
    explicit CreateView(QWidget* parent);
};

#endif //SMARTSENSORS_CREATEVIEW_H
