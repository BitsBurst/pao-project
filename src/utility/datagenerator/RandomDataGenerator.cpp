#include "RandomDataGenerator.h"

/**
 * @brief RandomDataGenerator::RandomDataGenerator
 * @param size size of the data to generate
 * @param amplitude amplitude of the sinusoidal function
 * @param frequency frequency of the sinusoidal function
 * @param mean mean of the gaussian distribution
 * @param stddev standard deviation of the gaussian distribution
 * @param min minimum value of the uniform distribution
 * @param max maximum value of the uniform distribution
 */
CombinedDataGenerator::CombinedDataGenerator()
		: size(300), amplitude(10), frequency(10), mean(0.1), stddev(1.0),
		  min(0.0), max(10.0), index(0), distributionType(DistributionType::UNIFORM),
		  generator(std::random_device{}()),
		  uniformDistribution(min, max) {
	srand(time(nullptr));
}
/**
 * @brief RandomDataGenerator::setMinMaxValue
 * @param min minimum value of the data
 * @param max maximum value of the data
 */
void CombinedDataGenerator::setMinMaxValue(double min, double max) {
	this->minRange = min;
	this->maxRange = max;
}
/**
 * @brief RandomDataGenerator::setDistributionType
 * @param type distribution type
 */
void CombinedDataGenerator::setDistributionType(DistributionType type) {
	distributionType = type;
}
/**
 * @brief RandomDataGenerator::setSize
 * @param size size of the data to generate
 */
void CombinedDataGenerator::setSize(int size) {
	this->size = size;
}
/**
 * @brief RandomDataGenerator::generateData
 * Generate a data point according to the distribution type
 * @return a data point
 */
double CombinedDataGenerator::generateData() {
	if (index >= size){
		index = 0;
		return 0.0;
	}
	double dataPoint;
	switch (distributionType) {
	case DistributionType::SINUSOIDAL:
		dataPoint = amplitude * sin(2 * M_PI * frequency * index / size) + (rand() % 100) / 100.0;
		dataPoint = (dataPoint + 10) / 20 * (maxRange- minRange) + minRange;
		break;
	case DistributionType::WAVE_1:
		dataPoint = amplitude * sin(2 * M_PI * frequency * index / size) * cos(M_PI * frequency * index / size) + (rand() % 100) / 100.0;
		dataPoint = (dataPoint + 10) / 20 * (maxRange- minRange) + minRange;
		break;
	case DistributionType::WAVE_2:
		dataPoint = amplitude * sin(4 * M_PI * frequency * index / size) * cos(M_PI * frequency * index / size) + (rand() % 100) / 100.0;
		dataPoint = (dataPoint + 10) / 20 * (maxRange- minRange) + minRange;
		break;
	case DistributionType::WAVE_3:
		dataPoint = amplitude * sin(2 * M_PI * frequency * index / size) * cos(10 * M_PI * frequency * index / size) + (rand() % 100) / 100.0;
		dataPoint = (dataPoint + 10) / 20 * (maxRange- minRange) + minRange;
		break;
	case DistributionType::WAVE_4:
		dataPoint = amplitude * sin(2 * M_PI * frequency * index / size) * cos(20 * M_PI * frequency * index / size) + (rand() % 100) / 100.0;
		dataPoint = (dataPoint + 10) / 20 * (maxRange- minRange) + minRange;
		break;
	case DistributionType::WAVE_5:
		dataPoint = amplitude * sin(5 * M_PI * frequency * index / size) * cos(20 * M_PI * frequency * index / size) + (rand() % 100) / 100.0;
		dataPoint = (dataPoint + 10) / 20 * (maxRange- minRange) + minRange;
		break;
	case DistributionType::UNIFORM:
		dataPoint = uniformDistribution(generator);
		dataPoint = (dataPoint) / 10 * (maxRange- minRange) + minRange;
		break;
	default:
		dataPoint = 0.0;
		break;
	}

	++index;
	return dataPoint;
}