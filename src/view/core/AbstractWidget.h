#ifndef SMARTSENSORS_ABSTRACTWIDGET_H
#define SMARTSENSORS_ABSTRACTWIDGET_H

#include <QVBoxLayout>
#include "AbstractGraphicalElement.h"
/**
 * @brief The AbstractWidget class
 */
class AbstractWidget : public AbstractGraphicalElement {
    Q_OBJECT
private:
public:
    explicit AbstractWidget(QLayout * layout = new QVBoxLayout(), QWidget * parent = nullptr);
	virtual ~AbstractWidget();
};

#endif //SMARTSENSORS_ABSTRACTWIDGET_H
