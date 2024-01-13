#include "AbstractItem.h"
void (*AbstractItem::modelChangedStatic_)() = nullptr;
AbstractItem::~AbstractItem()
= default;
QDataStream& operator<<(QDataStream& stream, const AbstractItem& abstract_item)
{
	stream << abstract_item.name_ << abstract_item.id_;
	if(abstract_item.modelChangedInstance_ == nullptr) {
		const_cast<AbstractItem&>(abstract_item).modelChangedInstance_ = &AbstractItem::modelChangedStatic_;
	}
	return stream;
}
QDataStream& operator>>(QDataStream& stream, AbstractItem& abstract_item)
{
	stream >> abstract_item.name_ >> abstract_item.id_;
	if(abstract_item.modelChangedInstance_ == nullptr) {
		abstract_item.modelChangedInstance_ = &AbstractItem::modelChangedStatic_;
	}
	return stream;
}
AbstractItem::AbstractItem(QString id, QString name, void (**modelChangedHandlerPointer)()):id_(id), name_(name), modelChangedInstance_(modelChangedHandlerPointer)
{
	// Note: WARNING: This is a hack. It is not a good idea to emit modelChanged event for every object created. LAVE IT AS IT IS.
	/*if(modelChangedInstance_ == nullptr) {
		modelChangedInstance_ = &modelChangedStatic_;
	}*/
}
QString AbstractItem::getId() const
{
	return id_;
}
void AbstractItem::setId(QString id)
{
	id_ = id;
	modelChangedHandler();
}
QString AbstractItem::getName() const
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
AbstractItem::AbstractItem():id_(""), name_(""), modelChangedInstance_(nullptr)
{

}
