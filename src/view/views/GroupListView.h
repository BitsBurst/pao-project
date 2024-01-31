#ifndef SMARTSENSORS_GROUPLISTVIEW_H
#define SMARTSENSORS_GROUPLISTVIEW_H

#include <QLabel>
#include <QScrollArea>
#include "../core/AbstractView.h"
#include "../widgets/GroupItem/GroupItemWidget.h"
#include "../utility/CustomElements.h"
#include "../../model/core/AbstractItem.h"

class GroupListView : public AbstractView {
    Q_OBJECT
signals:
    void changeToModifyView(AbstractItem* item);

private:
    QScrollArea * scroll_area_;
    QVector<GroupItemWidget *> item_lists_;

    QVector<AbstractItem*> items_;
public:
    explicit GroupListView(const QVector<AbstractItem*>& items,QWidget *parent = nullptr);

    void handleEvents();
};

#endif //SMARTSENSORS_GROUPLISTVIEW_H
