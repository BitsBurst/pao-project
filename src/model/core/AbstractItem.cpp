#include "AbstractItem.h"
void (*AbstractItem::modelChangedStatic_)() = nullptr;
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
AbstractItem::AbstractItem(QString id, QString name, void (**modelChangedHandlerPointer)()):id_(id), name_(name), modelChangedInstance_(modelChangedHandlerPointer)
{
	if(modelChangedInstance_ == nullptr) {
		modelChangedInstance_ = &modelChangedStatic_;
	}
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
void AbstractItem::setModelChangedPointerStatic(void (*modelChangedStatic)())
{
	modelChangedStatic_ = modelChangedStatic;
}
