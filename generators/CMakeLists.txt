
add_subdirectory (generators)


# add_custom_command (
# 	OUTPUT gpus_info.hpp 
# 	PRE_BUILD
# 	COMMAND gpus_info_generator 
# 	# "${CMAKE_CURRENT_BINARY_DIR}/gpus_info.hpp"
# 	)

# target_compile_definitions (graphics_number_of_gpus_generator PUBLIC TEMPLATE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics_template.hpp")

# set (graphics_generator_BINARY_DIR STRING ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
# message(${graphics_generator_BINARY_DIR})

file(GLOB_RECURSE HEADER_LIST ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable (graphics_generator ${SOURCE_LIST} ${HEADER_LIST})

# add_custom_command (
# 		# OUTPUT
# 		#  ${gpus_info_generator_BINARY_DIR}/generated/generated.hpp
# 		TARGET graphics_generator
# 		PRE_BUILD
# 		COMMAND $<TARGET_FILE:gpus_info_generator> ${CMAKE_CURRENT_BINARY_DIR}/generated.hpp)

# add_custom_command (
# # OUTPUT
# #  ${gpus_info_generator_BINARY_DIR}/generated/gpus_info.hpp
# TARGET graphics_generator
# PRE_BUILD
# COMMAND $<TARGET_FILE:gpus_info_generator> ${CMAKE_CURRENT_BINARY_DIR}/generated/generated.hpp)
generate (graphics_generator ${CMAKE_CURRENT_BINARY_DIR}/generated.hpp)

# target_sources (graphics_generator PRIVATE ${gpus_info_generator_BINARY_DIR}/generated/generated.hpp)

# add_custom_command (
# 	OUTPUT ${graphics_generator_BINARY_DIR}/generated/graphics_info.hpp
# 	# TARGET phulkan_library
# 	PRE_BUILD
# 	COMMAND $<TARGET_FILE:graphics_generator> ${graphics_generator_BINARY_DIR}/generated/graphics_info.hpp)


target_compile_definitions (graphics_generator PRIVATE GENERATED_INCLUDE_FILE="${CMAKE_CURRENT_BINARY_DIR}/generated.hpp")



# add_custom_command (
# 	TARGET graphics_generator
# 	PRE_BUILD
# 	COMMAND $<TARGET_FILE:gpus_info_generator> ${CMAKE_CURRENT_BINARY_DIR}/gpus_info.hpp)

# target_sources(graphics_generator PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated/gpus_info.hpp)

# message("$<TARGET_FILE_DIR:graphics_generator>")

# add_custom_command(testing
# 	PRE_BUILD 
# 	COMMAND open .
# )

target_link_libraries(graphics_generator
PRIVATE 
	# /Users/pw/vulkansdk/macOS/lib/libvulkan.1.2.162.dylib 
	/Users/pw/vulkansdk/MoltenVK/dylib/macOS/libMoltenVK.dylib 
	/Users/pw/vulkansdk/macOS/lib/libVkLayer_khronos_validation.dylib
	/Users/pw/vulkansdk/macOS/lib/libvulkan.1.2.162.dylib
	glfw
)

target_include_directories(graphics_generator PRIVATE 
	# /Users/pw/vulkansdk/macOS/include
	include
	/Users/pw/vulkansdk/MoltenVK/include 
	glfw
	/usr/local/Cellar/boost/1.75.0_1/include
	${CMAKE_CURRENT_BINARY_DIR}
	# ${CMAKE_CURRENT_BINARY_DIR}/generated
)

# target_include_directories(graphics_generator
# PRIVATE
# ${Vulkan_INCLUDE_DIR}
#   glfw
#   glm)


# add_custom_command (
# 	OUTPUT graphics_info.hpp 
# 	COMMAND graphics_generator)

# target_compile_definitions (graphics_generator PUBLIC TEMPLATE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics_template.hpp")


# try_run (
#     # Name of variable to store the run result (process exit status; number) in:
#     test_run_result

#     # Name of variable to store the compile result (TRUE or FALSE) in:
#     test_compile_result

#     # Binary directory:
#     ${CMAKE_CURRENT_BINARY_DIR}/

#     # Source file to be compiled:
#     "${CMAKE_CURRENT_SOURCE_DIR}/generators/number_of_gpus.cpp"

#     # Where to store the output produced during compilation:
#     COMPILE_OUTPUT_VARIABLE test_compile_output

#     # Where to store the output produced by running the compiled executable:
#     RUN_OUTPUT_VARIABLE test_run_output)

    # Did compilation succeed and process return 0 (success)?
# IF("${test_compile_result}" AND ("${test_run_result}" EQUAL 0))
# # Strip whitespace (such as the trailing newline from std::endl)
# # from the produced output:
# STRING(STRIP "${test_run_output}" test_run_output)
# ELSE()
# # Error on failure and print error message:
# MESSAGE(FATAL_ERROR "Failed check!")
# ENDIF()

function(generate target file)
	add_custom_command (
		# OUTPUT
		#  ${gpus_info_generator_BINARY_DIR}/generated/generated.hpp
		TARGET ${target}
		PRE_BUILD
		COMMAND $<TARGET_FILE:graphics_generator> ${file})
endfunction()