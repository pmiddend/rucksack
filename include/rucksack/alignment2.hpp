#ifndef RUCKSACK_ALIGNMENT2_HPP_INCLUDED
#define RUCKSACK_ALIGNMENT2_HPP_INCLUDED

#include <rucksack/alignment.hpp>
#include <rucksack/symbol.hpp>

namespace rucksack
{
class alignment2
{
public:
	RUCKSACK_SYMBOL explicit
	alignment2(
		alignment::type,
		alignment::type);

	RUCKSACK_SYMBOL alignment::type
	x() const;

	RUCKSACK_SYMBOL alignment::type
	y() const;
private:
	alignment::type x_,y_;
};
}

#endif
