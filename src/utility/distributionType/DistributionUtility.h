#ifndef SMARTSENSORS_DISTRIBUTIONUTILITY_H
#define SMARTSENSORS_DISTRIBUTIONUTILITY_H

#include <QString>

enum DistributionType { SINUSOIDAL, GAUSSIAN, UNIFORM };

class DistributionUtility {
private:
public:
    static QString ToString(DistributionType type);
};

#endif //SMARTSENSORS_DISTRIBUTIONUTILITY_H
