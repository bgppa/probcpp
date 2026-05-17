#include "bernoulli.hpp"
#include <vector>
#include <iostream>

int main() {
	// Define now an array of Distributions
	std::vector<std::unique_ptr<Distribution>> dists;

	dists.push_back(std::make_unique<BernoulliDistribution>(0.5));

	std::cout << "Ok, defined" << std::endl;


	return 0;
}
