#include <rucksack/widget/base.hpp>
#include <fcppt/optional_impl.hpp>

rucksack::widget::base::base(
	widget::optional_parent const &_parent)
:
	children_()
{
	if(_parent)
		_parent->push_back_child(
			*this);
}

rucksack::widget::base::~base()
{
}

void
rucksack::widget::base::push_back_child(
	base &_child)
{
	children_.push_back(
		_child);
}
