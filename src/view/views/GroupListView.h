#ifndef SMARTSENSORS_GROUPLISTVIEW_H
#define SMARTSENSORS_GROUPLISTVIEW_H

#include <QLabel>
#include <QScrollArea>
#include "../core/AbstractView.h"
#include "../widgets/GroupItemWidget.h"

class GroupListView : public AbstractView {
    Q_OBJECT
private:
    QScrollArea * scroll_area_;
    QVector<GroupItemWidget *> item_lists_;
public:
    explicit GroupListView(QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_GROUPLISTVIEW_H
