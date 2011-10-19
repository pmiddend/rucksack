#ifndef RUCKSACK_WIDGET_MASTER_AND_SLAVES_HPP_INCLUDED
#define RUCKSACK_WIDGET_MASTER_AND_SLAVES_HPP_INCLUDED

#include <rucksack/widget/base.hpp>
#include <rucksack/widget/enumeration.hpp>
#include <rucksack/widget/box/base.hpp>
#include <rucksack/padding.hpp>
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
 * The master and slaves widget is a pretty "special" one. Chances are you
 * don't need it.
 *
 * The widget has a "master widget" and multiple "subwidgets". The master
 * widget is displayed in a column on the left, the subwidgets are displayed on the right
 */
class RUCKSACK_CLASS_SYMBOL master_and_slaves
:
	public widget::base
{
FCPPT_NONCOPYABLE(
	master_and_slaves);
public:
	RUCKSACK_SYMBOL explicit
	master_and_slaves(
		rucksack::padding const &);

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
	master_pane(
		widget::base &);

	RUCKSACK_SYMBOL void
	push_back_child(
		widget::base &);

	RUCKSACK_SYMBOL ~master_and_slaves();
private:
	widget::box::base surrounding_box_;
	widget::base *master_pane_;
	widget::enumeration enumeration_;
	rucksack::vector position_;
	rucksack::dim size_;
};
}
}

#endif
