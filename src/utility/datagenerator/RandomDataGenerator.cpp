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
		  generator(std::random_device{}()), gaussianDistribution(mean, stddev),
		  uniformDistribution(min, max) {
	srand(time(nullptr));
}
/**
 * @brief RandomDataGenerator::setDistributionType
 * @param type type of the distribution
 */
void CombinedDataGenerator::setDistributionType(DistributionType type) {
	distributionType = type;
}
/**
 * @brief RandomDataGenerator::setSinusoidalParams
 * @param amplitude amplitude of the sinusoidal function
 * @param frequency frequency of the sinusoidal function
 */
void CombinedDataGenerator::setSinusoidalParams(double amplitude, double frequency) {
	distributionType = DistributionType::SINUSOIDAL;
	this->amplitude = amplitude;
	this->frequency = frequency;
}
/**
 * @brief RandomDataGenerator::setGaussianParams
 * @param mean mean of the gaussian distribution
 * @param stddev standard deviation of the gaussian distribution
 */
void CombinedDataGenerator::setGaussianParams(double mean, double stddev) {
	distributionType = DistributionType::GAUSSIAN;
	this->mean = mean;
	this->stddev = stddev;
}
/**
 * @brief RandomDataGenerator::setUniformParams
 * @param min minimum value of the uniform distribution
 * @param max maximum value of the uniform distribution
 */
void CombinedDataGenerator::setUniformParams(double min, double max) {
	distributionType = DistributionType::UNIFORM;
	this->min = min;
	this->max = max;
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
		break;
	case DistributionType::GAUSSIAN:
		dataPoint = gaussianDistribution(generator);
		break;
	case DistributionType::UNIFORM:
		dataPoint = uniformDistribution(generator);
		break;
	default:
		dataPoint = 0.0;
		break;
	}

	++index;
	return dataPoint;
}