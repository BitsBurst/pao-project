#include <QComboBox>
#include "EditorView.h"
#include "../../widgets/Editor/ItemEditor.h"
#include "../../../controller/LocatorController.h"
/**
 * @brief EditorView::EditorView
 * @param item
 * @param parent
 */
EditorView::EditorView(AbstractItem* item, QWidget* parent)
        :AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), item_(item), newObject_(false)
{
    // Initialization
    title_ = new QLabel("Editor");
    title_->setFont(CustomElements::getFontH2());

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
	handleEvents();
}
/**
 * @brief EditorView::setItem
 * @param item
 */
void EditorView::setItem(AbstractItem* item)
{
    item_ = item;

    if (item_ != nullptr) {
        ItemEditor editor_visitor(this, sensor_form_, category_form_);
        item_->accept(editor_visitor);
    }
}
/**
 * @brief EditorView::update
 */
void EditorView::update()
{
    QWidget::update();
}
/**
 * @brief EditorView::setActiveForm
 * @param index
 */
void EditorView::setActiveForm(int index)
{
    form_stack_->setCurrentIndex(index);

    if (item_ == nullptr) {
        static_cast<AbstractFormWidget*>(form_stack_->currentWidget())->reset();
    }
}
/**
 * @brief EditorView::handleEvents
 */
void EditorView::handleEvents() {
	connect(ok_button_, &QPushButton::released, this, &EditorView::applyChanges);
    connect(cancel_button_, &QPushButton::released, this, &EditorView::cancelOperation);
}
/**
 * @brief EditorView::applyChanges
 */
void EditorView::applyChanges() {

    if (newObject_) {
        emit addNewItem(item_);
    }

	static_cast<AbstractFormWidget*>(form_stack_->currentWidget())->updateItem(item_);

   // emit modelChanged();
}
/**
 * @brief EditorView::isNewObject
 * @return
 */
bool EditorView::isNewObject() const
{
    return newObject_;
}
/**
 * @brief EditorView::setNewObject
 * @param newObject
 */
void EditorView::setNewObject(bool newObject)
{
    newObject_ = newObject;
}
/**
 * @brief EditorView::getItem
 * @return
 */
AbstractItem* EditorView::getItem() const
{
    return item_;
}
