set (gpus_info_generator_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
set (gpus_info_generator_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE HEADER_LIST include/*.hpp)
file(GLOB_RECURSE SOURCE_LIST src/*.cpp)



add_executable (gpu_gen_definitions)

set_target_properties (gpu_gen_definitions PROPERTIES FOLDER "ph_gpu/Generators/gpu_generate_class/Generators")

target_sources (gpu_gen_definitions PRIVATE ${SOURCE_LIST} ${HEADER_LIST})



function(generate target instance_file gpu_file)
	add_custom_command (
		TARGET ${target}
		PRE_BUILD
		COMMAND $<TARGET_FILE:gpu_gen_definitions> ${instance_file} ${gpu_file})
endfunction()


target_link_libraries(gpu_gen_definitions
	PRIVATE 
	${Boost_LIBRARIES}
	${Vulkan_LIBRARIES}
	glfw
)

target_include_directories(gpu_gen_definitions PRIVATE 
	include
	${Boost_INCLUDE_DIRS}
	${Vulkan_INCLUDE_DIRS}
	glfw
	${CMAKE_CURRENT_BINARY_DIR}
)