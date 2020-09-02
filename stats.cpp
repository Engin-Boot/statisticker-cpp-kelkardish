#include "stats.h"

double computeAverage(const std::vector<double>& passedStats, int n) {
	
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum = sum + passedStats[i];
	}

	return sum / n;
}

double computeMax(const std::vector<double>& passedStats, int n) {
	
	double max = passedStats[0];
	for (int i = 1; i < n; i++) {
		if (max < passedStats[i])
			max = passedStats[i];
 	}
	return max;
}

double computeMin(const std::vector<double>& passedStats, int n) {
	double min = passedStats[0];
	for (int i = 1; i < n; i++) {
		if (min > passedStats[i])
			min = passedStats[i];
	}
	return min;
}

Stats Statistics::ComputeStatistics(const std::vector<double>& passedStats) {

	Stats calculatedStats = { NAN, NAN, NAN };

	int inputSize = passedStats.size();

	if (inputSize == 0) {
		return calculatedStats;
	}
	else {
		calculatedStats.average = computeAverage(passedStats, inputSize);
		calculatedStats.max = computeMax(passedStats, inputSize);
		calculatedStats.min = computeMin(passedStats, inputSize);
	}

	return calculatedStats;

}
