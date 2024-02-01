#include "AbstractItem.h"
#include "../exception/NormalException.h"

/**
 * @brief AbstractItem::~AbstractItem
 * @details Destructor for the AbstractItem class.
 */
AbstractItem::~AbstractItem()
= default;
/**
 * @brief AbstractItem::AbstractItem
 * @param name
 * @details Constructor for the AbstractItem class.
 */
AbstractItem::AbstractItem(QString name):id_(QUuid::createUuid().toString()), name_(name), description_("")
{
}
/**
 * @brief AbstractItem::getId
 * @return
 * @details Getter for the id_ attribute.
 */
QString AbstractItem::getId()
const {
	return id_;
}
/**
 * @brief AbstractItem::setId
 * @param id
 * @details Setter for the id_ attribute.
 */
void AbstractItem::setId(QString id)
{
	id_ = id;
	modelChangedHandler();
}
/**
 * @brief AbstractItem::getName
 * @return
 * @details Getter for the name_ attribute.
 */
QString AbstractItem::getName()
const {
	return name_;
}
/**
 * @brief AbstractItem::setName
 * @param name
 * @details Setter for the name_ attribute.
 */
void AbstractItem::setName(QString name)
{
	name_ = name;
	modelChangedHandler();
}
/**
 * @brief AbstractItem::getDescription
 * @return
 * @details Getter for the description_ attribute.
 */
QString AbstractItem::getDescription() const
{
	return description_;
}
/**
 * @brief AbstractItem::setDescription
 * @param description
 * @details Setter for the description_ attribute.
 */
void AbstractItem::setDescription(QString description)
{
	description_ = description;
	modelChangedHandler();
}

/**
 * @brief AbstractItem::modelChangedHandler
 * @details Handler for the modelChangedEvent.
 */
void AbstractItem::modelChangedHandler()
{
	modelChangedEvent.notifyAsync();
}
/**
 * @brief AbstractItem::toJson
 * @return
 * @details This method returns a QJsonObject containing the attributes of the AbstractItem.
 */
AbstractItem::AbstractItem():id_(QUuid::createUuid().toString()), name_(""), description_("")
{

}
/**
 * @brief AbstractItem::fromJson
 * @param object
 * @return
 * @details This method returns a pointer to an AbstractItem object built from the QJsonObject passed as parameter.
 */
QJsonObject AbstractItem::toJson() const
{
	QJsonObject json;
	json["id"] = id_;
	json["name"] = name_;
	json["description"] = description_;
	return json;
}
/**
 * @brief AbstractItem::fromJson
 * @param object
 * @return
 * @details This method returns a pointer to an AbstractItem object built from the QJsonObject passed as parameter.
 */
AbstractItem * AbstractItem::fromJson(const QJsonObject& object)
{
	AbstractItem * abstract_item = new AbstractItem();
	if (const QJsonValue v = object["id"]; v.isString())
		abstract_item->id_ = object["id"].toString();
	if (const QJsonValue v = object["name"]; v.isString())
		abstract_item->name_ = object["name"].toString();
	if (const QJsonValue v = object["description"]; v.isString())
		abstract_item->description_ = object["description"].toString();
	return abstract_item;
}
/**
 * @brief AbstractItem::AbstractItem
 * @param abstract_item
 * @details Copy constructor for the AbstractItem class.
 */
AbstractItem::AbstractItem(const AbstractItem& abstract_item)
{
	id_ = abstract_item.id_;
	name_ = abstract_item.name_;
	description_ = abstract_item.description_;
}

void AbstractItem::accept(IConstVisitor& visitor) const {
    throw NormalException("Unable to set editor data.");
}

void AbstractItem::accept(IVisitor& visitor) {
    throw NormalException("Unable to set editor data.");
}
