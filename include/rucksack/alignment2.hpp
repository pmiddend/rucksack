#ifndef RUCKSACK_ALIGNMENT2_HPP_INCLUDED
#define RUCKSACK_ALIGNMENT2_HPP_INCLUDED

#include <rucksack/alignment.hpp>

namespace rucksack
{
class alignment2
{
public:
	explicit
	alignment2(
		alignment::type,
		alignment::type);

	alignment::type
	x() const;

	alignment::type
	y() const;
private:
	alignment::type x_,y_;
};
}

#endif
