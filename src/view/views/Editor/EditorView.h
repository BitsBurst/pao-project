#ifndef SMARTSENSORS_EDITORVIEW_H
#define SMARTSENSORS_EDITORVIEW_H

#include <QLabel>
#include <QStackedLayout>
#include "../../core/AbstractView.h"
#include "../../utility/CustomElements.h"

// Model
#include "../../../model/core/AbstractItem.h"
#include "../../widgets/Editor/AbstractFormWidget.h"
#include "../../widgets/Editor/SensorFormWidget.h"
#include "../../widgets/Editor/CategoryFormWidget.h"
/**
 * @brief The EditorView class
 * The EditorView class is a view that allows the user to edit the properties of an AbstractItem.
 * The view is composed by a title, a form and two buttons to confirm or cancel the operation.
 */
class EditorView : public AbstractView {
    Q_OBJECT

signals:
    void modelChanged();
    void cancelOperation();
    void addNewItem(AbstractItem * item);

private slots:
	void applyChanges();

private:
    QLabel * title_;
    QWidget * form_;
    QStackedLayout* form_stack_;
    AbstractItem* item_;
    // TODO[Luca] Remove useless Vector?
    QVector<AbstractFormWidget*> editors_;
    QPushButton * ok_button_, * cancel_button_;

    SensorFormWidget * sensor_form_;
    CategoryFormWidget * category_form_;

    bool newObject_;

    void handleEvents();

public:
    explicit EditorView(AbstractItem* item, QWidget* parent);
    void update();

    void setItem(AbstractItem* item);
    AbstractItem* getItem() const override;
    void setActiveForm(int index);

    bool isNewObject() const;
    void setNewObject(bool newObject);
};

#endif //SMARTSENSORS_EDITORVIEW_H
