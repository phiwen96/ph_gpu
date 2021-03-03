set (gpus_info_generator_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
set (gpus_info_generator_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE HEADER_LIST include/*.hpp)
file(GLOB_RECURSE SOURCE_LIST src/*.cpp)



add_executable (gpu_gen_definitions)

set_target_properties (gpu_gen_definitions PROPERTIES FOLDER "ph_gpu/Generators/gpu_generate_class/Generators")

target_sources (gpu_gen_definitions PRIVATE ${SOURCE_LIST} ${HEADER_LIST})



function(generate target file)
add_custom_command (
	# OUTPUT
	#  ${gpus_info_generator_BINARY_DIR}/generated/generated.hpp
	TARGET ${target}
	PRE_BUILD
	COMMAND $<TARGET_FILE:gpu_gen_definitions> ${file})
endfunction()


# add_custom_command (
# OUTPUT
#  ${gpus_info_generator_BINARY_DIR}/generated/generated.hpp
# # TARGET graphics_generator
# PRE_BUILD
# COMMAND $<TARGET_FILE:gpus_info_generator> ${gpus_info_generator_BINARY_DIR}/generated/generated.hpp)

target_link_libraries(gpu_gen_definitions
PRIVATE 
/Users/pw/vulkansdk/MoltenVK/dylib/macOS/libMoltenVK.dylib 
/Users/pw/vulkansdk/macOS/lib/libVkLayer_khronos_validation.dylib
/Users/pw/vulkansdk/macOS/lib/libvulkan.1.2.162.dylib
glfw
)

target_include_directories(gpu_gen_definitions PRIVATE 
include
# /Users/pw/vulkansdk/macOS/include
/Users/pw/vulkansdk/MoltenVK/include 
glfw
/usr/local/Cellar/boost/1.75.0_1/include
${CMAKE_CURRENT_BINARY_DIR}
)