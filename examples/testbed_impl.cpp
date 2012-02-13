#include <sge/sprite/geometry/make_random_access_range.hpp>
#include <sge/sprite/process/all.hpp>
#include "testbed_impl.hpp"
#include <rucksack/widget/base.hpp>
#include <sge/image/colors.hpp>
#include <sge/input/keyboard/action.hpp>
#include <sge/input/keyboard/key_code.hpp>
#include <sge/input/keyboard/device.hpp>
#include <sge/renderer/depth_stencil_buffer.hpp>
#include <sge/renderer/no_multi_sampling.hpp>
#include <sge/renderer/parameters.hpp>
#include <sge/renderer/scoped_block.hpp>
#include <sge/window/system.hpp>
#include <sge/sprite/config/unit_type.hpp>
#include <sge/sprite/config/float_type.hpp>
#include <sge/renderer/visual_depth.hpp>
#include <sge/log/global.hpp>
#include <sge/renderer/vsync.hpp>
#include <sge/sprite/compare/default.hpp>
#include <sge/systems/cursor_option_field.hpp>
#include <sge/systems/input.hpp>
#include <sge/systems/input_helper.hpp>
#include <sge/systems/input_helper_field.hpp>
#include <sge/systems/list.hpp>
#include <sge/systems/renderer.hpp>
#include <sge/systems/running_to_false.hpp>
#include <sge/systems/window.hpp>
#include <sge/viewport/fill_on_resize.hpp>
#include <sge/window/parameters.hpp>
#include <fcppt/container/bitfield/basic_impl.hpp>
#include <fcppt/log/activate_levels.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/text.hpp>

rucksack::examples::testbed_impl::testbed_impl(
	sge::window::title const &_window_title)
:
	systems_(
		sge::systems::list()
		(sge::systems::window(
				sge::window::parameters(
					_window_title,
					sge::window::dim(
						1024,
						768))))
		(sge::systems::renderer(
				sge::renderer::parameters(
					sge::renderer::visual_depth::depth32,
					sge::renderer::depth_stencil_buffer::off,
					sge::renderer::vsync::on,
					sge::renderer::no_multi_sampling),
				sge::viewport::fill_on_resize()))
		(sge::systems::input(
				sge::systems::input_helper_field(
					sge::systems::input_helper::keyboard_collector),
				sge::systems::cursor_option_field::null()))),
	buffers_(
		systems_.renderer(),
		sge::sprite::buffers::option::dynamic),
	quit_connection_(
		systems_.keyboard_collector().key_callback(
			sge::input::keyboard::action(
				sge::input::keyboard::key_code::escape,
				sge::systems::running_to_false(
					running_)))),
	running_(
		true)
{
	fcppt::log::activate_levels(
		sge::log::global(),
		fcppt::log::level::debug);
}

void
rucksack::examples::testbed_impl::add_widget(
	widget::base &_widget,
	sge::image::color::any::object const &_color)
{
	sprites_.push_back(
		std::make_pair(
			&_widget,
			sprite_object(
				sprite_parameters()
					.any_color(
						_color))));
}

void
rucksack::examples::testbed_impl::run()
{
	while(running_)
	{
		systems_.window_system().poll();

		this->update();

		sge::renderer::scoped_block const block_(
			systems_.renderer());

		this->render();
	}
}

void
rucksack::examples::testbed_impl::update()
{
	for(
		sprite_list::iterator it =
			sprites_.begin();
		it != sprites_.end();
		++it)
	{
		it->second.pos(
			it->first->position());
		it->second.size(
			it->first->size());
	}
}

void
rucksack::examples::testbed_impl::render()
{
	/*
	sge::renderer::state::scoped scoped_state(
		systems_.renderer(),
		sge::renderer::state::list
			(sge::renderer::state::bool_::clear_back_buffer = true)
			(sge::renderer::state::color::back_buffer_clear_color = sge::image::colors::black()));
			*/

	typedef
	std::vector<sprite_object>
	sprite_sequence;

	sprite_sequence raw_sprites;

	for(
		sprite_list::const_iterator it =
			sprites_.begin();
		it != sprites_.end();
		++it)
		raw_sprites.push_back(
			it->second);

	sge::sprite::process::all(
		sge::sprite::geometry::make_random_access_range(
			raw_sprites.begin(),
			raw_sprites.end()),
		buffers_,
		sge::sprite::compare::default_());
}

sge::systems::instance const &
rucksack::examples::testbed_impl::systems() const
{
	return systems_;
}

rucksack::examples::testbed_impl::~testbed_impl()
{
}
