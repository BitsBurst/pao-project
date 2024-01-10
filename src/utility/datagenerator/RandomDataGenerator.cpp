#include "RandomDataGenerator.h"

RandomDataGenerator::RandomDataGenerator(int seed) : generator(seed) {}

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
	case TRIANGULAR:
		generateTriangularData(rangeStart, rangeEnd, dataSize, data);
		break;
	case WEIBULL:
		generateWeibullData(rangeStart, rangeEnd, dataSize, data);
		break;
	default:
		std::cerr << "Tipo di distribuzione non supportato" << std::endl;
	}

	return data;
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

void RandomDataGenerator::generateTriangularData(int rangeStart, int rangeEnd, int dataSize, std::vector<double>& data) {
	std::piecewise_linear_distribution<double> distribution({rangeStart, (rangeStart + rangeEnd) / 2.0, rangeEnd});

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
