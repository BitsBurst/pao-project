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
    void showSingleItem(AbstractItem* item);

private:
    QScrollArea * scroll_area_;
    QVector<GroupItemWidget *> item_lists_;
    QWidget * scroll_area_list;
    QVBoxLayout * scroll_area_layout;

    GroupItemWidget* current_selected_;


    QVector<AbstractItem*> items_;

    void handleEvents();
	void subscribeToGroupItemsEvents(GroupItemWidget *);
	void unsubscribeToGroupItemsEvents(GroupItemWidget *);
    void handleShowSingleItem(GroupItemWidget* graphical_item, AbstractItem* item);

public:
    explicit GroupListView(const QVector<AbstractItem*>& items,QWidget *parent = nullptr);
    ~GroupListView();
    void setItems(const QVector<AbstractItem*>& items);
	void deleteListItem(GroupItemWidget* item);
    GroupItemWidget* getGroupItem(AbstractItem * item);
    void resetCurrentItem();

    QVector<AbstractItem*>& getItems();

};

#endif //SMARTSENSORS_GROUPLISTVIEW_H
