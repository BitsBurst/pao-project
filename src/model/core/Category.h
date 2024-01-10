#ifndef PAO_PROJECT_CATEGORY_H
#define PAO_PROJECT_CATEGORY_H
#include "AbstractItem.h"
#include "../datagen/AbstractDataGen.h"
#include "../../utility/datagenerator/RandomDataGenerator.h"
#include <QString>
class Category: public AbstractItem {
public:
	Category(void (**)() = nullptr);
	Category(QString, QString, DistributionType = UNIFORM, void (**)() = nullptr);
	~Category();
	QString getUnitMeasure();
	void setUnitMeasure(QString unit_measure);
	QJsonObject toJson() const;
	static Category fromJson(QJsonObject const &);
	int getDistributionType();
private:
	QString unit_measure_;
	DistributionType distribution_type_;
};
#endif //PAO_PROJECT_CATEGORY_H
