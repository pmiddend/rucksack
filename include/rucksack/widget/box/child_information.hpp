#ifndef RUCKSACK_WIDGET_BOX_CHILD_INFORMATION_HPP_INCLUDED
#define RUCKSACK_WIDGET_BOX_CHILD_INFORMATION_HPP_INCLUDED

#include <rucksack/alignment.hpp>
#include <rucksack/dim.hpp>
#include <fcppt/math/dim/object_impl.hpp>

namespace rucksack
{
namespace widget
{
namespace box
{
/**
 * This is a utility class which holds all the information needed for a child.
 * It's intentionally not supplied with SYMBOLs because it's not part of the
 * interface the user sees.
 */
class child_information
{
public:
	explicit
	child_information();

	explicit
	child_information(
		rucksack::alignment::type,
		rucksack::dim const &);

	rucksack::alignment::type
	alignment() const;

	rucksack::dim const &
	size() const;

	void
	size(
		rucksack::dim const &);
private:
	rucksack::alignment::type alignment_;
	rucksack::dim size_;
};
}
}
}

#endif
