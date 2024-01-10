#ifndef SMARTSENSORS_RANDOMDATAGENERATOR_H
#define SMARTSENSORS_RANDOMDATAGENERATOR_H

#include <iostream>
#include <vector>
#include <random>

enum DistributionType {
	UNIFORM,
	NORMAL,
	EXPONENTIAL,
	POISSON,
	BINOMIAL,
	GAMMA,
	TRIANGULAR,
	WEIBULL
};

class RandomDataGenerator {
public:
	RandomDataGenerator(int seed);

	void setDistributionType(DistributionType type);

	std::vector<double> generateData(int rangeStart, int rangeEnd, int dataSize);

private:
	std::default_random_engine generator;
	DistributionType distributionType;

	void generateUniformData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
	void generateNormalData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
	void generateExponentialData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
	void generatePoissonData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
	void generateBinomialData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
	void generateGammaData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
	void generateTriangularData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
	void generateWeibullData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data);
};

#endif //SMARTSENSORS_RANDOMDATAGENERATOR_H
