FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
    message(STATUS "Fetching googletest v${GTEST_VERSION}")

    FetchContent_Populate(googletest)

    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()