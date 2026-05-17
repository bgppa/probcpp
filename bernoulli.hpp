/* Interface for the Bernoulli distribution */
#pragma once
#include "distribution.hpp"
#include <string>

/* The Bernoulli distribution has success (1.0) with
   probability p, failure (0.) with probability 1-p
*/


class BernoulliDistribution : public Distribution {
private:
	double p_;
	std::string name_;

public:
	explicit BernoulliDistribution(double p,
				unsigned seed = std::random_device{}());

	// this was pure virtual in the base class
	[[nodiscard]] double sample() override;
	
	// this was also pure virtual in the base class
	[[nodiscard]] std::string name() const override;

	[[nodiscard]] double theoretical_mean() const {return p_;};
	[[nodiscard]] double theoretical_variance() const {return p_*(1. - p_);};

};
