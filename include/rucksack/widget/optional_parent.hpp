#ifndef RUCKSACK_WIDGET_OPTIONAL_PARENT_HPP_INCLUDED
#define RUCKSACK_WIDGET_OPTIONAL_PARENT_HPP_INCLUDED

#include <rucksack/widget/base_fwd.hpp>
#include <fcppt/optional_fwd.hpp>

namespace rucksack
{
namespace widget
{
typedef
fcppt::optional<widget::base &>
optional_parent;
}
}

#endif
