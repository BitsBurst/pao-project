#include "Sensor.h"
Sensor::Sensor(QString name, Category category, void (**ptfp)()):AbstractItem(name, ptfp), min_range_(0), max_range_(0), category_(category), seed_(QDateTime::currentDateTime().toSecsSinceEpoch()), data_()
{

}
Sensor::~Sensor()
{
	delete data_generator_worker_;
}
double Sensor::getMinRange()
{
	return min_range_;
}
void Sensor::setMinRange(double min_range)
{
	min_range_ = min_range;
	modelChangedHandler();
}
double Sensor::getMaxRange()
{
	return max_range_;
}
void Sensor::setMaxRange(double max_range)
{
	max_range_ = max_range;
	modelChangedHandler();
}
Category Sensor::getCategory()
{
	return category_;
}
void Sensor::setCategory(Category category)
{
	category_ = category;
	modelChangedHandler();
}
Sensor::Sensor(void (**ptfp)()): AbstractItem("", ptfp), min_range_(0), max_range_(0), category_(Category())
{

}
QJsonObject Sensor::toJson() const
{
	QJsonObject json = AbstractItem::toJson();
	json["min_range"] = min_range_;
	json["max_range"] = max_range_;
	json["category"] = category_.toJson();
	return json;
}
Sensor Sensor::fromJson(const QJsonObject& object)
{
	AbstractItem abs_item = AbstractItem::fromJson(object);
	Sensor sensor;
	sensor.id_ = abs_item.getId();
	sensor.name_ = abs_item.getName();
	if(const QJsonValue& min_range = object["min_range"]; min_range.isDouble())
		sensor.min_range_ = min_range.toDouble();
	if(const QJsonValue& max_range = object["max_range"]; max_range.isDouble())
		sensor.max_range_ = max_range.toDouble();
	if(const QJsonValue& category = object["category"]; category.isObject())
		sensor.category_ = Category::fromJson(category.toObject());
	return sensor;
}
void Sensor::startDataGeneration()
{
	if(data_generator_worker_ == nullptr)
		data_generator_worker_ = new DataGeneratorWorker(category_.getDistributionType(), min_range_, max_range_, seed_);
	data_generator_worker_->start();

}
void Sensor::stopDataGeneration()
{
	data_generator_worker_->exit();
	delete data_generator_worker_;
}
void Sensor::dataGenerated(double v, QDateTime t)
{
	data_.insert(t, v);
	modelChangedHandler();
}
