
add_subdirectory (generators)

set (GENERATED_INSTANCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/include/instance.hpp")
set (GENERATED_GPU_FILE "${CMAKE_CURRENT_SOURCE_DIR}/include/gpu.hpp")



file(GLOB_RECURSE HEADER_LIST ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable (gpu_generate_class ${SOURCE_LIST} ${HEADER_LIST})

set_target_properties(gpu_generate_class PROPERTIES FOLDER "phulkan_generator/Generators")


generate (gpu_generate_class 
	${GENERATED_INSTANCE_FILE} 
	${GENERATED_GPU_FILE})
# generate (gpu_generate_class ${CMAKE_CURRENT_BINARY_DIR}/gpu.hpp)
# add_custom_command (
# 		TARGET gpu_generate_class
# 		PRE_BUILD
# 		COMMAND $<TARGET_FILE:gpu_gen_definitions> ${CMAKE_CURRENT_SOURCE_DIR}/include/gpu.hpp)

# set_target_properties (include/gpu_gen_definitions.hpp PROPERTIES FOLDER "ph_gpu/Generators/gpu_generate_class/Generators")

# target_sources (gpu_generate_class PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/gpu.hpp)

target_compile_definitions (gpu_generate_class 
	PRIVATE 
	PROJECT_NAME="${PROJECT_NAME}"
	GENERATED_INSTANCE_FILE="${GENERATED_INSTANCE_FILE}" 
	GENERATED_GPU_FILE="${GENERATED_GPU_FILE}")


target_link_libraries(gpu_generate_class
	PRIVATE 
	${Boost_LIBRARIES}
	${Vulkan_LIBRARIES}
	glfw
)

target_include_directories(gpu_generate_class 
	PRIVATE 
	include
	${Boost_INCLUDE_DIRS}
	${Vulkan_INCLUDE_DIRS}
	glfw
	${CMAKE_CURRENT_BINARY_DIR}
)


function(generate target instance_file gpu_file)
	add_custom_command (
		TARGET ${target}
		PRE_BUILD
		COMMAND $<TARGET_FILE:gpu_generate_class> ${instance_file} ${gpu_file})
endfunction()