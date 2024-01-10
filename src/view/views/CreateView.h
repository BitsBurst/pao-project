#ifndef SMARTSENSORS_CREATEVIEW_H
#define SMARTSENSORS_CREATEVIEW_H

#include <QLabel>
#include "../utility/CustomElements.h"
#include "../core/AbstractView.h"

class CreateView : public AbstractView {
    Q_OBJECT
private:
    QLabel *label1_, *label2_;
public:
    explicit CreateView(QLayout * layout = nullptr, QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_CREATEVIEW_H
