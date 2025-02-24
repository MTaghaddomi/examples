#
# Copyright 2018-2020 Pejman Ghorbanzade. All rights reserved.
#

include(GNUInstallDirs)

find_package("cxxopts" QUIET)
find_package("weasel" QUIET)

add_executable(weasel_example_advanced "")

target_sources(
        weasel_example_advanced
    PRIVATE
        code_under_test.cpp
        code_under_test.hpp
        regression_test.cpp
        regression_test.hpp
)

target_link_libraries(
        weasel_example_advanced
    PRIVATE
        cxxopts::cxxopts
        weasel::framework
)

source_group(
    TREE ${CMAKE_CURRENT_LIST_DIR}
    FILES $<TARGET_PROPERTY:weasel_example_advanced,SOURCES>
)

install(
    TARGETS weasel_example_advanced
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
