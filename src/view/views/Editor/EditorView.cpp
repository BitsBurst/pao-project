#include <QComboBox>
#include "EditorView.h"
#include "../../widgets/Editor/SensorFormWidget.h"
#include "../../widgets/Editor/CategoryFormWidget.h"

EditorView::EditorView(AbstractItem* item, QLayout* layout, QWidget* parent)
        :AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), item_(item)
{
    // Initialization
    information_widget_ = new InformationWidget(item_);


    // Form
    form_ = new QWidget(this);
    form_stack_ = new QStackedLayout(form_);

    form_->setLayout(form_stack_);

    SensorFormWidget* sensor_form = new SensorFormWidget(form_);
    CategoryFormWidget* category_form = new CategoryFormWidget(form_);

    form_stack_->addWidget(sensor_form);
    form_stack_->addWidget(category_form);

    editors_.push_back(sensor_form);
    editors_.push_back(category_form);

    // Layout Widgets
    layout_->addWidget(information_widget_);
    layout_->addWidget(form_);

    setActiveForm(0);
}

void EditorView::setItem(AbstractItem* item)
{
    item_ = item;
    update();
}

void EditorView::update()
{
    QWidget::update();

    information_widget_->deleteLater();
    layout_->replaceWidget(information_widget_, new InformationWidget(item_));
}

void EditorView::setActiveForm(int index)
{
    form_stack_->setCurrentIndex(index);
}
