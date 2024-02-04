#ifndef SMARTSENSORS_SINGLECATEGORYWIDGET_H
#define SMARTSENSORS_SINGLECATEGORYWIDGET_H

#include "../../core/AbstractWidget.h"
#include "../../views/GroupListView.h"
#include "../../../model/core/AbstractItem.h"
#include "../../../model/core/Category.h"
/**
 * @brief The SingleCategoryWidget class
 * This class is the widget for the single category.
 */
class SingleCategoryWidget : public AbstractWidget {
    Q_OBJECT
private:
    QLabel * unit_measure_, * distribution_type_;
public:
    explicit SingleCategoryWidget(Category* item, QWidget* parent = nullptr);
	~SingleCategoryWidget() override;

    void setItem(Category* item);
};

#endif //SMARTSENSORS_SINGLECATEGORYWIDGET_H
