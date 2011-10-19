#include <rucksack/widget/box/child_information.hpp>

rucksack::widget::box::child_information::child_information()
:
	alignment_(),
	size_()
{
}

rucksack::widget::box::child_information::child_information(
	rucksack::alignment::type const _alignment,
	rucksack::dim const &_size)
:
	alignment_(
		_alignment),
	size_(
		_size)
{
}

rucksack::alignment::type
rucksack::widget::box::child_information::alignment() const
{
	return alignment_;
}

rucksack::dim const &
rucksack::widget::box::child_information::size() const
{
	return size_;
}

void
rucksack::widget::box::child_information::size(
	rucksack::dim const &_size)
{
	size_ =
		_size;
}
