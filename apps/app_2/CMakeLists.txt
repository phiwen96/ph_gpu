
file(GLOB HEADER_LIST include/*.hpp)
file(GLOB SOURCE_LIST src/*.cpp)

add_executable (app_2)

target_sources(app_2 PRIVATE ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries (app_2 PRIVATE phulkan_generator)
target_include_directories (app_2 PRIVATE include phulkan_generator)

