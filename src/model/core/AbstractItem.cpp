#include "AbstractItem.h"
AbstractItem::~AbstractItem()
= default;
AbstractItem::AbstractItem(QString name, void (**modelChangedHandlerPointer)()):id_(QUuid::createUuid().toString()), name_(name), modelChangedInstance_(modelChangedHandlerPointer)
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
	if (modelChangedInstance_ != nullptr && *modelChangedInstance_ != nullptr)
	{
		(*modelChangedInstance_)();
	}
}
void AbstractItem::setModelChangedPointer(void (**modelChanged)())
{
		modelChangedInstance_ = modelChanged;
}
AbstractItem::AbstractItem():id_(QUuid::createUuid().toString()), name_(""), modelChangedInstance_(nullptr)
{

}
QJsonObject AbstractItem::toJson() const
{
	QJsonObject json;
	json["id"] = id_;
	json["name"] = name_;
	return json;
}
AbstractItem AbstractItem::fromJson(const QJsonObject& object)
{
	AbstractItem abstract_item;
	if (const QJsonValue v = object["id"]; v.isString())
		abstract_item.id_ = object["id"].toString();
	if (const QJsonValue v = object["name"]; v.isString())
		abstract_item.name_ = object["name"].toString();
	return abstract_item;
}
