#ifndef SMARTSENSORS_CREATEVIEW_H
#define SMARTSENSORS_CREATEVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"

class CreateView : public AbstractView {
    Q_OBJECT
private:
public:
    explicit CreateView(QLayout * layout = nullptr, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_CREATEVIEW_H
