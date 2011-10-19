#ifndef RUCKSACK_EXAMPLES_TESTBED_IMPL_HPP_INCLUDED
#define RUCKSACK_EXAMPLES_TESTBED_IMPL_HPP_INCLUDED

#include <rucksack/widget/base_fwd.hpp>
#include <rucksack/scalar.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/string.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <utility>
#include <boost/mpl/vector/vector10.hpp>
#include <fcppt/config/external_end.hpp>
#include <sge/image/color/any/object_fwd.hpp>
#include <sge/image/color/rgba8_format.hpp>
#include <sge/sprite/choices.hpp>
#include <sge/sprite/object.hpp>
#include <sge/sprite/parameters.hpp>
#include <sge/sprite/system.hpp>
#include <sge/sprite/external_system_impl.hpp>
#include <sge/sprite/type_choices.hpp>
#include <sge/sprite/with_color.hpp>
#include <sge/sprite/with_dim.hpp>
#include <sge/systems/instance.hpp>

namespace rucksack
{
namespace examples
{
class testbed_impl
{
FCPPT_NONCOPYABLE(
	testbed_impl);
public:
	explicit
	testbed_impl(
		fcppt::string const &);

	void
	add_widget(
		widget::base &,
		sge::image::color::any::object const &);

	void
	run();

	void
	update();

	void
	render();

	sge::systems::instance const &
	systems() const;

	~testbed_impl();
private:
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

	typedef
	std::vector
	<
		std::pair<widget::base*,sprite_object>
	>
	sprite_list;

	sge::systems::instance systems_;
	sprite_system sprite_system_;
	sprite_list sprites_;
	fcppt::signal::scoped_connection quit_connection_;
	bool running_;
};
}
}

#endif

