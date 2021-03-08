cmake_minimum_required (VERSION 3.19.4)



project (
	phulkan_generator
	VERSION 1.0
	DESCRIPTION "Very nice project"
	LANGUAGES CXX
)

add_subdirectory (dependencies/phake)
# ph_git ()


add_subdirectory (dependencies/const_str)
add_subdirectory (dependencies/Phan)



if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set (CMAKE_CXX_STANDARD 20)
	set (CMAKE_CXX_STANDARD_REQUIRED ON)

	set_property(GLOBAL PROPERTY USE_FOLDERS YES)

	find_package (Boost 1.75 REQUIRED)
	find_package(Vulkan REQUIRED)
	find_package(glfw3 REQUIRED)
	find_package(glm REQUIRED)

	# include (CTest)
endif()



add_subdirectory(generators)

add_subdirectory (src)



add_subdirectory(apps)



# cmake -S . -B xbuild -GXcode && cmake --open xbuild