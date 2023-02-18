add_executable(project_activity main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

target_include_directories(project_activity PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(project_activity PUBLIC cxx_std_17)
target_compile_definitions(project_activity PRIVATE SFML_STATIC)

target_link_libraries(project_activity ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})