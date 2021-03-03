

add_subdirectory (app_1)
add_subdirectory (app_2)


set_target_properties(app_1 app_2 PROPERTIES FOLDER "Main apps")