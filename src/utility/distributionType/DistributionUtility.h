#ifndef SMARTSENSORS_DISTRIBUTIONUTILITY_H
#define SMARTSENSORS_DISTRIBUTIONUTILITY_H

#include <QString>
/**
 * @brief Enum to represent the distribution type
 */
enum DistributionType {
	WAVE_1,
	WAVE_2,
	WAVE_3,
	WAVE_4,
	WAVE_5,
	SINUSOIDAL,
	UNIFORM
};
/**
 * @brief Class to convert distribution type to string
 */
class DistributionUtility {
private:
public:
    static QString ToString(DistributionType type);
    static QMap<DistributionType,QString> type_;
};

#endif //SMARTSENSORS_DISTRIBUTIONUTILITY_H
