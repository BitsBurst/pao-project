#ifndef SMARTSENSORS_ITEMEDITOR_H
#define SMARTSENSORS_ITEMEDITOR_H

#include "../../../model/visitor/IConstVisitor.h"
#include "SensorFormWidget.h"
#include "CategoryFormWidget.h"
#include "../../views/Editor/EditorView.h"
/**
 * @brief The ItemEditor class
 * This class is the visitor for the item.
 */
class ItemEditor : public IConstVisitor {
private:
    SensorFormWidget* sensor_editor_;
    CategoryFormWidget* category_editor_;
    EditorView* editor_;

public:
    ItemEditor(EditorView* editor, SensorFormWidget* sensor_editor, CategoryFormWidget* category_editor);
    void visit(const Sensor& sensor) override;
    void visit(const Category& category) override;
};

#endif //SMARTSENSORS_ITEMEDITOR_H
