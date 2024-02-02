#include "SingleCategoryWidget.h"

SingleCategoryWidget::SingleCategoryWidget(const QVector<AbstractItem*>& items, QWidget* parent)
    :AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    // Initialization
    group_list_view_ = new GroupListView(items, this);

    layout_->addWidget(group_list_view_);
}
SingleCategoryWidget::~SingleCategoryWidget()
{

}
