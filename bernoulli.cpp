/* To define:
	- constructor
	- sample
	- name
*/

#include "bernoulli.hpp"
#include <iostream>
#include <random>		// used for std::uniform_real_distribution
#include <sstream>

// Constructor
BernoulliDistribution::BernoulliDistribution(double p, unsigned seed)
: Distribution(seed)
{
	if (p < 0. ) {
		std::cerr << "Warning: p < 0. Setting to 0." << std::endl;	
		p = 0;
	} else if (p > 1.) {
		std::cerr << "Warning: p > 1. Setting to 1." << std::endl;	
		p = 1;
	}
	p_ = p;
	// the seed parameter is used for the Distribution constructor
	// important to initialize the internal myrng
	// use a string stream to store distribution name (similar to sprintf)
	std::ostringstream oss;
	oss << "Bernoulli (p = " << p_ << ")";
	name_ = oss.str();
}


// sample
double BernoulliDistribution::sample()
{
	// Generate a random uniform in [0,1]
	// return 1 if <= p), 0 otherwise
	// need to use the C++ uniform distribution, already provided
	std::uniform_real_distribution<> dist(0., 1.);
	// myrng is the generator provided in Distribution
	return (dist(myrng) <= p_) ? 1.0 : 0.;
}


std::string BernoulliDistribution::name() const
{
	return name_;
}
