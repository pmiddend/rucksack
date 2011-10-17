#include <rucksack/widget/viewport_adaptor.hpp>
#include <sge/renderer/onscreen_target.hpp>
#include <sge/renderer/device.hpp>
#include <sge/viewport/manager.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_end.hpp>

rucksack::widget::viewport_adaptor::viewport_adaptor(
	widget::optional_parent const &_parent,
	sge::viewport::manager &_viewport,
	sge::renderer::device &_renderer)
:
	widget::base(
		_parent),
	renderer_(
		_renderer),
	viewport_connection_(
		_viewport.manage_callback(
			std::tr1::bind(
				&viewport_adaptor::manage_callback,
				this)))
{
}

void
rucksack::widget::viewport_adaptor::size(
	rucksack::dim const &_size)
{
	renderer_.onscreen_target().viewport(
		sge::renderer::viewport(
			sge::renderer::viewport::value_type(
				renderer_.onscreen_target().viewport().get().pos(),
				fcppt::math::dim::structure_cast<sge::renderer::viewport::value_type::dim>(
					_size))));
}

void
rucksack::widget::viewport_adaptor::position(
	rucksack::vector const &_pos)
{
	renderer_.onscreen_target().viewport(
		sge::renderer::viewport(
			sge::renderer::viewport::value_type(
				fcppt::math::vector::structure_cast<sge::renderer::viewport::value_type::vector>(
					_pos),
				renderer_.onscreen_target().viewport().get().size())));
}

rucksack::dim const
rucksack::widget::viewport_adaptor::size() const
{
	return
		fcppt::math::dim::structure_cast<rucksack::dim>(
			renderer_.onscreen_target().viewport().get().size());
}

rucksack::vector const
rucksack::widget::viewport_adaptor::position() const
{
	return
		fcppt::math::vector::structure_cast<rucksack::vector>(
			renderer_.onscreen_target().viewport().get().pos());
}

rucksack::axis_policy2 const
rucksack::widget::viewport_adaptor::axis_policy() const
{
	// A dummy for now, until there's a use case
	return 
		rucksack::axis_policy2(
			rucksack::axis_policy(
				rucksack::minimum_size(),
				rucksack::preferred_size(),
				rucksack::is_expanding()),
			rucksack::axis_policy(
				rucksack::minimum_size(),
				rucksack::preferred_size(),
				rucksack::is_expanding()),
			rucksack::aspect(
				1,
				1));
}

void
rucksack::widget::viewport_adaptor::relayout()
{
	// A dummy for now, until there's a use case
	for(base::child_list::iterator it = children_.begin(); it != children_.end(); ++it)
		it->relayout();
}

rucksack::widget::viewport_adaptor::~viewport_adaptor()
{
}

void
rucksack::widget::viewport_adaptor::manage_callback()
{
	rucksack::dim const this_size = 
		this->size();

	for(base::child_list::iterator it = children_.begin(); it != children_.end(); ++it)
	{
		it->size(
			this_size);
		it->relayout();
	}
}
