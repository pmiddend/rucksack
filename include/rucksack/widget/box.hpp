#ifndef RUCKSACK_WIDGET_BOX_HPP_INCLUDED
#define RUCKSACK_WIDGET_BOX_HPP_INCLUDED

#include <rucksack/widget/optional_parent.hpp>
#include <rucksack/widget/base.hpp>
#include <rucksack/alignment.hpp>
#include <rucksack/transient_layout_data.hpp>
#include <rucksack/axis.hpp>
#include <rucksack/aspect.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>

namespace rucksack
{
namespace widget
{
/**
 * The box class behaves just like the Qt box layout. It aligns its children
 * either vertically or horizontally (determined by the "axis" parameter which
 * specifies the "major axis" of alignment; hozirontal alignment has axis::x,
 * vertical has axis::y).
 */
class box
:
	public widget::base
{
FCPPT_NONCOPYABLE(
	box);
public:
	explicit
	box(
		widget::optional_parent const &,
		rucksack::alignment::type const &,
		rucksack::axis::type,
		rucksack::aspect const &);

	// Nothing fancy, just set the stored size (this should NOT cause a relayout
	// immediately)
	void
	size(
		rucksack::dim const &);

	// Nothing fancy, just set the stored position (this should NOT cause a
	// relayout immediately)
	void
	position(
		rucksack::vector const &);

	// Nothing fancy, just return the stored size
	rucksack::dim const
	size() const;

	// Nothing fancy, just return the stored position
	rucksack::vector const
	position() const;

	// We have to calculate/set:
	//
	// 1. The minimum size (for each axis)
	// 2. The preferred size (for each axis)
	// 3. If the widget is expandable (for each axis)
	// 4. Aspect
	//
	// The minimum size for the _major_ axis is easy: We just accumulate the
	// minimum sizes of all the children.
	//
	// The minimum size of the _minor_ axis is equally simple: Take the maximum
	// of all the children's sizes.
	//
	// For the preferred size, we forward to the minimum size if the preferred
	// size is not given. If it _is_ given, we do the same as in the minimum
	// case, just with "preferred" instead of "minimum".
	//
	// Finally, the widget is expandable on each axis if there's at least one
	// widget that's expandable.
	//
	// We just ignore the aspect for now. I have no use case for that, yet.
	//
	// Also note that currently, box widgets always have a preferred size (which
	// might be equal to the minimum size).
	rucksack::axis_policy2 const
	axis_policy() const;

	// This does a lot of stuff, see the code itself.
	void
	relayout();

	~box();
private:
	typedef
	std::map<widget::base*,rucksack::transient_layout_data>
	transient_layout_data_map;

	rucksack::alignment::type const alignment_;
	// We use the axis_ to access the components of either a dim or a vector:
	//
	// v[axis_] = 10;
	//
	// So ideally, the data type for the axis is the data type operator[] takes.
	// This is dim::size_type (or vector::size_type, they're equivalent)
	rucksack::dim::size_type const axis_;
	rucksack::aspect const aspect_;
	rucksack::vector position_;
	rucksack::dim size_;

	// Those just return axis and (1-axis), but are better readable in the code
	rucksack::dim::size_type
	major_axis() const;

	rucksack::dim::size_type
	minor_axis() const;

	void
	relayout_major_axis(
		transient_layout_data_map &);

	void
	relayout_minor_axis(
		transient_layout_data_map &);
};
}
}

#endif
