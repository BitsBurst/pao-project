#include <QComboBox>
#include "EditorView.h"
#include "../../widgets/Editor/ItemEditor.h"

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

    sensor_form_ = new SensorFormWidget(form_);
    category_form_ = new CategoryFormWidget(form_);

    form_stack_->addWidget(sensor_form_);
    form_stack_->addWidget(category_form_);

    editors_.push_back(sensor_form_);
    editors_.push_back(category_form_);

    if (item_ != nullptr) {
        ItemEditor editor_visitor(this, sensor_form_, category_form_);
        item_->accept(editor_visitor);
    }

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

    if (item_ != nullptr) {
        ItemEditor editor_visitor(this, sensor_form_, category_form_);
        item_->accept(editor_visitor);
    }
}

void EditorView::update()
{
    QWidget::update();
}

void EditorView::setActiveForm(int index)
{
    form_stack_->setCurrentIndex(index);
}
