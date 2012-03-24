include(
	AwlMainGenerator)

ADD_LIBRARY(
	rucksack_testbed STATIC testbed.cpp testbed_impl.cpp)

FUNCTION(
	ADD_RUCKSACK_EXAMPLE
	EXAMPLE_NAME
	ADDITIONAL_LIBRARIES)

	STRING(REPLACE "/" "" FULL_NAME ${EXAMPLE_NAME})

	SET(FULL_NAME rucksack${FULL_NAME}example)

	awl_utils_add_portable_executable(
		${FULL_NAME}
		"rucksack::examples::main"
		${EXAMPLE_NAME}.cpp)

	TARGET_LINK_LIBRARIES (
		${FULL_NAME}
		${RUCKSACK_DEFAULT_LINK_TARGET}
		rucksack_testbed
		${ADDITIONAL_LIBRARIES}
		${Awl_LIBRARIES}
		${SGE_LIBRARIES}
		${Fcppt_core_LIBRARIES}
		${Fcppt_filesystem_LIBRARIES})

	INSTALL(
		TARGETS
		${FULL_NAME}
		DESTINATION
		${INSTALL_BINARY_DIR}
	)
ENDFUNCTION()

ADD_RUCKSACK_EXAMPLE(box "")
ADD_RUCKSACK_EXAMPLE(enumeration "${Boost_CHRONO_LIBRARIES}")
ADD_RUCKSACK_EXAMPLE(master_and_slaves "${Boost_CHRONO_LIBRARIES}")
