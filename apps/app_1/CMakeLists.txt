
file(GLOB HEADER_LIST include/*.hpp)
file(GLOB SOURCE_LIST src/*.cpp)

add_executable (app_1)

target_sources(app_1 PRIVATE ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries (app_1 PRIVATE ph_gpu)
target_include_directories (app_1 PRIVATE include ph_gpu)

