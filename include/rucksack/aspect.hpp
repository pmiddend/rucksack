#ifndef RUCKSACK_ASPECT_HPP_INCLUDED
#define RUCKSACK_ASPECT_HPP_INCLUDED

#include <rucksack/scalar.hpp>

namespace rucksack
{
class aspect
{
public:
	explicit
	aspect(
		rucksack::scalar,
		rucksack::scalar);

	rucksack::scalar
	x() const;

	rucksack::scalar
	y() const;
private:
	rucksack::scalar x_,y_;
};
}

#endif
