#ifndef SMARTSENSORS_DISTRIBUTIONUTILITY_H
#define SMARTSENSORS_DISTRIBUTIONUTILITY_H

#include <QString>

enum DistributionType {
	WAVE_1,
	WAVE_2,
	WAVE_3,
	WAVE_4,
	WAVE_5,
	SINUSOIDAL,
	UNIFORM
};

class DistributionUtility {
private:
public:
    static QString ToString(DistributionType type);
    static QMap<DistributionType,QString> type_;
};

#endif //SMARTSENSORS_DISTRIBUTIONUTILITY_H
