#ifndef PAO_PROJECT_CATEGORY_H
#define PAO_PROJECT_CATEGORY_H
#include "AbstractItem.h"
#include "../datagen/DataGenObj.h"
#include "../../utility/datagenerator/RandomDataGenerator.h"
#include <QString>
/**
 * @brief The Category class
 * @details This class represents a category of items.
 */
class Category: public AbstractItem {
public:
	Category();
	Category(QString, QString, DistributionType = DistributionType::UNIFORM);
	Category(const Category &);
	~Category();
	QString getUnitMeasure() const;
	void setUnitMeasure(QString unit_measure);
	QJsonObject toJson() const;
	static Category* fromJson(QJsonObject const &);
	DistributionType getDistributionType() const;
	void setDistributionType(DistributionType distribution_type);
	Category& operator=(Category const &category);

    virtual void accept(IConstVisitor& visitor) const;
    virtual void accept(IVisitor& visitor);
private:
	QString unit_measure_;
	DistributionType distribution_type_;
};
#endif //PAO_PROJECT_CATEGORY_H
