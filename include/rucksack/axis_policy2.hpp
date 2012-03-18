#ifndef RUCKSACK_AXIS_POLICY2_HPP_INCLUDED
#define RUCKSACK_AXIS_POLICY2_HPP_INCLUDED

#include <rucksack/aspect.hpp>
#include <rucksack/axis_policy.hpp>
#include <rucksack/dim.hpp>
#include <rucksack/symbol.hpp>
#include <fcppt/math/dim/object_impl.hpp>


namespace rucksack
{
class axis_policy2
{
public:
	RUCKSACK_SYMBOL explicit
	axis_policy2(
		rucksack::axis_policy const &,
		rucksack::axis_policy const &,
		rucksack::aspect const &);

	RUCKSACK_SYMBOL rucksack::axis_policy const &
	x() const;

	RUCKSACK_SYMBOL rucksack::axis_policy const &
	y() const;

	RUCKSACK_SYMBOL rucksack::axis_policy const &
	operator[](
		rucksack::dim::size_type) const;

	RUCKSACK_SYMBOL rucksack::aspect const &
	aspect() const;
private:
	rucksack::axis_policy x_,y_;
	rucksack::aspect aspect_;
};
}

#endif
