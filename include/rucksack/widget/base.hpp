#ifndef RUCKSACK_WIDGET_BASE_HPP_INCLUDED
#define RUCKSACK_WIDGET_BASE_HPP_INCLUDED

#include <rucksack/axis_policy2.hpp>
#include <rucksack/class_symbol.hpp>
#include <rucksack/dim.hpp>
#include <rucksack/rect.hpp>
#include <rucksack/symbol.hpp>
#include <rucksack/vector.hpp>
#include <rucksack/widget/optional_parent.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/intrusive/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace rucksack
{
namespace widget
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

class RUCKSACK_CLASS_SYMBOL base
:
	public
		boost::intrusive::list_base_hook
		<
			boost::intrusive::link_mode<boost::intrusive::auto_unlink>
		>
{
FCPPT_PP_POP_WARNING

FCPPT_NONCOPYABLE(
	base);
public:
	virtual void
	size(
		rucksack::dim const &) = 0;

	virtual void
	position(
		rucksack::vector const &) = 0;

	virtual rucksack::dim const
	size() const = 0;

	rucksack::rect const
	area() const;

	virtual rucksack::vector const
	position() const = 0;

	virtual rucksack::axis_policy2 const
	axis_policy() const = 0;

	virtual void
	relayout() = 0;

	RUCKSACK_SYMBOL void
	parent(
		rucksack::widget::optional_parent const &);

	RUCKSACK_SYMBOL rucksack::widget::optional_parent const &
	parent() const;

	RUCKSACK_SYMBOL
	virtual ~base() = 0;
protected:
	RUCKSACK_SYMBOL
	explicit
	base(
		rucksack::widget::optional_parent const &);

	RUCKSACK_SYMBOL virtual void
	child_destroyed(
		base &);
private:
	rucksack::widget::optional_parent parent_;
};
}
}


#endif
