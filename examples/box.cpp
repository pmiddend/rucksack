#include "testbed.hpp"
#include <rucksack/widget/box/base.hpp>
#include <rucksack/widget/viewport_adaptor.hpp>
#include <rucksack/widget/dummy.hpp>
#include <sge/systems/instance.hpp>
#include <sge/image/colors.hpp>
#include <sge/image/color/any/object.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

int main()
try
{
	rucksack::examples::testbed testbed_(
		FCPPT_TEXT("rucksack box test"));

	rucksack::widget::viewport_adaptor viewport_box(
		testbed_.systems().viewport_manager(),
		testbed_.systems().renderer());

	rucksack::widget::box::base outer_box(
		rucksack::axis::x,
		rucksack::aspect(
			1,
			1));

	viewport_box.child(
		outer_box);

	rucksack::widget::box::base left_box(
		rucksack::axis::y,
		rucksack::aspect(
			1,
			1));

	outer_box.push_back_child(
		left_box,
		rucksack::alignment::left_or_top);

	rucksack::widget::box::base right_box(
		rucksack::axis::y,
		rucksack::aspect(
			1,
			1));

	outer_box.push_back_child(
		right_box,
		rucksack::alignment::center);

	rucksack::widget::dummy inner_sprite(
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

	left_box.push_back_child(
		inner_sprite,
		rucksack::alignment::center);

	rucksack::widget::dummy inner_sprite2(
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

	right_box.push_back_child(
		inner_sprite2,
		rucksack::alignment::right_or_bottom);

	testbed_.add_widget(
		viewport_box,
		sge::image::colors::blue());

	testbed_.add_widget(
		inner_sprite,
		sge::image::colors::red());

	testbed_.add_widget(
		inner_sprite2,
		sge::image::colors::green());

	testbed_.run();
}
catch(
	fcppt::exception const &error)
{
	fcppt::io::cerr()
		<< error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
