#include "stats.h"
include<cmath>
typedef std::vector<double> vecDouble;

class StatClass
{
private:
	vecDouble stats;
	int statSize;
	void stripNANvalues();
public:
	StatClass(const vecDouble& x) : stats(x) { stripNANvalues(); }
	double computeAverage();
	double computeMax();
	double computeMin();
};


void StatClass::stripNANvalues() {
	statSize = stats.size();
	for (int i = 0; i < statSize; i++) {
		if (std::isnan(stats[i])) {
			stats[i] = 0.0;
		}
	}
}

double StatClass::computeAverage() {
	double sum = 0.0;
	for (int i = 0; i < statSize; i++) {
		sum = sum + stats[i];
	}
	return sum / statSize ;
}

double StatClass::computeMax() {
	double max = stats[0];
	for (int i = 1; i < statSize; i++) {
		if (max < stats[i]) {
			max = stats[i];
		}
	}
	return max;
}

double StatClass::computeMin() {
	double min = stats[0];
	for (int i = 1; i < statSize; i++) {
		if (min > stats[i]) {
			min = stats[i];
		}
	}
	return min;
}

Stats Statistics::ComputeStatistics(const vecDouble& passedStats) {
	Stats computedStats = {NAN, NAN, NAN};

	if (passedStats.size() == 0) {
		return computedStats;
	}

	StatClass* statobj = new StatClass(passedStats);
	
	computedStats.average = statobj->computeAverage();
	computedStats.max = statobj->computeMax();
	computedStats.min = statobj->computeMin();

	return computedStats;
}
