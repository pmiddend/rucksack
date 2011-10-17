#include <rucksack/axis_policy.hpp>

rucksack::axis_policy::axis_policy(
	rucksack::minimum_size const &_minimum_size,
	rucksack::preferred_size const &_preferred_size,
	rucksack::is_expanding const &_is_expanding)
:
	minimum_size_(
		_minimum_size.get()),
	preferred_size_(
		_preferred_size.get()),
	is_expanding_(
		_is_expanding.get())
{
}

rucksack::scalar
rucksack::axis_policy::minimum_size() const
{
	return minimum_size_;
}

rucksack::optional_scalar
rucksack::axis_policy::preferred_size() const
{
	return preferred_size_;
}

bool
rucksack::axis_policy::is_expanding() const
{
	return is_expanding_;
}
