#ifndef SMARTSENSORS_RANDOMDATAGENERATOR_H
#define SMARTSENSORS_RANDOMDATAGENERATOR_H
#include <iostream>
#include <vector>
#include <random>
#include <random>
#include <cmath>
#include <ctime>
#include <QString>
#include "../distributionType/DistributionUtility.h"

/**
 * @brief Class that generates random data
 * @details This class generates random data based on the distribution type set
 */
class CombinedDataGenerator {
private:
	int size;
	double amplitude;
	double frequency;
	double mean;
	double stddev;
	double min;
	double max;
	double minRange;
	double maxRange;
	int index;
	DistributionType distributionType;

	std::mt19937 generator;
	std::uniform_real_distribution<double> uniformDistribution;

public:
	CombinedDataGenerator();

	void setDistributionType(DistributionType type);

	void setMinMaxValue(double min, double max);

	void setSize(int size);

	double generateData();
};

#endif //SMARTSENSORS_RANDOMDATAGENERATOR_H
