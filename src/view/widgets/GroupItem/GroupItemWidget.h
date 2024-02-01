#ifndef SMARTSENSORS_GROUPITEMWIDGET_H
#define SMARTSENSORS_GROUPITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "../../core/AbstractWidget.h"
#include "../../utility/CustomElements.h"
#include "../../../model/core/AbstractItem.h"

class GroupItemWidget : public AbstractWidget {
    Q_OBJECT

signals:
    void changeToModifyView(AbstractItem* item);
    void deleteItem(AbstractItem* item);

private:
    QString icon_src_;
    QString id_;

    QLabel * title_label_;
    QLabel * detail_label_;

    QPushButton *modify_btn_, *delete_btn_;
    AbstractItem* item_;
	void render();
public:
    explicit GroupItemWidget(QString id, QString title = "", QString description = "", QString icon_src = "", QWidget *parent = nullptr);
    explicit GroupItemWidget(AbstractItem* item, QWidget *parent = nullptr);

    void setTitle(const QString& title);
    void setDetail(const QString& detail);

    void handleEvents();
};

#endif //SMARTSENSORS_GROUPITEMWIDGET_H
