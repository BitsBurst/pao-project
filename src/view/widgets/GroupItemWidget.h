#ifndef SMARTSENSORS_GROUPITEMWIDGET_H
#define SMARTSENSORS_GROUPITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include "../core/AbstractWidget.h"
#include "../utility/CustomElements.h"

class GroupItemWidget : public AbstractWidget {
    Q_OBJECT
private:
    QString icon_src_;
    QString id_;

    QLabel * title_label_;
    QLabel * description_label_;
public:
    explicit GroupItemWidget(QString id, QString title = "", QString description = "", QString icon_src = "", QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_GROUPITEMWIDGET_H
