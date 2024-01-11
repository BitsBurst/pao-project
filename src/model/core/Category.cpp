#include "Category.h"
QString Category::getUnitMeasure()
{
	return unit_measure_;
}
void Category::setUnitMeasure(QString unit_measure)
{
	unit_measure_ = unit_measure;
	modelChangedEvent.notifyAsync();
}
Category::~Category()
{
}
Category::Category(QString name, QString unit_measure, DistributionType distribution_type):AbstractItem(name), unit_measure_(unit_measure), distribution_type_(distribution_type)
{

}
Category::Category():AbstractItem(""), unit_measure_(""), distribution_type_(UNIFORM)
{

}
QJsonObject Category::toJson() const
{
	QJsonObject json = AbstractItem::toJson();
	json["unit_measure"] = unit_measure_;
	return json;
}
Category * Category::fromJson(const QJsonObject& obj)
{
	AbstractItem* abs_item = AbstractItem::fromJson(obj);
	Category* category = new Category();
	category->id_ = abs_item->getId();
	category->name_ = abs_item->getName();
	if(const QJsonValue& unit_measure = obj["unit_measure"]; unit_measure.isString())
		category->unit_measure_ = unit_measure.toString();
	return category;
}
int Category::getDistributionType()
{
	return distribution_type_;
}
Category& Category::operator=(const Category& category)
{
	id_ = category.id_;
	name_ = category.name_;
	unit_measure_ = category.unit_measure_;
	distribution_type_ = category.distribution_type_;
	return *this;
}
