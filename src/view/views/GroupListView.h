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
    void deleteItem(AbstractItem* item);

private:
    QScrollArea * scroll_area_;
    QVector<GroupItemWidget *> item_lists_;
    QWidget * scroll_area_list;
    QVBoxLayout * scroll_area_layout;

    QVector<AbstractItem*> items_;
public:
    void setItems(const QVector<AbstractItem*>& items);

public:
    explicit GroupListView(const QVector<AbstractItem*>& items,QWidget *parent = nullptr);



    void handleEvents();
};

#endif //SMARTSENSORS_GROUPLISTVIEW_H
