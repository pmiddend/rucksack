CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(rucksack)

INCLUDE(FcpptCMakeUtils)

# boost begin
FIND_PACKAGE(
	Boost 1.45.0 REQUIRED COMPONENTS
	system)

INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
# boost end

# fcppt begin
FIND_PACKAGE(Fcppt REQUIRED)
INCLUDE_DIRECTORIES(${Fcppt_INCLUDE_DIRS})
ADD_DEFINITIONS(${Fcppt_DEFINITIONS})
# fcppt end

# sge begin
FIND_PACKAGE(
	SGE REQUIRED COMPONENTS
	renderer
	image
	input
	viewport
	window
	sprite
	systems)

INCLUDE_DIRECTORIES(${SGE_INCLUDE_DIRS})
ADD_DEFINITIONS(${SGE_DEFINITIONS})
# sge end

# get rid of a pretty useless warning
IF(CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP)
	REMOVE_DEFINITIONS(-Wold-style-cast)
ENDIF()

SET(
	INSTALL_MEDIA_DIR
	${INSTALL_DATA_DIR}/media)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

SET(
	RUCKSACK_FILES
	include/rucksack/alignment.hpp
	include/rucksack/alignment2.hpp
	include/rucksack/aspect.hpp
	include/rucksack/axis.hpp
	include/rucksack/axis_policy.hpp
	include/rucksack/axis_policy2.hpp
	include/rucksack/class_symbol.hpp
	include/rucksack/dim.hpp
	include/rucksack/is_expanding.hpp
	include/rucksack/minimum_size.hpp
	include/rucksack/optional_dim.hpp
	include/rucksack/optional_scalar.hpp
	include/rucksack/preferred_size.hpp
	include/rucksack/scalar.hpp
	include/rucksack/size_policy.hpp
	include/rucksack/size_policy2.hpp
	include/rucksack/size_policy_field.hpp
	include/rucksack/symbol.hpp
	include/rucksack/transient_layout_data.hpp
	include/rucksack/vector.hpp
	include/rucksack/widget/base.hpp
	include/rucksack/widget/base_fwd.hpp
	include/rucksack/widget/box.hpp
	include/rucksack/widget/optional_parent.hpp
	include/rucksack/widget/viewport_adaptor.hpp
	src/rucksack/alignment2.cpp
	src/rucksack/aspect.cpp
	src/rucksack/axis_policy.cpp
	src/rucksack/axis_policy2.cpp
	src/rucksack/size_policy2.cpp
	src/rucksack/transient_layout_data.cpp
	src/rucksack/widget/base.cpp
	src/rucksack/widget/box.cpp
	src/rucksack/widget/viewport_adaptor.cpp
)

FCPPT_UTILS_ADD_SOURCE_GROUPS("${RUCKSACK_FILES}")

ADD_LIBRARY(
	rucksack SHARED ${RUCKSACK_FILES})

TARGET_LINK_LIBRARIES(
	rucksack
	${SGE_LIBRARIES}
	${Fcppt_LIBRARIES})

ADD_SUBDIRECTORY(
	examples)
