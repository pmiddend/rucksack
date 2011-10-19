#include <rucksack/widget/enumeration.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>
#include <fcppt/assert/pre.hpp>

rucksack::widget::enumeration::enumeration(
	rucksack::padding const &_padding,
	rucksack::aspect const &_aspect)
:
	widget::base(
		widget::optional_parent()),
	padding_(
		_padding.get()),
	aspect_(
		_aspect),
	children_(),
	position_(),
	size_()
{
}

void
rucksack::widget::enumeration::size(
	rucksack::dim const &_size)
{
	size_ =
		_size;
}

void
rucksack::widget::enumeration::position(
	rucksack::vector const &_position)
{
	position_ =
		_position;
}

rucksack::dim const
rucksack::widget::enumeration::size() const
{
	return
		size_;
}

rucksack::vector const
rucksack::widget::enumeration::position() const
{
	return
		position_;
}

rucksack::axis_policy2 const
rucksack::widget::enumeration::axis_policy() const
{
	return
		rucksack::axis_policy2(
			rucksack::axis_policy(
				rucksack::minimum_size(
					0),
				rucksack::preferred_size(),
				rucksack::is_expanding(
					true)),
			rucksack::axis_policy(
				rucksack::minimum_size(
					0),
				rucksack::preferred_size(),
				rucksack::is_expanding(
					true)),
			aspect_);
}

void
rucksack::widget::enumeration::relayout()
{
	rucksack::vector current_pos(
		this->position().x(),
		this->position().y() + padding_);

	rucksack::scalar current_row_max_height =
		0;

	for(
		child_information::iterator child_ptr =
			children_.begin();
		child_ptr != children_.end();
		child_ptr++)
	{
		rucksack::dim const preferred_or_minimum(
			(*child_ptr)->axis_policy().x().preferred_size()
			?
				*(*child_ptr)->axis_policy().x().preferred_size()
			:
				(*child_ptr)->axis_policy().x().minimum_size(),
			(*child_ptr)->axis_policy().y().preferred_size()
			?
				*(*child_ptr)->axis_policy().y().preferred_size()
			:
				(*child_ptr)->axis_policy().y().minimum_size());

		// Next line
		if(current_pos.x() + padding_ + preferred_or_minimum.w() > this->position().x() + this->size().w())
		{
			FCPPT_ASSERT_PRE(
				current_pos.y() + preferred_or_minimum.h() <= this->position().y() + this->size().h());

			current_pos.x() =
				this->position().x();

			current_pos.y() +=
				current_row_max_height + padding_;

			current_row_max_height =
				0;
		}

		(*child_ptr)->position(
			rucksack::vector(
				current_pos.x() + padding_,
				current_pos.y()));

		(*child_ptr)->size(
			preferred_or_minimum);

		current_pos.x() +=
			preferred_or_minimum.w() + padding_;

		current_row_max_height =
			std::max(
				current_row_max_height,
				preferred_or_minimum.h());
	}
}

void
rucksack::widget::enumeration::push_back_child(
	widget::base &_child)
{
	children_.push_back(
		&_child);
	_child.parent(
		widget::optional_parent(
			*this));
}

rucksack::widget::enumeration::~enumeration()
{
	for(
		child_information::iterator child_ptr =
			children_.begin();
		child_ptr != children_.end();
		child_ptr++)
		(*child_ptr)->parent(
			widget::optional_parent());
}

void
rucksack::widget::enumeration::child_destroyed(
	widget::base &_child)
{
	child_information::iterator it =
		std::find(
			children_.begin(),
			children_.end(),
			&_child);

	FCPPT_ASSERT_PRE(
		it != children_.end());

	children_.erase(
		it);
}
