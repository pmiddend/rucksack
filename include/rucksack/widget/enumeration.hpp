#ifndef RUCKSACK_WIDGET_ENUMERATION_HPP_INCLUDED
#define RUCKSACK_WIDGET_ENUMERATION_HPP_INCLUDED

#include <rucksack/widget/base.hpp>
#include <rucksack/padding.hpp>
#include <rucksack/aspect.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace rucksack
{
namespace widget
{
/**
 * The enumeration widget starts aligning its child widgets from left to right
 * until there's no more space on the right. Then, it creates a new row and
 * again, aligns from the left to right (like a word processor does with words).
 */
class enumeration
:
	public widget::base
{
FCPPT_NONCOPYABLE(
	enumeration);
public:
	RUCKSACK_SYMBOL
	explicit
	enumeration(
		rucksack::padding const &,
		rucksack::aspect const &);

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

	RUCKSACK_SYMBOL void
	push_back_child(
		widget::base &);

	RUCKSACK_SYMBOL ~enumeration();
private:
	typedef
	std::vector<widget::base*>
	child_information;

	rucksack::scalar const padding_;
	rucksack::aspect const aspect_;
	child_information children_;
	rucksack::vector position_;
	rucksack::dim size_;

	void
	child_destroyed(
		widget::base &);
};
}
}

#endif
