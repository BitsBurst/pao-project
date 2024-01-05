#ifndef PAO_PROJECT_ABSTRACTITEM_H
#define PAO_PROJECT_ABSTRACTITEM_H

#include <QString>
#include <QDataStream>

class AbstractItem {
	friend QDataStream &operator<<(QDataStream &, const AbstractItem &);
	friend QDataStream &operator>>(QDataStream &, AbstractItem &);
public:
	 ~AbstractItem();
	 AbstractItem(QString, QString);
	 QString getId();
	 void setId(QString id);
	 QString getName();
	 void setName(QString name);
private:
	QString id_;
	QString name_ ;
};
QDataStream &operator<<(QDataStream &, const AbstractItem &);
QDataStream &operator>>(QDataStream &, AbstractItem &);
#endif //PAO_PROJECT_ABSTRACTITEM_H
