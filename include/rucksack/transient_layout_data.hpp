#ifndef RUCKSACK_TRANSIENT_LAYOUT_DATA_HPP_INCLUDED
#define RUCKSACK_TRANSIENT_LAYOUT_DATA_HPP_INCLUDED

#include <rucksack/vector.hpp>
#include <rucksack/dim.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

namespace rucksack
{
class transient_layout_data
{
public:
	explicit
	transient_layout_data();

	void
	position(
		rucksack::vector const &);

	void
	size(
		rucksack::dim const &);

	rucksack::vector const &
	position() const;

	rucksack::dim const &
	size() const;
private:
	rucksack::vector position_;
	rucksack::dim size_;
};
}

#endif
