#ifndef SMARTSENSORS_GROUPLISTVIEW_H
#define SMARTSENSORS_GROUPLISTVIEW_H

#include <QLabel>
#include "../core/AbstractView.h"
#include "../widgets/GroupItemWidget.h"

class GroupListView : public AbstractView {
    Q_OBJECT
private:
    GroupItemWidget * item_;
public:
    explicit GroupListView(QLayout * layout = nullptr, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_GROUPLISTVIEW_H
