#ifndef SMARTSENSORS_GROUPLISTVIEW_H
#define SMARTSENSORS_GROUPLISTVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"


class GroupListView : public AbstractView {
    Q_OBJECT
private:
public:
    explicit GroupListView(QLayout * layout = nullptr, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_GROUPLISTVIEW_H
