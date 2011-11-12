#ifndef RUCKSACK_WIDGET_DUMMY_HPP_INCLUDED
#define RUCKSACK_WIDGET_DUMMY_HPP_INCLUDED

#include <rucksack/dim.hpp>
#include <rucksack/vector.hpp>
#include <rucksack/widget/base.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

namespace rucksack
{
namespace widget
{
class dummy
:
	public widget::base
{
FCPPT_NONCOPYABLE(
	dummy);
public:
	RUCKSACK_SYMBOL explicit
	dummy(
		rucksack::axis_policy2 const &);

	RUCKSACK_SYMBOL void
	size(
		rucksack::dim const &);

	RUCKSACK_SYMBOL void
	position(
		rucksack::vector const &);

	RUCKSACK_SYMBOL rucksack::dim const
	size() const;

	RUCKSACK_SYMBOL rucksack::vector const
	position() const;

	RUCKSACK_SYMBOL rucksack::axis_policy2 const
	axis_policy() const;

	RUCKSACK_SYMBOL void
	relayout();

	RUCKSACK_SYMBOL
	~dummy();
private:
	rucksack::axis_policy2 const axis_policy_;
	rucksack::vector position_;
	rucksack::dim size_;
};
}
}

#endif
