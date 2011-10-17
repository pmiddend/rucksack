#include <rucksack/size_policy2.hpp>

rucksack::size_policy2::size_policy2(
	rucksack::size_policy_field const &_x,
	rucksack::size_policy_field const &_y,
	rucksack::aspect const &_aspect)
:
	x_(
		_x),
	y_(
		_y),
	aspect_(
		_aspect)
{
}

rucksack::size_policy_field const &
rucksack::size_policy2::x() const
{
	return x_;
}

rucksack::size_policy_field const &
rucksack::size_policy2::y() const
{
	return y_;
}

rucksack::aspect const &
rucksack::size_policy2::aspect() const
{
	return aspect_;
}
