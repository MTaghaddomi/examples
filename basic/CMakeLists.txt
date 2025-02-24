#
# Copyright 2018-2020 Pejman Ghorbanzade. All rights reserved.
#

include(GNUInstallDirs)

find_package("weasel" QUIET)

if (NOT weasel_FOUND)
    message(FATAL_ERROR "required dependency on ${package_name} is missing")
endif()

add_executable(weasel_example_basic "")

target_sources(
        weasel_example_basic
    PRIVATE
        code_under_test.cpp
        code_under_test.hpp
        regression_test.cpp
        regression_test.hpp
)

target_link_libraries(
        weasel_example_basic
    PRIVATE
        weasel::client
)

source_group(
    TREE ${CMAKE_CURRENT_LIST_DIR}
    FILES $<TARGET_PROPERTY:weasel_example_basic,SOURCES>
)

install(
    TARGETS weasel_example_basic
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
