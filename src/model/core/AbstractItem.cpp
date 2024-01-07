#include "AbstractItem.h"
void (*AbstractItem::modelChanged)() = nullptr;
AbstractItem::~AbstractItem()
= default;
QDataStream& operator<<(QDataStream& stream, const AbstractItem& abstract_item)
{
	stream << abstract_item.name_ << abstract_item.id_;
	return stream;
}
QDataStream& operator>>(QDataStream& stream, AbstractItem& abstract_item)
{
	stream >> abstract_item.name_ >> abstract_item.id_;
	return stream;
}
AbstractItem::AbstractItem(QString id, QString name): id_(id), name_(name)
{
}
QString AbstractItem::getId()
{
	return id_;
}
void AbstractItem::setId(QString id)
{
	id_ = id;
	modelChangedHandler();
}
QString AbstractItem::getName()
{
	return name_;
}
void AbstractItem::setName(QString name)
{
	name_ = name;
	modelChangedHandler();
}
void AbstractItem::modelChangedHandler()
{
	if (AbstractItem::modelChanged != nullptr)
	{
		AbstractItem::modelChanged();
	}
}
void AbstractItem::setModelChangedHandler(void (*fp)())
{
	AbstractItem::modelChanged = fp;
}