#include <QList>
#include "DistributionUtility.h"

QVector<QString> DistributionUtility::type_ = QVector<QString>({"Sinusoidale", "Gaussiana", "Uniforme"});

QString DistributionUtility::ToString(DistributionType v) {
    switch (v)
    {
    case SINUSOIDAL:   return "Sinusoidale";
    case GAUSSIAN:   return "Gaussiana";
    case UNIFORM: return "Uniforme";
    default:      return "[Unknown]";
    }
}