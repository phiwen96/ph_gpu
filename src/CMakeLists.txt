
file (GLOB_RECURSE HEADER_LIST ${PROJECT_SOURCE_DIR}/include/*.hpp)
file (GLOB SOURCE_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)


add_library (phulkan_generator STATIC ${SOURCE_LIST} ${HEADER_LIST})

generate (phulkan_generator ${PROJECT_SOURCE_DIR}/include/phulkan_generator/instance.hpp ${PROJECT_SOURCE_DIR}/include/phulkan_generator/gpu.hpp)


target_include_directories (phulkan_generator PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories (phulkan_generator PRIVATE ${CMAKE_CURRENT_BINARY_DIR})



target_include_directories(phulkan_generator PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/phulkan_generator>
    $<INSTALL_INTERFACE:include/phulkan_generator>
)

target_include_directories(phulkan_generator PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)