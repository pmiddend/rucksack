#ifndef RUCKSACK_SIZE_POLICY2_HPP_INCLUDED
#define RUCKSACK_SIZE_POLICY2_HPP_INCLUDED

#include <rucksack/size_policy_field.hpp>
#include <rucksack/aspect.hpp>
#include <fcppt/container/bitfield/basic_impl.hpp>

namespace rucksack
{
class size_policy2
{
public:
	explicit
	size_policy2(
		rucksack::size_policy_field const &,
		rucksack::size_policy_field const &,
		rucksack::aspect const &);

	rucksack::size_policy_field const &
	x() const;

	rucksack::size_policy_field const &
	y() const;

	rucksack::aspect const &
	aspect() const;
private:
	rucksack::size_policy_field x_,y_;
	rucksack::aspect aspect_;
};
}

#endif
