#ifndef RUCKSACK_WIDGET_BASE_HPP_INCLUDED
#define RUCKSACK_WIDGET_BASE_HPP_INCLUDED

#include <rucksack/widget/optional_parent.hpp>
#include <rucksack/vector.hpp>
#include <rucksack/class_symbol.hpp>
#include <rucksack/symbol.hpp>
#include <rucksack/axis_policy2.hpp>
#include <rucksack/dim.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/intrusive/list.hpp>
#include <fcppt/config/external_end.hpp>

namespace rucksack
{
namespace widget
{
class RUCKSACK_CLASS_SYMBOL base
:
	public
		boost::intrusive::list_base_hook
		<
			boost::intrusive::link_mode<boost::intrusive::auto_unlink>
		>
{
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

	virtual rucksack::vector const
	position() const = 0;

	virtual rucksack::axis_policy2 const
	axis_policy() const = 0;

	virtual void
	relayout() = 0;

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

	void
	parent(
		rucksack::widget::optional_parent const &);

	rucksack::widget::optional_parent const &
	parent() const;
};
}
}


#endif
