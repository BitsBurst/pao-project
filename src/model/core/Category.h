#ifndef PAO_PROJECT_CATEGORY_H
#define PAO_PROJECT_CATEGORY_H
#include "AbstractItem.h"
#include "../datagen/AbstractDataGen.h"
#include <QString>
class Category: public AbstractItem {
	friend QDataStream &operator<<(QDataStream &, const Category &);
	friend QDataStream &operator>>(QDataStream &, Category &);
public:
	Category(void (**)() = nullptr);
	Category(QString, QString, QString, AbstractDataGen* = nullptr, void (**)() = nullptr);
	~Category();
	QString getUnitMeasure();
	void setUnitMeasure(QString unit_measure);
private:
	QString unit_measure_;
	AbstractDataGen* data_gen_;
};
QDataStream &operator<<(QDataStream &, const Category&);
QDataStream &operator>>(QDataStream &, Category &);
#endif //PAO_PROJECT_CATEGORY_H
