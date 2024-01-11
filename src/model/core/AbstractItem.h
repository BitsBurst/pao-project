#ifndef PAO_PROJECT_ABSTRACTITEM_H
#define PAO_PROJECT_ABSTRACTITEM_H

#include <QString>
#include <QDataStream>
#include <QUuid>
#include <QJsonObject>
#include "../../utility/event/EventHandler.h"
class AbstractItem {
public:
	 ~AbstractItem();
	 AbstractItem();
	 AbstractItem(QString);
	 AbstractItem(AbstractItem const &abstract_item);
	 QString getId();
	 void setId(QString id);
	 QString getName();
	 void setName(QString name);
	 QJsonObject toJson() const;
	 static AbstractItem * fromJson(QJsonObject const &);
	 EventHandlerVoid modelChangedEvent;

protected:
	QString id_;
	QString name_;

protected:
	void modelChangedHandler();
};
#endif //PAO_PROJECT_ABSTRACTITEM_H
