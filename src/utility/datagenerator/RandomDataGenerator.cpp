#include "RandomDataGenerator.h"

CombinedDataGenerator::CombinedDataGenerator()
		: size(300), amplitude(10), frequency(10), mean(0.1), stddev(1.0),
		  min(0.0), max(10.0), index(0), distributionType(DistributionType::UNIFORM),
		  generator(std::random_device{}()), gaussianDistribution(mean, stddev),
		  uniformDistribution(min, max) {
	srand(time(nullptr));
}

void CombinedDataGenerator::setDistributionType(DistributionType type) {
	distributionType = type;
}

void CombinedDataGenerator::setSinusoidalParams(double amplitude, double frequency) {
	distributionType = DistributionType::SINUSOIDAL;
	this->amplitude = amplitude;
	this->frequency = frequency;
}

void CombinedDataGenerator::setGaussianParams(double mean, double stddev) {
	distributionType = DistributionType::GAUSSIAN;
	this->mean = mean;
	this->stddev = stddev;
}

void CombinedDataGenerator::setUniformParams(double min, double max) {
	distributionType = DistributionType::UNIFORM;
	this->min = min;
	this->max = max;
}

void CombinedDataGenerator::setSize(int size) {
	this->size = size;
}

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