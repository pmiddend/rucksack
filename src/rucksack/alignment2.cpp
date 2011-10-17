#include <rucksack/alignment2.hpp>

rucksack::alignment2::alignment2(
	alignment::type const _x,
	alignment::type const _y)
:
	x_(
		_x),
	y_(
		_y)
{
}

rucksack::alignment::type
rucksack::alignment2::x() const
{
	return x_;
}

rucksack::alignment::type
rucksack::alignment2::y() const
{
	return y_;
}
