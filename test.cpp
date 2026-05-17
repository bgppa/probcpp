#include "bernoulli.hpp"
#include <vector>
#include <iostream>
#include <cmath>

/* Simple tests will just check mean and variance */

bool testBernoulli(double p)
{
	// fix the seed so to guarantee reproducibility
	unsigned local_seed = 0;
	std::unique_ptr<BernoulliDistribution> ber = 
			std::make_unique<BernoulliDistribution> (p, local_seed);
	double mu = ber->empirical_mean();
	double sigma2 = ber->empirical_variance();
	
	std::cout << "Empirical mean:" << mu; 
	std::cout << " expected: " << ber->theoretical_mean() << std::endl;
	std::cout << "Empirical variance:" << sigma2; 
	std::cout << " expected: " << ber->theoretical_variance() <<std::endl;

	double tol = 0.1; // arbitrary tolerance; TO DO: modify as MC conf int
	if (abs(mu - ber->theoretical_mean()) > tol) return false;
	if (abs(sigma2 - ber->theoretical_variance()) > tol) return false;
	return true;
}


int main() {
	std::cout << "TESTING..." << std::endl;
	std::vector<double> v = {0., 0.1, 0.3, 0.6, 0.9, 1.};
	for (double p : v) {
		if (testBernoulli(p)) {
			std::cout << "...PASS";
		} else {
			std::cout << "...FAIL!";
			std::cout << " --- tests are NOT passed --- ";
			std::cout << std::endl;
			return 1;
		}
		std::cout << std::endl;
	}
	return 0;
}
