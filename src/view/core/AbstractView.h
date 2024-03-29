#ifndef SMARTSENSORS_ABSTRACTVIEW_H
#define SMARTSENSORS_ABSTRACTVIEW_H

#include <QWidget>
#include <QLayout>
#include "AbstractGraphicalElement.h"
#include "../../model/core/AbstractItem.h"
/**
 * @brief The AbstractView class
 */
class AbstractView : public AbstractGraphicalElement {
    Q_OBJECT
public:
	virtual ~AbstractView();
    explicit AbstractView(QLayout * layout, QWidget *parent = nullptr);

    virtual AbstractItem* getItem() const;
};

#endif //SMARTSENSORS_ABSTRACTVIEW_H
