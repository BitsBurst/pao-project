#ifndef SMARTSENSORS_SINGLECATEGORYWIDGET_H
#define SMARTSENSORS_SINGLECATEGORYWIDGET_H

#include "../../core/AbstractWidget.h"
#include "../../views/GroupListView.h"
#include "../../../model/core/AbstractItem.h"

class SingleCategoryWidget : public AbstractWidget {
    Q_OBJECT
private:
    GroupListView* group_list_view_;

public:
    explicit SingleCategoryWidget(const QVector<AbstractItem*>& items, QWidget* parent = nullptr);
};

#endif //SMARTSENSORS_SINGLECATEGORYWIDGET_H
