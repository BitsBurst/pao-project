#ifndef PAO_PROJECT_ABSTRACTITEM_H
#define PAO_PROJECT_ABSTRACTITEM_H

#include <QString>
#include <QDataStream>

class AbstractItem {
	friend QDataStream &operator<<(QDataStream &, const AbstractItem &);
	friend QDataStream &operator>>(QDataStream &, AbstractItem &);
public:
	 ~AbstractItem();
	AbstractItem();
	 AbstractItem(QString, QString, void (**)() = nullptr);
	 QString getId() const;
	 void setId(QString id);
	 QString getName() const;
	 void setName(QString name);
	 void setModelChangedPointer(void (**)());
	 static void setModelChangedPointerStatic(void (*)());
	 static void (*modelChangedStatic_)();

private:
	QString id_;
	QString name_;
	void (**modelChangedInstance_)();

protected:
	void modelChangedHandler();
};
QDataStream &operator<<(QDataStream &, const AbstractItem &);
QDataStream &operator>>(QDataStream &, AbstractItem &);
#endif //PAO_PROJECT_ABSTRACTITEM_H
