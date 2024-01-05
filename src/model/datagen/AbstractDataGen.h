#ifndef PAO_PROJECT_ABSTRACTDATAGEN_H
#define PAO_PROJECT_ABSTRACTDATAGEN_H
#include <QString>
class AbstractDataGen {
	QString id_;
public:
	virtual ~AbstractDataGen();
	virtual double generateData() = 0;
};

#endif //PAO_PROJECT_ABSTRACTDATAGEN_H
