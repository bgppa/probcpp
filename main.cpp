#include "bernoulli.hpp"
#include <vector>
#include <iostream>

int main() {
	// Define now an array of Distributions
	std::vector<std::unique_ptr<Distribution>> dists;
	double p1 = 0.5;
	double p2 = 0.8;

	dists.push_back(std::make_unique<BernoulliDistribution>(p1));
	dists.push_back(std::make_unique<BernoulliDistribution>(p2));

	std::cout << "10 coins with " << p1 << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << dists.at(0)->sample() << " ";
	}
	std::cout << std::endl;

	std::cout << "10 coins with " << p2 << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << dists.at(1)->sample() << " ";
	}
	std::cout << std::endl;

	return 0;
}
