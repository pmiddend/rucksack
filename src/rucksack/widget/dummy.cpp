#include <rucksack/widget/dummy.hpp>

rucksack::widget::dummy::dummy(
	rucksack::axis_policy2 const &_axis_policy)
:
	widget::base(
		widget::optional_parent()),
	axis_policy_(
		_axis_policy),
	position_(),
	size_()
{
}

void
rucksack::widget::dummy::size(
	rucksack::dim const &_size)
{
	size_ =
		_size;
}

void
rucksack::widget::dummy::position(
	rucksack::vector const &_position)
{
	position_ =
		_position;
}

rucksack::dim const
rucksack::widget::dummy::size() const
{
	return size_;
}

rucksack::vector const
rucksack::widget::dummy::position() const
{
	return position_;
}

rucksack::axis_policy2 const
rucksack::widget::dummy::axis_policy() const
{
	return axis_policy_;
}

void
rucksack::widget::dummy::relayout()
{
}

rucksack::widget::dummy::~dummy()
{
}
