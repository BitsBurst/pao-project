#include "Category.h"
QString Category::getUnitMeasure()
{
	return unit_measure_;
}
void Category::setUnitMeasure(QString unit_measure)
{
	unit_measure_ = unit_measure;
	modelChangedHandler();
}
Category::~Category()
{
}
Category::Category(QString id, QString name, QString unit_measure, AbstractDataGen* data_gen, void (**ptfp)()):AbstractItem(id, name, ptfp), unit_measure_(unit_measure), data_gen_(data_gen)
{

}
Category::Category(void (**ptfp)()):AbstractItem("", "", ptfp), unit_measure_(""), data_gen_(nullptr)
{

}
QDataStream& operator<<(QDataStream& stream, const Category& category)
{
	stream << dynamic_cast<const AbstractItem&>(category) << category.unit_measure_;
	return stream;
}
QDataStream& operator>>(QDataStream& stream, Category& category)
{
	stream >> dynamic_cast<AbstractItem&>(category) >> category.unit_measure_;
	return stream;
}
