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
    explicit EditorView(AbstractItem* item, QLayout * layout = nullptr, QWidget *parent = nullptr);
    void update();

    void setItem(AbstractItem* item);
    AbstractItem* getItem() const;
    void setActiveForm(int index);

    bool isNewObject() const;
    void setNewObject(bool newObject);
};

#endif //SMARTSENSORS_EDITORVIEW_H
