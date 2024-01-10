#ifndef PAO_PROJECT_ABSTRACTITEM_H
#define PAO_PROJECT_ABSTRACTITEM_H

#include <QString>
#include <QDataStream>
#include <QUuid>
#include <QJsonObject>
class AbstractItem {
public:
	 ~AbstractItem();
	 AbstractItem();
	 AbstractItem(QString, void (**)() = nullptr);
	 AbstractItem(AbstractItem const &abstract_item);
	 QString getId();
	 void setId(QString id);
	 QString getName();
	 void setName(QString name);
	 void setModelChangedPointer(void (**)());
	 QJsonObject toJson() const;
	 static AbstractItem fromJson(QJsonObject const &);

protected:
	QString id_;
	QString name_;
	void (**modelChangedInstance_)();

protected:
	void modelChangedHandler();
};
#endif //PAO_PROJECT_ABSTRACTITEM_H
