#ifndef RUCKSACK_EXAMPLES_TESTBED_HPP_INCLUDED
#define RUCKSACK_EXAMPLES_TESTBED_HPP_INCLUDED

#include "testbed_impl_fwd.hpp"
#include <rucksack/widget/base_fwd.hpp>
#include <sge/image/color/any/object_fwd.hpp>
#include <fcppt/string.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/noncopyable.hpp>

namespace rucksack
{
namespace examples
{
class testbed
{
FCPPT_NONCOPYABLE(
	testbed);
public:
	explicit
	testbed(
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

	~testbed();
private:
	fcppt::scoped_ptr<examples::testbed_impl> impl_;
};
}
}

#endif
