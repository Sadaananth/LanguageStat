cmake_minimum_required(VERSION 3.16)

project(LanguageStat)


add_custom_target(prebuild
COMMAND wget -nc -P ${PROJECT_SOURCE_DIR}/resources/ https://raw.githubusercontent.com/github-linguist/linguist/master/lib/linguist/languages.yml)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(LanguageStat ${SOURCES})
set_property(TARGET LanguageStat PROPERTY CXX_STANDARD 20)
add_dependencies(LanguageStat prebuild)
target_include_directories(LanguageStat PUBLIC ${PROJECT_SOURCE_DIR}/third_party/yaml-cpp/yaml-cpp/include)
target_link_libraries(LanguageStat ${PROJECT_SOURCE_DIR}/third_party/yaml_cpp/yaml-cpp/build/libyaml-cpp.a)

if("${UNIT_TESTS}" MATCHES "ON")
    enable_testing()
    add_subdirectory(tests)
endif()
