#include "Category.h"
QString Category::getUnitMeasure()
{
	return unit_measure_;
}
void Category::setUnitMeasure(QString unit_measure)
{
	unit_measure_ = unit_measure;
	modelChangedHandler();
}
Category::~Category()
{
}
Category::Category(QString name, QString unit_measure, DistributionType distribution_type, void (**ptfp)()):AbstractItem(name, ptfp), unit_measure_(unit_measure), distribution_type_(distribution_type)
{

}
Category::Category(void (**ptfp)()):AbstractItem("", ptfp), unit_measure_(""), distribution_type_(UNIFORM)
{

}
QJsonObject Category::toJson() const
{
	QJsonObject json = AbstractItem::toJson();
	json["unit_measure"] = unit_measure_;
	return json;
}
Category Category::fromJson(const QJsonObject& obj)
{
	AbstractItem abs_item = AbstractItem::fromJson(obj);
	Category category;
	category.id_ = abs_item.getId();
	category.name_ = abs_item.getName();
	if(const QJsonValue& unit_measure = obj["unit_measure"]; unit_measure.isString())
		category.unit_measure_ = unit_measure.toString();
	return category;
}
int Category::getDistributionType()
{
	return distribution_type_;
}
