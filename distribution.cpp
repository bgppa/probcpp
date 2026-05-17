// Add the mean and variance code to the Distribution abstract class

#include "distribution.hpp"
#include <numeric>				 // needed for std::accumulate

double Distribution::empirical_mean(int n)
{
	/* Classic C-way:
	double sum = 0.;
	for (int i = 0; i < n; ++i)
		{sum += sample();}
	return sum / static_cast<double>(n);
	*/

	/* Traying a more modern C++ style: */
	std::vector<double> samples(static_cast<size_t>(n));
	for (double& elm : samples) {elm = sample();}
	return std::accumulate(samples.begin(), samples.end(), 0.) /
					static_cast<double>(n);
}


double Distribution::empirical_variance(int n)
{
	std::vector<double> samples(static_cast<size_t>(n));

	// first, re-compute the mean of the samples.
	// cannot re-use the method above: I need the explicit samples later
	for (double& v : samples) {v = sample();}

	const double mean =
		std::accumulate(samples.begin(), samples.end(), 0.) /
		static_cast<double>(n);

	// empirical "squares"
	double sq_sum = 0.;
	for (double s : samples)
		sq_sum += (s - mean) * (s - mean);

	// divide by (n-1) for unbiased estimator
	return sq_sum / static_cast<double>(n - 1);
}

