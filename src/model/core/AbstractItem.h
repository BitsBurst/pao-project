#ifndef PAO_PROJECT_ABSTRACTITEM_H
#define PAO_PROJECT_ABSTRACTITEM_H

#include <QString>
#include <QDataStream>
#include <QUuid>
#include <QJsonObject>
#include "../../utility/event/EventHandler.h"
#include "../visitor/IConstVisitor.h"

/**
 * @brief The AbstractItem class
 * @details This class is the base class for all the items in the application.
 * It provides the basic functionalities for the items.
 */
class AbstractItem{
public:
	 virtual ~AbstractItem();
	 AbstractItem();
	 AbstractItem(QString);
	 AbstractItem(AbstractItem const &abstract_item);
	 QString getId() const;
	 void setId(QString id);
	 QString getName() const;
	 void setName(QString name);
	 QJsonObject toJson() const;
	 static AbstractItem * fromJson(QJsonObject const &);
	 EventHandlerVoid modelChangedEvent;

    virtual void accept(IConstVisitor& visitor) const;

protected:
	QString id_;
	QString name_;

protected:
	void modelChangedHandler();
};
#endif //PAO_PROJECT_ABSTRACTITEM_H
