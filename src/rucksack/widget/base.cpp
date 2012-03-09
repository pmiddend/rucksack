#include <rucksack/widget/base.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/math/box/basic_impl.hpp>

rucksack::widget::base::~base()
{
	if(parent_)
		parent_->child_destroyed(
			*this);
}

rucksack::widget::base::base(
	rucksack::widget::optional_parent const &_parent)
:
	parent_(
		_parent)
{
}

rucksack::rect const
rucksack::widget::base::area() const
{
	return
		rucksack::rect(
			this->position(),
			this->size());
}

void
rucksack::widget::base::parent(
	rucksack::widget::optional_parent const &_parent)
{
	parent_ = _parent;
}

rucksack::widget::optional_parent const &
rucksack::widget::base::parent() const
{
	return parent_;
}

void
rucksack::widget::base::child_destroyed(
	base &)
{
}
