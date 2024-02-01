#ifndef SMARTSENSORS_CATEGORYFORMWIDGET_H
#define SMARTSENSORS_CATEGORYFORMWIDGET_H

#include <QSpinBox>
#include <QComboBox>
#include "AbstractFormWidget.h"
#include "../../../model/core/Category.h"

class CategoryFormWidget : public AbstractFormWidget {
    Q_OBJECT
private:
    QStringList units_, data_gens_;
    QComboBox * unit_measure_, * data_gen_;
public:
    explicit CategoryFormWidget(QWidget * parent = nullptr);

    void setValues(const Category& item);
    void reset() override;

	void updateItem(AbstractItem& item);
};

#endif //SMARTSENSORS_CATEGORYFORMWIDGET_H
