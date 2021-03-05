cmake_minimum_required (VERSION 3.19.4)

project (
	ph_gpu 
	VERSION 1.0
	DESCRIPTION "Very nice project"
	LANGUAGES CXX)


file (GLOB_RECURSE HEADER_LIST include/*.hpp)
file (GLOB SOURCE_LIST src/*.cpp)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set (CMAKE_CXX_STANDARD 20)
	set (CMAKE_CXX_STANDARD_REQUIRED ON)

	set_property(GLOBAL PROPERTY USE_FOLDERS YES)

	find_package (Boost 1.75 REQUIRED)
	find_package(Vulkan REQUIRED)
	find_package(glfw3 REQUIRED)
	find_package(glm REQUIRED)

	# include (CTest)
	include (FetchContent)
endif()

add_subdirectory(generators)

add_library (ph_gpu ${SOURCE_LIST} ${HEADER_LIST})

# add_custom_command (
# 		# OUTPUT
# 		#  ${gpus_info_generator_BINARY_DIR}/generated/generated.hpp
# 		TARGET ph_gpu
# 		PRE_BUILD
# 		COMMAND $<TARGET_FILE:graphics_generator> ${CMAKE_CURRENT_SOURCE_DIR}/include/ph_gpu/gpu.hpp)

generate (ph_gpu ${CMAKE_CURRENT_SOURCE_DIR}/include/ph_gpu/instance.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/ph_gpu/gpu.hpp)



# target_sources (ph_gpu PRIVATE ${SOURCE_LIST} ${HEADER_LIST})
# target_sources (ph_gpu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ph_gpu/gpu.hpp)

# add_custom_command (
# # OUTPUT
# #  ${gpus_info_generator_BINARY_DIR}/generated/gpus_info.hpp
# TARGET ph_gpu
# PRE_BUILD
# COMMAND $<TARGET_FILE:graphics_generator> ${CMAKE_CURRENT_BINARY_DIR}/generated/generated.hpp)

target_include_directories (ph_gpu PUBLIC include)
target_include_directories (ph_gpu PRIVATE ${CMAKE_CURRENT_BINARY_DIR})




# if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
# 	add_subdirectory (tests)
# endif()


add_subdirectory(apps)