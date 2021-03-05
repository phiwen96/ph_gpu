
add_subdirectory (generators)


file(GLOB_RECURSE HEADER_LIST ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable (gpu_generate_class ${SOURCE_LIST} ${HEADER_LIST})

set_target_properties(gpu_generate_class PROPERTIES FOLDER "ph_gpu/Generators")


generate (gpu_generate_class ${CMAKE_CURRENT_SOURCE_DIR}/include/gpu_gen_definitions.hpp)

# set_target_properties (include/gpu_gen_definitions.hpp PROPERTIES FOLDER "ph_gpu/Generators/gpu_generate_class/Generators")

target_sources (gpu_generate_class PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/gpu_gen_definitions.hpp)

target_compile_definitions (gpu_generate_class PRIVATE GENERATED_INCLUDE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/include/gpu_gen_definitions.hpp")


target_link_libraries(gpu_generate_class
PRIVATE 
	# /Users/pw/vulkansdk/MoltenVK/dylib/macOS/libMoltenVK.dylib 
	# /Users/pw/vulkansdk/macOS/lib/libVkLayer_khronos_validation.dylib
	# /Users/pw/vulkansdk/macOS/lib/libvulkan.1.2.170.dylib
	# /Users/pw/vulkansdk/macOS/lib/libvulkan.1.dylib
	${Boost_LIBRARIES}
${Vulkan_LIBRARIES}
	glfw
)

target_include_directories(gpu_generate_class PRIVATE 
	include
	# /Users/pw/vulkansdk/MoltenVK/include 
	${Boost_INCLUDE_DIRS}
${Vulkan_INCLUDE_DIRS}
	glfw
	# /usr/local/Cellar/boost/1.75.0_1/include
	${CMAKE_CURRENT_BINARY_DIR}
)


function(generate target file)
	add_custom_command (
		TARGET ${target}
		PRE_BUILD
		COMMAND $<TARGET_FILE:gpu_generate_class> ${file})
endfunction()