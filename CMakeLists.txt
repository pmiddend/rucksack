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
	ADD_DEFINITIONS(-Wno-old-style-cast)
ENDIF()

SET(
	INSTALL_MEDIA_DIR
	${INSTALL_DATA_DIR}/media)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

SET(
	RUCKSACK_FILES
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
	rucksack STATIC ${RUCKSACK_FILES})

ADD_SUBDIRECTORY(
	examples)
