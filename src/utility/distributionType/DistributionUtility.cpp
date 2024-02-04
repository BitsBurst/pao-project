#include <QMap>
#include "DistributionUtility.h"
/**
 * @brief Map of distribution type to string
 */
QMap<DistributionType,QString> DistributionUtility::type_ = QMap<DistributionType,QString>({
	{ DistributionType::WAVE_1, "WAVE_1"},
	{ DistributionType::WAVE_2, "WAVE_2"},
	{ DistributionType::WAVE_3, "WAVE_3"},
	{ DistributionType::WAVE_4, "WAVE_4"},
	{ DistributionType::WAVE_5, "WAVE_5"},
	{ DistributionType::SINUSOIDAL, "SINUSOIDAL"},
	{ DistributionType::UNIFORM, "UNIFORM"}
});
/**
 * @brief DistributionUtility::ToString
 * @param v distribution type
 * @return string representation of the distribution type
 */
QString DistributionUtility::ToString(DistributionType v) {
	return type_[v];
}