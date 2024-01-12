#include "RandomDataGenerator.h"
#include "../logger/Logger.h"

RandomDataGenerator::RandomDataGenerator(int seed) : generator(seed), distributionType(NORMAL) {}

void RandomDataGenerator::setDistributionType(DistributionType type) {
	distributionType = type;
}

std::vector<double> RandomDataGenerator::generateData(int rangeStart, int rangeEnd, int dataSize) {
	std::vector<double> data;

	switch (distributionType) {
	case UNIFORM:
		generateUniformData(rangeStart, rangeEnd, dataSize, data);
		break;
	case NORMAL:
		generateNormalData(rangeStart, rangeEnd, dataSize, data);
		break;
	case EXPONENTIAL:
		generateExponentialData(rangeStart, rangeEnd, dataSize, data);
		break;
	case POISSON:
		generatePoissonData(rangeStart, rangeEnd, dataSize, data);
		break;
	case BINOMIAL:
		generateBinomialData(rangeStart, rangeEnd, dataSize, data);
		break;
	case GAMMA:
		generateGammaData(rangeStart, rangeEnd, dataSize, data);
		break;
	case WEIBULL:
		generateWeibullData(rangeStart, rangeEnd, dataSize, data);
		break;
	case SINUSOIDAL:
		generateWeibullData(rangeStart, rangeEnd, dataSize, data);
		break;
	default:
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, "Invalid distribution type");
	}

	return data;
}
void RandomDataGenerator::generateSinusoidalData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	double amplitude = (rangeEnd - rangeStart) / 2.0;
	double frequency = 0.1;

	for (int i = 0; i < dataSize; ++i) {
		double x = rangeStart + i * (rangeEnd - rangeStart) / (dataSize - 1);
		double y = amplitude * sin(2 * M_PI * frequency * x);
		data.push_back(y);
	}
}
void RandomDataGenerator::generateUniformData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	std::uniform_real_distribution<double> distribution(rangeStart, rangeEnd);

	for (int i = 0; i < dataSize; ++i) {
		data.push_back(distribution(generator));
	}
}

void RandomDataGenerator::generateNormalData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	double mean = (rangeStart + rangeEnd) / 2.0;
	double stddev = (rangeEnd - rangeStart) / 4.0;

	std::normal_distribution<double> distribution(mean, stddev);

	for (int i = 0; i < dataSize; ++i) {
		data.push_back(distribution(generator));
	}
}

void RandomDataGenerator::generateExponentialData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	double lambda = 1.0 / ((rangeEnd - rangeStart) / 2.0);

	std::exponential_distribution<double> distribution(lambda);

	for (int i = 0; i < dataSize; ++i) {
		data.push_back(rangeStart + distribution(generator));
	}
}

void RandomDataGenerator::generatePoissonData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	double mean = (rangeStart + rangeEnd) / 2.0;

	std::poisson_distribution<int> distribution(mean);

	for (int i = 0; i < dataSize; ++i) {
		data.push_back(distribution(generator));
	}
}

void RandomDataGenerator::generateBinomialData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	int trials = 10;
	double probability = 0.5;

	std::binomial_distribution<int> distribution(trials, probability);

	for (int i = 0; i < dataSize; ++i) {
		data.push_back(distribution(generator));
	}
}

void RandomDataGenerator::generateGammaData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	double alpha = 2.0;
	double beta = 1.5;

	std::gamma_distribution<double> distribution(alpha, beta);

	for (int i = 0; i < dataSize; ++i) {
		data.push_back(distribution(generator));
	}
}

void RandomDataGenerator::generateWeibullData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	double alpha = 1.5;
	double beta = 2.0;

	std::weibull_distribution<double> distribution(alpha, beta);

	for (int i = 0; i < dataSize; ++i) {
		data.push_back(rangeStart + distribution(generator));
	}
}
// Aggiungi altre funzioni di generazione per altre distribuzioni se necessario
