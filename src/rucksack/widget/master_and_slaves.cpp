#include <rucksack/widget/master_and_slaves.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/clog.hpp>


rucksack::widget::master_and_slaves::master_and_slaves(
	rucksack::padding const &_padding)
:
	widget::base(
		widget::optional_parent()),
	surrounding_box_(
		rucksack::axis::x,
		rucksack::aspect(
			1,
			1)),
	master_pane_(
		0),
	enumeration_(
		_padding,
		rucksack::aspect(
			1,
			1)),
	position_(),
	size_()
{
	surrounding_box_.push_back_child(
		enumeration_,
		rucksack::alignment::center);
}

void
rucksack::widget::master_and_slaves::size(
	rucksack::dim const &_size)
{
	size_ =
		_size;
}

void
rucksack::widget::master_and_slaves::position(
	rucksack::vector const &_position)
{
	position_ =
		_position;
}

rucksack::dim const
rucksack::widget::master_and_slaves::size() const
{
	return
		size_;
}

rucksack::vector const
rucksack::widget::master_and_slaves::position() const
{
	return
		position_;
}

rucksack::axis_policy2 const
rucksack::widget::master_and_slaves::axis_policy() const
{
	return
		rucksack::axis_policy2(
			rucksack::axis_policy(
				rucksack::minimum_size(
					!master_pane_
					?
						0
					:
						master_pane_->axis_policy().x().minimum_size()),
				rucksack::preferred_size(
					rucksack::optional_scalar()),
				rucksack::is_expanding(
					true)),
			rucksack::axis_policy(
				rucksack::minimum_size(
					!master_pane_
					?
						0
					:
						master_pane_->axis_policy().y().minimum_size()),
				rucksack::preferred_size(
					rucksack::optional_scalar()),
				rucksack::is_expanding(
					true)),
			rucksack::aspect(
				1,
				1));
}

void
rucksack::widget::master_and_slaves::relayout()
{
	surrounding_box_.position(
		this->position());
	surrounding_box_.size(
		this->size());
	surrounding_box_.relayout();
}

void
rucksack::widget::master_and_slaves::master_pane(
	widget::base &_master_pane)
{
	if(master_pane_)
		surrounding_box_.pop_front_child();
	surrounding_box_.push_front_child(
		_master_pane,
		rucksack::alignment::center);
	master_pane_ =
		&_master_pane;
}

void
rucksack::widget::master_and_slaves::push_back_child(
	widget::base &_child)
{
	enumeration_.push_back_child(
		_child);
}

rucksack::widget::master_and_slaves::~master_and_slaves()
{
}
