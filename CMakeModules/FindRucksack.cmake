# - Try to find the rucksack library
#
# This module defines the following variables
#
#	RUCKSACK_FOUND        - True when rucksack was found
#	Rucksack_INCLUDE_DIRS - All includes required for rucksack to work
#	Rucksack_LIBRARIES    - All libraries required for rucksack to work
#
# This modules accepts the following variables
#
#	SGE_USE_STATIC_LIBS  - Use static linking.
#	RUCKSACK_INCLUDEDIR    - Hint where the rucksack includes might be.
#	RUCKSACK_LIBRARYDIR    - Hint where the rucksack libraries might be.

if(
	Rucksack_FIND_QUIETLY
)
	set(
		RUCKSACK_FIND_OPTIONS
		"QUIET"
	)
endif()

if(
	Rucksack_FIND_REQUIRED
)
	set(
		RUCKSACK_FIND_OPTIONS
		"REQUIRED"
	)
endif()

#Set SGE_DEFINITIONS for static linking
if(
	Rucksack_USE_STATIC_LIBS
)
	set(
		Rucksack_DEFINITIONS
		"-D RUCKSACK_STATIC_LINK"
	)
endif()

find_package(
	Boost
	1.45.0
	${RUCKSACK_FIND_OPTIONS}
	COMPONENTS
	system
)

find_package(
	Fcppt
	${RUCKSACK_FIND_OPTIONS}
)

find_package(
	SGE ${RUCKSACK_FIND_OPTIONS}
	COMPONENTS
	renderer
	image
	input
	viewport
	window
	sprite
	systems)

unset(
	RUCKSACK_FIND_OPTIONS
)

find_path(
	Rucksack_INCLUDE_DIR
	NAMES rucksack/scalar.hpp
	HINTS ${RUCKSACK_INCLUDEDIR}
)

if(
	Rucksack_USE_STATIC_LIBS
)
	set(
		RUCKSACK_CURRENT_LIB
		rucksack_static)
else()
	set(
		RUCKSACK_CURRENT_LIB
		rucksack)
endif()

find_library(
	Rucksack_LIBRARY
	NAMES ${RUCKSACK_CURRENT_LIB}
	HINTS "${RUCKSACK_LIBRARYDIR}"
)

include(
	FindPackageHandleStandardArgs
)

set(
	Rucksack_INCLUDE_DIRS
	"${SGE_INCLUDE_DIRS};${Rucksack_INCLUDE_DIR};${Fcppt_INCLUDE_DIRS};${Boost_INCLUDE_DIRS}"
)

set(
	Rucksack_LIBRARIES
	"${SGE_LIBRARIES};${Rucksack_LIBRARY};${Fcppt_LIBRARIES}"
)

find_package_Handle_standard_args(
	Rucksack
	DEFAULT_MSG
	Rucksack_INCLUDE_DIR
	Rucksack_LIBRARY
)

mark_as_advanced(
	Rucksack_INCLUDE_DIR
	Rucksack_LIBRARY
)
