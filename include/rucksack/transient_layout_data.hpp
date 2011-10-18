#ifndef RUCKSACK_TRANSIENT_LAYOUT_DATA_HPP_INCLUDED
#define RUCKSACK_TRANSIENT_LAYOUT_DATA_HPP_INCLUDED

#include <rucksack/vector.hpp>
#include <rucksack/dim.hpp>
#include <rucksack/symbol.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

namespace rucksack
{
class transient_layout_data
{
public:
	RUCKSACK_SYMBOL explicit
	transient_layout_data();

	RUCKSACK_SYMBOL void
	position(
		rucksack::vector const &);

	RUCKSACK_SYMBOL void
	size(
		rucksack::dim const &);

	RUCKSACK_SYMBOL rucksack::vector const &
	position() const;

	RUCKSACK_SYMBOL rucksack::dim const &
	size() const;
private:
	rucksack::vector position_;
	rucksack::dim size_;
};
}

#endif
