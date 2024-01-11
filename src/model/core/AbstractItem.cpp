#include "AbstractItem.h"
AbstractItem::~AbstractItem()
= default;
AbstractItem::AbstractItem(QString name):id_(QUuid::createUuid().toString()), name_(name)
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
	modelChangedEvent.notifyAsync();
}
AbstractItem::AbstractItem():id_(QUuid::createUuid().toString()), name_("")
{

}
QJsonObject AbstractItem::toJson() const
{
	QJsonObject json;
	json["id"] = id_;
	json["name"] = name_;
	return json;
}
AbstractItem * AbstractItem::fromJson(const QJsonObject& object)
{
	AbstractItem * abstract_item = new AbstractItem();
	if (const QJsonValue v = object["id"]; v.isString())
		abstract_item->id_ = object["id"].toString();
	if (const QJsonValue v = object["name"]; v.isString())
		abstract_item->name_ = object["name"].toString();
	return abstract_item;
}
AbstractItem::AbstractItem(const AbstractItem& abstract_item)
{
	id_ = abstract_item.id_;
	name_ = abstract_item.name_;
}
