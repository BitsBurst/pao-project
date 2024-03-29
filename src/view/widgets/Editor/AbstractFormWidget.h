#ifndef SMARTSENSORS_ABSTRACTFORMWIDGET_H
#define SMARTSENSORS_ABSTRACTFORMWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../../core/AbstractWidget.h"
#include "../../../model/core/AbstractItem.h"
/**
 * @brief The AbstractFormWidget class
 * This class is the base class for the form widgets.
 */
class AbstractFormWidget : public AbstractWidget {
    Q_OBJECT
protected:
    // QLabel * name_, *description_;
    QLineEdit * name_edit_, * description_edit_;

public:
    AbstractFormWidget(QWidget * parent = nullptr);
	~AbstractFormWidget() override;

    virtual void setValues(const AbstractItem& item);
    virtual void reset();

	virtual void updateItem(AbstractItem* item);
};

#endif //SMARTSENSORS_ABSTRACTFORMWIDGET_H
