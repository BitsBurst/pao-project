#include <QJsonArray>
#include "Sensor.h"
double Sensor::maxDataGenerated = 10000;
double Sensor::generationTimeStatic = 50;
Sensor::Sensor(QString name, Category category):AbstractItem(name), min_range_(0), max_range_(0), category_(category), seed_(QDateTime::currentDateTime().toSecsSinceEpoch()), data_(maxDataGenerated), data_generator_worker_(nullptr), generationTime(generationTimeStatic)
{

}
Sensor::~Sensor()
{
}
double Sensor::getMinRange() const
{
	return min_range_;
}
void Sensor::setMinRange(double min_range)
{
	min_range_ = min_range;
	modelChangedEvent.notifyAsync();
}
double Sensor::getMaxRange() const
{
	return max_range_;
}
void Sensor::setMaxRange(double max_range)
{
	max_range_ = max_range;
	modelChangedEvent.notifyAsync();
}
Category Sensor::getCategory() const
{
	return category_;
}
void Sensor::setCategory(Category category)
{
	category_ = category;
	modelChangedEvent.notifyAsync();
}
Sensor::Sensor(): AbstractItem(""), min_range_(0), max_range_(0), category_(Category()), seed_(QDateTime::currentDateTime().toSecsSinceEpoch()), data_(maxDataGenerated), data_generator_worker_(nullptr), generationTime(generationTimeStatic)
{

}
QJsonObject Sensor::toJson() const
{
	QJsonObject json = AbstractItem::toJson();
	json["min_range"] = min_range_;
	json["max_range"] = max_range_;
	json["category"] = category_.toJson();
	json["seed"] = seed_;
	json["generation_time"] = generationTime;
	return json;
}
Sensor* Sensor::fromJson(const QJsonObject& object)
{
	AbstractItem * abs_item = AbstractItem::fromJson(object);
	Sensor* sensor = new Sensor();
	sensor->id_ = abs_item->getId();
	sensor->name_ = abs_item->getName();
	if(const QJsonValue& min_range = object["min_range"]; min_range.isDouble())
		sensor->min_range_ = min_range.toDouble();
	if(const QJsonValue& max_range = object["max_range"]; max_range.isDouble())
		sensor->max_range_ = max_range.toDouble();
	if(const QJsonValue& category = object["category"]; category.isObject())
		sensor->category_ = *Category::fromJson(category.toObject());
	if(const QJsonValue& seed = object["seed"]; seed.isDouble())
		sensor->seed_ = seed.toDouble();
	if(const QJsonValue& generation_time = object["generation_time"]; generation_time.isDouble())
		sensor->generationTime = generation_time.toDouble();
	return sensor;
}
void Sensor::startDataGeneration()
{
	if(data_generator_worker_ == nullptr){
		data_generator_worker_ = new DataGeneratorWorker(max_range_, min_range_, seed_, generationTime,
				static_cast<DistributionType>(category_.getDistributionType()));
		data_generator_worker_->newDataEvent.subscribe(std::bind(&Sensor::dataGenerated, this, std::placeholders::_1));
	}
	data_generator_worker_->start();

}
void Sensor::stopDataGeneration()
{
	data_generator_worker_->exit();
	delete data_generator_worker_;
}
void Sensor::dataGenerated(DataGenObj obj)
{
	qDebug() << "Data generated" + QString::number(obj.getTimestamp().toSecsSinceEpoch()) + " " + QString::number(obj.getData());
	data_.insertLimited(obj.getTimestamp(), obj.getData());
	onDataGenerated.notifyAsync();
}
