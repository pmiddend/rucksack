#ifndef RUCKSACK_ASPECT_HPP_INCLUDED
#define RUCKSACK_ASPECT_HPP_INCLUDED

#include <rucksack/scalar.hpp>
#include <rucksack/symbol.hpp>

namespace rucksack
{
class aspect
{
public:
	RUCKSACK_SYMBOL explicit
	aspect(
		rucksack::scalar,
		rucksack::scalar);

	RUCKSACK_SYMBOL rucksack::scalar
	x() const;

	RUCKSACK_SYMBOL rucksack::scalar
	y() const;
private:
	rucksack::scalar x_,y_;
};
}

#endif
