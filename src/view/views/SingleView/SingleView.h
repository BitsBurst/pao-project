#ifndef SMARTSENSORS_SINGLEVIEW_H
#define SMARTSENSORS_SINGLEVIEW_H

#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include "../../core/AbstractView.h"
#include "../../utility/CustomElements.h"
#include "../../widgets/InformationWidget.h"
#include "../../widgets/SingleWidget/SingleSensorWidget.h"
#include "../../widgets/SingleWidget/SingleViewGroup.h"
#include "../../widgets/SingleWidget/SingleCategoryWidget.h"
/**
 * @brief The SingleView class
 */
class SingleView : public AbstractView {
    Q_OBJECT

signals:
    void changeToModifyView(AbstractItem* item);
	void deleteItem(AbstractItem* item);

private:
    InformationWidget * information_widget_;
    AbstractItem* item_;

    QStackedLayout* single_stack_;

    SingleSensorWidget* sensor_widget_;
    SingleViewGroup* group_widget_;
    SingleCategoryWidget* category_widget_;

    void handleEvents();
	void unsubscribeEvents();

	void onChangeToModifyView();
	void onDeleteItem();

public:
    explicit SingleView(AbstractItem* item, bool check_add_btn = false, QWidget *parent = nullptr);

    void setActiveView(int index);
    void setItem(AbstractItem* item);
    AbstractItem* getItem() const override;
};

#endif //SMARTSENSORS_SINGLEVIEW_H
