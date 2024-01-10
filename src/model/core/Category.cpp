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
Category::Category(QString name, QString unit_measure, AbstractDataGen* data_gen, void (**ptfp)()):AbstractItem(name, ptfp), unit_measure_(unit_measure), data_gen_(data_gen)
{

}
Category::Category(void (**ptfp)()):AbstractItem("", ptfp), unit_measure_(""), data_gen_(nullptr)
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
