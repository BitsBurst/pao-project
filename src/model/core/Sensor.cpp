#include <QJsonArray>
#include "Sensor.h"
double Sensor::maxDataGenerated = 10000; // max data generated stored in the sensor
double Sensor::generationTimeStatic = 100; // generation time in ms
/*
 * @brief Sensor::Sensor
 * @details Sensor constructor
 * @param name sensor name
 * @param category sensor category
 */
Sensor::Sensor(QString name, Category category):AbstractItem(name), onDataGenerated(), data_(maxDataGenerated), min_range_(0), max_range_(0), category_(category), seed_(QDateTime::currentDateTime().toSecsSinceEpoch()), data_generator_worker_(nullptr),  generationTime(generationTimeStatic)
{

}
/*
 * @brief Sensor::~Sensor
 * @details Sensor destructor
 */
Sensor::~Sensor()
{
	stopDataGeneration();
}
/*
 * @brief Sensor::getMinRange
 * @details get sensor min range
 * @return sensor min range
 */
double Sensor::getMinRange() const
{
	return min_range_;
}
/*
 * @brief Sensor::setMinRange
 * @details set sensor min range
 * @param min_range sensor min range
 */
void Sensor::setMinRange(double min_range)
{
	min_range_ = min_range;
	modelChangedEvent.notifyAsync();
}
/*
 * @brief Sensor::getMaxRange
 * @details get sensor max range
 * @return sensor max range
 */
double Sensor::getMaxRange() const
{
	return max_range_;
}
/*
 * @brief Sensor::setMaxRange
 * @details set sensor max range
 * @param max_range sensor max range
 */
void Sensor::setMaxRange(double max_range)
{
	max_range_ = max_range;
	modelChangedEvent.notifyAsync();
}
/*
 * @brief Sensor::getCategory
 * @details get sensor category
 * @return sensor category
 */
Category Sensor::getCategory() const
{
	return category_;
}
/*
 * @brief Sensor::setCategory
 * @details set sensor category
 * @param category sensor category
 */
void Sensor::setCategory(Category category)
{
	category_ = category;
	modelChangedEvent.notifyAsync();
}
/*
 * @brief Sensor::Sensor
 * @details Sensor constructor
 */
Sensor::Sensor(): AbstractItem(""), onDataGenerated(), data_(maxDataGenerated), min_range_(-5), max_range_(5), category_(Category()), seed_(QDateTime::currentDateTime().toSecsSinceEpoch()), data_generator_worker_(nullptr), generationTime(generationTimeStatic)
{

}
/*
 * @brief Sensor::toJson
 * @details convert sensor to json
 * @return sensor json
 */
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
/*
 * @brief Sensor::fromJson
 * @details convert json to sensor
 * @param object json object
 * @return sensor object
 */
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
/*
 * @brief Sensor::startDataGeneration
 * @details start data generation
 */
void Sensor::startDataGeneration()
{
	if(data_generator_worker_ == nullptr){
		data_generator_worker_ = new DataGeneratorWorker(max_range_, min_range_, seed_, generationTime, category_.getDistributionType());
		data_generator_worker_->newDataEvent.subscribe(std::bind(&Sensor::dataGenerated, this, std::placeholders::_1));
	}
	data_generator_worker_->start();

}
/*
 * @brief Sensor::stopDataGeneration
 * @details stop data generation
 */
void Sensor::stopDataGeneration()
{
	if(data_generator_worker_ == nullptr)
		return;
	data_generator_worker_->newDataEvent.unsubscribe(std::bind(&Sensor::dataGenerated, this, std::placeholders::_1));
	data_generator_worker_->terminate();
	data_generator_worker_->wait();
	delete data_generator_worker_;
	data_generator_worker_ = nullptr;
}
/*
 * @brief Sensor::dataGenerated
 * @details data generated
 * @param obj data generated object
 */
void Sensor::dataGenerated(DataGenObj obj)
{
	//qDebug() << "Data generated" + QString::number(obj.getTimestamp().toSecsSinceEpoch()) + " " + QString::number(obj.getData());
	data_.insertLimited(obj.getTimestamp(), obj.getData());
	onDataGenerated.notify(obj);
}

void Sensor::accept(IConstVisitor& visitor) const
{
    visitor.visit(*this);
}
void Sensor::accept(IVisitor& visitor)
{
    visitor.visit(*this);
}
Sensor::Sensor(const Sensor& obj):AbstractItem(obj), onDataGenerated(), data_(maxDataGenerated), min_range_(obj.min_range_), max_range_(obj.max_range_), category_(obj.category_), seed_(obj.seed_), data_generator_worker_(nullptr), generationTime(obj.generationTime)
{
}
