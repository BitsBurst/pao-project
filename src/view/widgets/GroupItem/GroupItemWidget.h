#ifndef SMARTSENSORS_GROUPITEMWIDGET_H
#define SMARTSENSORS_GROUPITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "../../core/AbstractWidget.h"
#include "../../utility/CustomElements.h"
#include "../../../model/core/AbstractItem.h"
/**
 * @brief The GroupItemWidget class
 * This class is the widget for the group item.
 */
class GroupItemWidget : public AbstractWidget {
    Q_OBJECT

signals:
    void changeToModifyView(AbstractItem* item);
    void deleteItem(AbstractItem* item);
    void showSingleItem(GroupItemWidget * graphical_item, AbstractItem* item);

private:
    QString icon_src_;
    QString id_;

    QLabel * title_label_;
    QLabel * detail_label_;

    QPushButton *modify_btn_, *delete_btn_;
    AbstractItem* item_;
	void refresh();

protected:
    void mousePressEvent(QMouseEvent *event) override;

public:
    explicit GroupItemWidget(AbstractItem* item, QWidget *parent = nullptr);
	~GroupItemWidget();

    void setTitle(const QString& title);
    void setDetail(const QString& detail);
	void setActive(bool);

    void handleEvents();
	AbstractItem* getItem();
};

#endif //SMARTSENSORS_GROUPITEMWIDGET_H
