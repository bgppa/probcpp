/* Base Distribution abstract class, archetype of all distributions */
#pragma once
#include <random>
#include <vector>


class Distribution {
protected:
	/* The internal RNG generator will inherit in all subclasses,
	   but it is not meant to be modified by the user. */
	std::mt19937 myrng;
public:
	/* Constructor used to setup the seed. The use of explicit prevents
	   accidental syntaxes like Distribution(-1) that might confuse.
	   Remark: std::random_device{}() is basically a wrapper of
	   /dev/urandom; it will generate an uinteger used then as seed for
	   the true rgn, mersenne */
	explicit Distribution(unsigned seed = std::random_device{}())
		: myrng(seed) {}

	/* Distructor must be virtual so to have valid polymorphism */
	virtual ~Distribution(){}

	/* Now: pure virtual methods that all subclasses must implement.
	   [[nodiscard]] will trigger a warning if the user use the function
	   for its side-effect only */
	
	[[nodiscard]] virtual double sample() = 0;
	[[nodiscard]] virtual std::string name() const = 0;

	[[nodiscard]] double empirical_mean(int n = 10'000);
	[[nodiscard]] double empirical_variance(int n = 10'000);
};
