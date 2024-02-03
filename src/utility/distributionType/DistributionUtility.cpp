#include "DistributionUtility.h"


QString DistributionUtility::ToString(DistributionType v) {
    switch (v)
    {
    case SINUSOIDAL:   return "Sinusoidale";
    case GAUSSIAN:   return "Gaussiana";
    case UNIFORM: return "Uniforma";
    default:      return "[Unknown]";
    }
}