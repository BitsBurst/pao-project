#include <QComboBox>
#include "EditorView.h"
#include "../../widgets/Editor/SensorFormWidget.h"
#include "../../widgets/Editor/CategoryFormWidget.h"

EditorView::EditorView(AbstractItem* item, QLayout* layout, QWidget* parent)
        :AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), item_(item)
{
    // Initialization
    title_ = new QLabel("Editor");
    title_->setFont(CustomElements::getFontH1());

    ok_button_ = new QPushButton("Ok");
    cancel_button_ = new QPushButton("Annulla");

    QWidget * btn_row = new QWidget(this);
    QHBoxLayout * btn_row_layout = new QHBoxLayout(btn_row);

    btn_row_layout->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    btn_row->setLayout(btn_row_layout);

    btn_row_layout->addWidget(ok_button_);
    btn_row_layout->addWidget(cancel_button_);

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
    layout_->addWidget(title_);
    layout_->addWidget(form_);
    static_cast<QVBoxLayout*>(layout_)->addStretch();
    layout_->addWidget(btn_row);

    setActiveForm(0);
}

void EditorView::setItem(AbstractItem* item)
{
    item_ = item;
    // Funzionalità visitor di selezione del form
    static_cast<AbstractFormWidget*>(form_stack_->currentWidget())->setValues(*item);
}

void EditorView::update()
{
    QWidget::update();
}

void EditorView::setActiveForm(int index)
{
    form_stack_->setCurrentIndex(index);
}
