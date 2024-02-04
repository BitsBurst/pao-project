#include "ItemEditor.h"

ItemEditor::ItemEditor(EditorView* editor,SensorFormWidget* sensor_editor, CategoryFormWidget* category_editor)
    :IConstVisitor(), sensor_editor_(sensor_editor), category_editor_(category_editor), editor_(editor) {}

void ItemEditor::visit(const Sensor& sensor) {
    sensor_editor_->setValues(sensor);
    editor_->setActiveForm(0);
}

void ItemEditor::visit(const Category& category) {
    category_editor_->setValues(category);
    editor_->setActiveForm(1);
}
