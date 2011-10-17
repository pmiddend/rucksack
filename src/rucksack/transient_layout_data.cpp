#include <rucksack/transient_layout_data.hpp>

rucksack::transient_layout_data::transient_layout_data()
:
	position_(),
	size_()
{
}

void
rucksack::transient_layout_data::position(
	rucksack::vector const &_position)
{
	position_ =
		_position;
}

void
rucksack::transient_layout_data::size(
	rucksack::dim const &_size)
{
	size_ =
		_size;
}

rucksack::vector const &
rucksack::transient_layout_data::position() const
{
	return position_;
}

rucksack::dim const &
rucksack::transient_layout_data::size() const
{
	return size_;
}
