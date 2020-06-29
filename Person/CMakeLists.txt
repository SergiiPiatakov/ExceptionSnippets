cmake_minimum_required  (VERSION 3.1)
project                 (person)
set (person_VERSION_MAJOR 0)
set (person_VERSION_MINOR 1)

set (PersonLib_SOURCES
    ${PROJECT_SOURCE_DIR}/Person.cpp
)

add_library (person ${PersonLib_SOURCES})
add_library (gl::person ALIAS person)

target_compile_features (person
    PUBLIC cxx_std_11
)

target_include_directories (person
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options (person
    PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Wall -Wextra>
)
