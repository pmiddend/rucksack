cmake_minimum_required(VERSION 2.6)

project(rucksack)

include(FcpptCMakeUtils)

include(
	FcpptSymbol
)

# boost begin
find_package(
	Boost 1.47.0 REQUIRED COMPONENTS
	chrono
	system)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

# boost-1.48 is broken with fusion, workaround
if(
	MSVC AND ${Boost_VERSION} STREQUAL "104800")
	add_definitions(
		-D BOOST_FUSION_DONT_USE_PREPROCESSED_FILES
	)
endif()
# boost end

# fcppt begin
find_package(Fcppt REQUIRED)
include_directories(${Fcppt_INCLUDE_DIRS})
add_definitions(${Fcppt_DEFINITIONS})
# fcppt end

# awl begin
find_package(
	Awl REQUIRED)
include_directories(
	${Awl_INCLUDE_DIR})
add_definitions(
	${Awl_DEFINITIONS})
# awl end

# sge begin
FIND_PACKAGE(
	SGE REQUIRED COMPONENTS
	renderer
	image
	input
	log
	viewport
	window
	sprite
	systems
	# The following is only required for static linking (make this optional later)
	core
	plugin
	audio
	media
	font
	image2d
	config
	charconv)

include_directories(${SGE_INCLUDE_DIRS})
add_definitions(${SGE_DEFINITIONS})
# sge end

# get rid of a pretty useless warning
if(CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP)
	remove_definitions(
		-Wold-style-cast)
endif()

set(
	INSTALL_MEDIA_DIR
	${INSTALL_DATA_DIR}/media)

include_directories(
	${CMAKE_SOURCE_DIR}/include)

fcppt_generate_symbol_header(
	RUCKSACK_STATIC_LINK
	rucksack
	RUCKSACK
	rucksack
)

include_directories(
	${CMAKE_BINARY_DIR}/include)

SET(
	RUCKSACK_FILES
	src/rucksack/alignment2.cpp
	src/rucksack/aspect.cpp
	src/rucksack/axis_policy.cpp
	src/rucksack/axis_policy2.cpp
	src/rucksack/widget/base.cpp
	src/rucksack/widget/box/base.cpp
	src/rucksack/widget/box/child_information.cpp
	src/rucksack/widget/dummy.cpp
	src/rucksack/widget/enumeration.cpp
	src/rucksack/widget/master_and_slaves.cpp
	src/rucksack/widget/viewport_adaptor.cpp
)

fcppt_utils_add_source_groups(
	"${RUCKSACK_FILES}")

option(
	ENABLE_SHARED
	"Build rucksack as a shared library"
	TRUE
)

option(
	ENABLE_STATIC
	"Build rucksack as a static library"
	FALSE
)

if(
	NOT ENABLE_SHARED AND NOT ENABLE_STATIC
)
	message(
		FATAL_ERROR
		"You disabled both STATIC and SHARED"
	)
endif()

# choose a library to link the tests to
if(
	ENABLE_SHARED
)
	set(
		RUCKSACK_DEFAULT_LINK_TARGET
		rucksack
	)
endif()

# static overrides shared
if(
	ENABLE_STATIC
)
	set(
		RUCKSACK_DEFAULT_LINK_TARGET
		rucksack_static
	)

	set(
		RUCKSACK_CONFIG_LINK_MACROS
		"-D RUCKSACK_STATIC_LINK"
	)
endif()

function(
	MAKE_RUCKSACK_LIBRARY
	TARGETNAME
	VARIANT
)
	add_library(
		${TARGETNAME}
		${VARIANT}
		${RUCKSACK_FILES}
	)

	if(
		NOT MSVC
	)
		target_link_libraries(
			${TARGETNAME}
			${Boost_SYSTEM_LIBRARY}
		)
	endif()

	if(
		${VARIANT} STREQUAL "STATIC"
	)
		set_target_properties(
			${TARGETNAME}
			PROPERTIES
			COMPILE_DEFINITIONS
			"RUCKSACK_STATIC_LINK"
		)
	endif()

	target_link_libraries(
		${TARGETNAME}
		${Fcppt_core_LIBRARIES}
		${Awl_LIBRARIES}
		${SGE_LIBRARIES})

	install(
		TARGETS
		${TARGETNAME}
		DESTINATION
		${INSTALL_LIBRARY_DIR}
	)
endfunction()

if(
	ENABLE_STATIC
)
	make_rucksack_library(
		rucksack_static
		STATIC
	)
endif()

if(
	ENABLE_SHARED
)
	make_rucksack_library(
		rucksack
		SHARED
	)
endif()

ADD_SUBDIRECTORY(
	examples)
