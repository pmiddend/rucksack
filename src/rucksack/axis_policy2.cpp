#include <rucksack/axis_policy2.hpp>

rucksack::axis_policy2::axis_policy2(
	rucksack::axis_policy const &_x,
	rucksack::axis_policy const &_y,
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

rucksack::axis_policy const &
rucksack::axis_policy2::x() const
{
	return x_;
}

rucksack::axis_policy const &
rucksack::axis_policy2::y() const
{
	return y_;
}

rucksack::axis_policy const &
rucksack::axis_policy2::operator[](
	rucksack::dim::size_type const i) const
{
	return i == 0 ? x_ : y_;
}

rucksack::aspect const &
rucksack::axis_policy2::aspect() const
{
	return aspect_;
}
