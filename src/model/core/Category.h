#ifndef PAO_PROJECT_CATEGORY_H
#define PAO_PROJECT_CATEGORY_H
#include "AbstractItem.h"
#include "../datagen/AbstractDataGen.h"
#include <QString>
class Category: public AbstractItem {
public:
	Category(void (**)() = nullptr);
	Category(QString, QString, AbstractDataGen* = nullptr, void (**)() = nullptr);
	~Category();
	QString getUnitMeasure();
	void setUnitMeasure(QString unit_measure);
	QJsonObject toJson() const;
	static Category fromJson(QJsonObject const &);
private:
	QString unit_measure_;
	AbstractDataGen* data_gen_;
};
#endif //PAO_PROJECT_CATEGORY_H
