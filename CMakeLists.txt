cmake_minimum_required(VERSION 3.16)

project(LanguageStat)


add_custom_target(prebuild
COMMAND wget -nc -P ${PROJECT_SOURCE_DIR}/resources/ https://github.com/github-linguist/linguist/blob/master/lib/linguist/languages.yml)
    
set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(LanguageStat ${SOURCES})
set_property(TARGET LanguageStat PROPERTY CXX_STANDARD 20)
# target_link_libraries(LanguageStat -lpthread)
add_dependencies(LanguageStat prebuild)

if("${UNIT_TESTS}" MATCHES "ON")
    enable_testing()
    add_subdirectory(tests)
endif()
