#include "ItemEditor.h"
/**
 * @brief ItemEditor::ItemEditor
 * This is the constructor of the class. It initializes the editor, the sensor editor and the category editor.
 * @param editor
 * @param sensor_editor
 * @param category_editor
 */
ItemEditor::ItemEditor(EditorView* editor,SensorFormWidget* sensor_editor, CategoryFormWidget* category_editor)
    :IConstVisitor(), sensor_editor_(sensor_editor), category_editor_(category_editor), editor_(editor) {}
/**
 * @brief ItemEditor::visit
 * This method visits the sensor and sets the values in the sensor editor.
 * @param sensor
 */
void ItemEditor::visit(const Sensor& sensor) {
    sensor_editor_->setValues(sensor);
    editor_->setActiveForm(0);
}
/**
 * @brief ItemEditor::visit
 * This method visits the category and sets the values in the category editor.
 * @param category
 */
void ItemEditor::visit(const Category& category) {
    category_editor_->setValues(category);
    editor_->setActiveForm(1);
}
