#ifndef RUCKSACK_AXIS_POLICY_HPP_INCLUDED
#define RUCKSACK_AXIS_POLICY_HPP_INCLUDED

#include <rucksack/minimum_size.hpp>
#include <rucksack/preferred_size.hpp>
#include <rucksack/is_expanding.hpp>
#include <fcppt/optional_impl.hpp>

namespace rucksack
{
class axis_policy
{
public:
	explicit
	axis_policy(
		rucksack::minimum_size const &,
		rucksack::preferred_size const &,
		rucksack::is_expanding const &);

	rucksack::scalar
	minimum_size() const;

	rucksack::optional_scalar
	preferred_size() const;

	bool
	is_expanding() const;
private:
	rucksack::scalar minimum_size_;
	rucksack::optional_scalar preferred_size_;
	bool is_expanding_;
};
}

#endif
