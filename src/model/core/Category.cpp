#include "Category.h"
/**
 * @brief Category::getUnitMeasure
 * @return the unit of measure of the category
 */
QString Category::getUnitMeasure() const
{
	return unit_measure_;
}
/**
 * @brief Category::setUnitMeasure
 * @param unit_measure the new unit of measure of the category
 */
void Category::setUnitMeasure(QString unit_measure)
{
	unit_measure_ = unit_measure;
	modelChangedEvent.notifyAsync();
}
/**
 * @brief Category::~Category
 * @details Destructor
 */
Category::~Category()
{
}
/**
 * @brief Category::Category
 * @details Constructor
 * @param name the name of the category
 * @param unit_measure the unit of measure of the category
 * @param distribution_type the distribution type of the category
 */
Category::Category(QString name, QString unit_measure, DistributionType distribution_type):AbstractItem(name), unit_measure_(unit_measure), distribution_type_(distribution_type)
{

}
/**
 * @brief Category::Category
 * @details Default constructor
 */
Category::Category():AbstractItem(""), unit_measure_(""), distribution_type_(DistributionType::UNIFORM)
{

}
/**
 * @brief Category::toJson
 * @return a QJsonObject representing the category
 */
QJsonObject Category::toJson() const
{
	QJsonObject json = AbstractItem::toJson();
	json["unit_measure"] = unit_measure_;
	json["distribution_type"] = distribution_type_;
	return json;
}
/**
 * @brief Category::fromJson
 * @param obj the QJsonObject representing the category
 * @return a pointer to the category
 */
Category * Category::fromJson(const QJsonObject& obj)
{
	AbstractItem* abs_item = AbstractItem::fromJson(obj);
	Category* category = new Category();
	category->id_ = abs_item->getId();
	category->name_ = abs_item->getName();
	if(const QJsonValue& unit_measure = obj["unit_measure"]; unit_measure.isString())
		category->unit_measure_ = unit_measure.toString();
	if(const QJsonValue& distribution_type = obj["distribution_type"]; distribution_type.isDouble())
		category->distribution_type_ = static_cast<DistributionType>(distribution_type.toInt());
	return category;
}
/**
 * @brief Category::getDistributionType
 * @return the distribution type of the category
 */
DistributionType Category::getDistributionType() const
{
	return distribution_type_;
}
/**
 * @brief Category::operator=
 * @param category the category to copy
 * @return a reference to the category
 */
Category& Category::operator=(const Category& category)
{
	id_ = category.id_;
	name_ = category.name_;
	unit_measure_ = category.unit_measure_;
	distribution_type_ = category.distribution_type_;
	return *this;
}
