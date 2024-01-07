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
	 static void setModelChangedHandler(void (*)());
private:
	QString id_;
	QString name_ ;
	static void (*modelChanged)();
protected:
	static void modelChangedHandler();
};
QDataStream &operator<<(QDataStream &, const AbstractItem &);
QDataStream &operator>>(QDataStream &, AbstractItem &);
#endif //PAO_PROJECT_ABSTRACTITEM_H
