#include <rucksack/aspect.hpp>

rucksack::aspect::aspect(
	rucksack::scalar const _x,
	rucksack::scalar const _y)
:
	x_(
		_x),
	y_(
		_y)
{
}

rucksack::scalar
rucksack::aspect::x() const
{
	return x_;
}

rucksack::scalar
rucksack::aspect::y() const
{
	return y_;
}
