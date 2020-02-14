FetchContent_GetProperties(json)

if (NOT json_POPULATED)
    message(STATUS "Fetching Json v${JSON_VERSION}")

    FetchContent_Populate(json)

    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()
