#ifndef RUCKSACK_WIDGET_VIEWPORT_ADAPTOR_HPP_INCLUDED
#define RUCKSACK_WIDGET_VIEWPORT_ADAPTOR_HPP_INCLUDED

#include <rucksack/class_symbol.hpp>
#include <rucksack/symbol.hpp>
#include <rucksack/widget/base.hpp>
#include <rucksack/widget/optional_parent.hpp>
#include <sge/renderer/device_fwd.hpp>
#include <sge/viewport/manager_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/scoped_connection.hpp>


namespace rucksack
{
namespace widget
{
/**
 * The viewport adaptor has juts one single child. It synchronizes the size and
 * position of this child with the given viewport. So in a hierarchy, this
 * manager is supposed to be near the top.
 *
 * The operations size(...) and position(...) resize and reposition the
 * viewport.
 *
 * Note that you _can_ use this class with a parent (in which case the viewport
 * will be changed by the parent) but I don't know any use case for this, since
 * a renderer can only have one viewport at a time.
 */
class RUCKSACK_CLASS_SYMBOL viewport_adaptor
:
	public rucksack::widget::base
{
FCPPT_NONCOPYABLE(
	viewport_adaptor);
public:
	// We need the renderer object for the size() and position() getters/setters.
	// The viewport manager ironically doesn't give us access to the viewport
	// directly.
	RUCKSACK_SYMBOL explicit
	viewport_adaptor(
		sge::viewport::manager &,
		sge::renderer::device &);

	RUCKSACK_SYMBOL void
	size(
		rucksack::dim const &);

	RUCKSACK_SYMBOL void
	position(
		rucksack::vector const &);

	RUCKSACK_SYMBOL rucksack::dim const
	size() const;

	RUCKSACK_SYMBOL rucksack::vector const
	position() const;

	RUCKSACK_SYMBOL rucksack::axis_policy2 const
	axis_policy() const;

	RUCKSACK_SYMBOL void
	relayout();

	RUCKSACK_SYMBOL void
	child(
		widget::base &);

	RUCKSACK_SYMBOL ~viewport_adaptor();
private:
	sge::renderer::device &renderer_;
	fcppt::signal::scoped_connection viewport_connection_;
	widget::base *child_;

	void
	manage_callback();

	void
	child_destroyed(
		widget::base &);
};
}
}

#endif
