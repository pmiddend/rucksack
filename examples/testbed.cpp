#include "testbed.hpp"
#include "testbed_impl.hpp"
#include <fcppt/make_unique_ptr.hpp>

rucksack::examples::testbed::testbed(
	fcppt::string const &_str)
:
	impl_(
		fcppt::make_unique_ptr<examples::testbed_impl>(
			_str))
{
}

void
rucksack::examples::testbed::add_widget(
	widget::base &_widget,
	sge::image::color::any::object const &_color)
{
	return
		impl_->add_widget(
			_widget,
			_color);
}

void
rucksack::examples::testbed::run()
{
	return
		impl_->run();
}

void
rucksack::examples::testbed::update()
{
	return
		impl_->update();
}

void
rucksack::examples::testbed::render()
{
	return
		impl_->render();
}

sge::systems::instance const &
rucksack::examples::testbed::systems() const
{
	return
		impl_->systems();
}

rucksack::examples::testbed::~testbed()
{
}
