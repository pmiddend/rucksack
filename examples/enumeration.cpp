#include "main.hpp"
#include "testbed.hpp"
#include <rucksack/widget/enumeration.hpp>
#include <rucksack/widget/viewport_adaptor.hpp>
#include <rucksack/widget/dummy.hpp>
#include <sge/systems/instance.hpp>
#include <sge/image/colors.hpp>
#include <sge/image/color/any/object.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/exit_failure.hpp>
#include <awl/main/function_context_fwd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/random/uniform.hpp>
#include <fcppt/random/default_generator.hpp>
#include <fcppt/random/make_inclusive_range.hpp>
#include <fcppt/chrono/high_resolution_clock.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/container/ptr/push_back_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <boost/ptr_container/ptr_vector.hpp>
#include <fcppt/config/external_end.hpp>

awl::main::exit_code const
rucksack::examples::main(
	awl::main::function_context const &)
try
{
	rucksack::examples::testbed testbed_(
		sge::window::title(
			FCPPT_TEXT("rucksack enumeration test")));

	rucksack::widget::viewport_adaptor viewport_box(
		testbed_.systems().viewport_manager(),
		testbed_.systems().renderer());

	rucksack::widget::enumeration enumeration_box(
		rucksack::padding(
			5),
		rucksack::aspect(
			1,
			1));

	viewport_box.child(
		enumeration_box);

	fcppt::random::default_generator def_gen(
		static_cast<fcppt::random::default_generator::result_type>(
			fcppt::chrono::high_resolution_clock::now().time_since_epoch().count()));

	fcppt::random::uniform<rucksack::scalar,fcppt::random::default_generator &>
		size_rng_w(
			fcppt::random::make_inclusive_range(
				10,
				300),
			def_gen),
		size_rng_h(
			fcppt::random::make_inclusive_range(
				10,
				300),
			def_gen);

	typedef
	boost::ptr_vector<rucksack::widget::dummy>
	dummy_sprite_sequence;

	dummy_sprite_sequence sprites;

	testbed_.add_widget(
		viewport_box,
		sge::image::colors::blue());

	for(unsigned i = 0; i < 20; ++i)
	{
		fcppt::container::ptr::push_back_unique_ptr(
			sprites,
			fcppt::make_unique_ptr<rucksack::widget::dummy>(
				rucksack::axis_policy2(
					rucksack::axis_policy(
						rucksack::minimum_size(
							size_rng_w()),
						rucksack::preferred_size(),
						rucksack::is_expanding(
							false)),
					rucksack::axis_policy(
						rucksack::minimum_size(
							size_rng_h()),
						rucksack::preferred_size(),
						rucksack::is_expanding(
							false)),
					rucksack::aspect(
						1,
						1))));

		enumeration_box.push_back_child(
			sprites.back());

		testbed_.add_widget(
			sprites.back(),
			sge::image::colors::red());
	}

	return testbed_.run();
}
catch(
	fcppt::exception const &error)
{
	fcppt::io::cerr()
		<< error.string()
		<< FCPPT_TEXT('\n');

	return awl::main::exit_failure();
}
