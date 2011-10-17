#ifndef RUCKSACK_SIZE_POLICY_FIELD_HPP_INCLUDED
#define RUCKSACK_SIZE_POLICY_FIELD_HPP_INCLUDED

#include <rucksack/size_policy.hpp>
#include <fcppt/container/bitfield/basic_fwd.hpp>

namespace rucksack
{
typedef
fcppt::container::bitfield::basic<rucksack::size_policy::type,rucksack::size_policy::size>
size_policy_field;
}

#endif
