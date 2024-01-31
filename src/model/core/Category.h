#ifndef PAO_PROJECT_CATEGORY_H
#define PAO_PROJECT_CATEGORY_H
#include "AbstractItem.h"
#include "../datagen/DataGenObj.h"
#include "../../utility/datagenerator/RandomDataGenerator.h"
#include <QString>
class Category: public AbstractItem {
public:
	Category();
	Category(QString, QString, DistributionType = UNIFORM);
	~Category();
	QString getUnitMeasure() const;
	void setUnitMeasure(QString unit_measure);
	QJsonObject toJson() const;
	static Category* fromJson(QJsonObject const &);
	int getDistributionType() const;
	Category& operator=(Category const &category);
private:
	QString unit_measure_;
	DistributionType distribution_type_;
};
#endif //PAO_PROJECT_CATEGORY_H
