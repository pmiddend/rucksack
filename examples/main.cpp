#include <rucksack/widget/base.hpp>
#include <rucksack/widget/box.hpp>
#include <sge/image/color/rgba8.hpp>
#include <sge/image/color/rgba8_format.hpp>
#include <sge/image/colors.hpp>
#include <sge/input/keyboard/action.hpp>
#include <sge/input/keyboard/device.hpp>
#include <sge/log/global.hpp>
#include <sge/renderer/no_multi_sampling.hpp>
#include <sge/renderer/parameters.hpp>
#include <sge/renderer/scoped_block.hpp>
#include <sge/renderer/state/bool.hpp>
#include <sge/renderer/state/color.hpp>
#include <sge/renderer/state/list.hpp>
#include <sge/renderer/state/trampoline.hpp>
#include <sge/renderer/state/var.hpp>
#include <sge/sprite/choices.hpp>
#include <sge/sprite/external_system_impl.hpp>
#include <sge/sprite/object.hpp>
#include <sge/sprite/parameters.hpp>
#include <sge/sprite/render_one.hpp>
#include <sge/sprite/system.hpp>
#include <sge/sprite/type_choices.hpp>
#include <sge/sprite/with_color.hpp>
#include <sge/sprite/with_dim.hpp>
#include <sge/systems/instance.hpp>
#include <sge/systems/list.hpp>
#include <sge/systems/parameterless.hpp>
#include <sge/systems/running_to_false.hpp>
#include <sge/viewport/center_on_resize.hpp>
#include <sge/window/instance.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/log/activate_levels.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdlib>
#include <iostream>
#include <fcppt/config/external_end.hpp>

#include <sge/sprite/default_parameters.hpp>
#include <sge/sprite/defaults/defaults.hpp>

namespace
{
typedef
sge::sprite::choices
<
	sge::sprite::type_choices
	<
		rucksack::scalar,
		float,
		sge::image::color::rgba8_format
	>,
	boost::mpl::vector2
	<
		sge::sprite::with_dim,
		sge::sprite::with_color
	>
>
sprite_choices;

typedef
sge::sprite::system<sprite_choices>::type
sprite_system;

typedef
sge::sprite::object<sprite_choices>
sprite_object;

typedef
sge::sprite::parameters<sprite_choices>
sprite_parameters;

class sprite_widget
:
	public rucksack::widget::base
{
FCPPT_NONCOPYABLE(
	sprite_widget);
public:
	explicit
	sprite_widget(
		rucksack::widget::optional_parent const &_parent,
		sprite_parameters const &_parameters,
		rucksack::axis_policy2 const &_axis_policy)
	:
		rucksack::widget::base(
			_parent),
		sprite_(
			_parameters.elements()),
		axis_policy_(
			_axis_policy)
	{
	}

	~sprite_widget()
	{
	}

	void
	size(
		rucksack::dim const &_size)
	{
		sprite_.size(
			_size);
	}

	void
	position(
		rucksack::vector const &_pos)
	{
		sprite_.pos(
			_pos);
	}

	rucksack::dim const
	size() const
	{
		return sprite_.size();
	}

	rucksack::vector const
	position() const
	{
		return sprite_.pos();
	}

	rucksack::axis_policy2 const
	axis_policy() const
	{
		return axis_policy_;
	}

	void
	relayout()
	{
	}

	sprite_object const
	sprite() const
	{
		return sprite_;
	}
private:
	sprite_object sprite_;
	rucksack::axis_policy2 axis_policy_;
};
}

int main()
try
{
	fcppt::log::activate_levels(
		sge::log::global(),
		fcppt::log::level::debug);

	sge::window::dim const window_dim(
		1024,
		768);

	sge::systems::instance const sys(
		sge::systems::list()
		(sge::systems::window(
				sge::window::simple_parameters(
					FCPPT_TEXT("rucksack main example"),
					window_dim)))
		(sge::systems::renderer(
				sge::renderer::parameters(
					sge::renderer::visual_depth::depth32,
					sge::renderer::depth_stencil_buffer::off,
					sge::renderer::vsync::on,
					sge::renderer::no_multi_sampling),
				sge::viewport::center_on_resize(
					window_dim)))
		(sge::systems::input(
				sge::systems::input_helper_field(
					sge::systems::input_helper::keyboard_collector),
				sge::systems::cursor_option_field::null())));

	sprite_system ss(
		sys.renderer());

	rucksack::widget::box outer_box(
		rucksack::widget::optional_parent(),
		rucksack::alignment::center,
		rucksack::axis::x,
		rucksack::aspect(
			1,
			1));

	rucksack::widget::box left_box(
		rucksack::widget::optional_parent(
			outer_box),
		rucksack::alignment::center,
		rucksack::axis::y,
		rucksack::aspect(
			1,
			1));

	rucksack::widget::box right_box(
		rucksack::widget::optional_parent(
			outer_box),
		rucksack::alignment::center,
		rucksack::axis::y,
		rucksack::aspect(
			1,
			1));

	sprite_widget inner_sprite(
		rucksack::widget::optional_parent(
			left_box),
		sge::sprite::default_parameters<sprite_choices>()
			.any_color(
				sge::image::colors::red()),
		rucksack::axis_policy2(
			rucksack::axis_policy(
				rucksack::minimum_size(
					100),
				rucksack::preferred_size(),
				rucksack::is_expanding(
					false)),
			rucksack::axis_policy(
				rucksack::minimum_size(
					50),
				rucksack::preferred_size(),
				rucksack::is_expanding(
					false)),
			rucksack::aspect(
				1,
				1)));

	sprite_widget inner_sprite2(
		rucksack::widget::optional_parent(
			right_box),
		sge::sprite::default_parameters<sprite_choices>()
			.any_color(
				sge::image::colors::green()),
		rucksack::axis_policy2(
			rucksack::axis_policy(
				rucksack::minimum_size(
					200),
				rucksack::preferred_size(),
				rucksack::is_expanding(
					false)),
			rucksack::axis_policy(
				rucksack::minimum_size(
					50),
				rucksack::preferred_size(),
				rucksack::is_expanding(
					false)),
			rucksack::aspect(
				1,
				1)));

	outer_box.position(
		rucksack::vector(
			0,
			0));
	outer_box.size(
		rucksack::dim(
			640,
			480));
	outer_box.relayout();

	sprite_object outer_box_sprite(
		sge::sprite::default_parameters<sprite_choices>()
			.pos(
				outer_box.position())
			.size(
				outer_box.size())
			.any_color(
				sge::image::colors::blue()).elements());

	sprite_object left_box_sprite(
		sge::sprite::default_parameters<sprite_choices>()
			.pos(
				left_box.position())
			.size(
				left_box.size())
			.any_color(
				sge::image::colors::cyan()).elements());

	sprite_object right_box_sprite(
		sge::sprite::default_parameters<sprite_choices>()
			.pos(
				right_box.position())
			.size(
				right_box.size())
			.any_color(
				sge::image::colors::magenta()).elements());

	std::cout << "left box position: " << left_box.position() << ", size: " << left_box.size() << "\n";
	std::cout << "right box position: " << right_box.position() << ", size: " << right_box.size() << "\n";
	std::cout << "inner position: " << inner_sprite.position() << ", size: " << inner_sprite2.size() << "\n";
	std::cout << "inner2 position: " << inner_sprite2.position() << ", size: " << inner_sprite2.size() << "\n";

	bool running = true;

	fcppt::signal::scoped_connection const cb(
		sys.keyboard_collector().key_callback(
			sge::input::keyboard::action(
				sge::input::keyboard::key_code::escape,
				sge::systems::running_to_false(
					running))));

	sys.renderer().state(
		sge::renderer::state::list
		(sge::renderer::state::bool_::clear_back_buffer = true)
		(sge::renderer::state::color::back_buffer_clear_color = sge::image::colors::black()));

	while(
		running)
	{
		sys.window().dispatch();

		sge::renderer::scoped_block const block_(
			sys.renderer());

		sge::sprite::render_one(
			ss,
			outer_box_sprite);
		sge::sprite::render_one(
			ss,
			left_box_sprite);
		sge::sprite::render_one(
			ss,
			right_box_sprite);
		sge::sprite::render_one(
			ss,
			inner_sprite.sprite());
		sge::sprite::render_one(
			ss,
			inner_sprite2.sprite());
	}
}
catch(
	fcppt::exception const &error)
{
	fcppt::io::cerr()
		<< error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
