cmake_minimum_required  (VERSION 3.1)
project                 (person)
set (person_VERSION_MAJOR 0)
set (person_VERSION_MINOR 1)

set (PersonLib_SOURCES
    ${PROJECT_SOURCE_DIR}/Person.cpp
)

add_library (person ${PersonLib_SOURCES})
add_library (gl::person ALIAS person)

set_target_properties (person
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories (person
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options (person
    PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Wall -Wextra>
)

# Add and link exception library

set(XCEPT_SOURCES  ${PROJECT_SOURCE_DIR}/xeptions.cpp)

add_library (xeptions ${PersonLib_SOURCES})

set_target_properties (xeptions
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories (person
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options (xeptions
    PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Wall -Wextra>
)

#target_link_libraries(xeptions PUBLIC person)
