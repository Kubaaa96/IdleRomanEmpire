function(add_app APP_NAME)
    cmake_parse_arguments(ARGS "" "" "SOURCES;DEPENDS" ${ARGN})
    add_executable(${APP_NAME} ${ARGS_SOURCES})
    get_property(PROJECT_LIBS GLOBAL PROPERTY PROJECT_LIBS_PROPERTY)
    set_link_options_app(${APP_NAME} DEPENDS ${ARGS_DEPENDS})
endfunction()

function(create_test TESTNAME)
    cmake_parse_arguments(ARGS "" "" "SOURCES;DEPENDS" ${ARGN})
    add_executable(${TESTNAME} ${ARGS_SOURCES})
    set_link_options(${TESTNAME} DEPENDS ${ARGS_DEPENDS})
    gtest_discover_tests(${TESTNAME}
            WORKING_DIRECTORY ${PROJECT_DIR}
            PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
            )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER ${CMAKE_SOURCE_DIR}/tests)

endfunction()

function(add_library_and_link)
    set(prefix ARG)
    set(options SKIP_CXX_FLAGS)
    set(singleValues NAME)
    set(multiValues SOURCES DEPENDS)
    cmake_parse_arguments(${prefix} "${options}" "${singleValues}" "${multiValues}" ${ARGN})
    if (ARG_SKIP_CXX_FLAGS)
        set(SKIP_CXX_FLAGS "SKIP_CXX_FLAGS")
    endif ()

    set(LIB_NAME ${${prefix}_NAME})
    set(LIB_SOURCES ${${prefix}_SOURCES})
    add_library(${LIB_NAME} STATIC ${LIB_SOURCES})

    set_link_options(${LIB_NAME} ${SKIP_CXX_FLAGS} DEPENDS ${${prefix}_DEPENDS})
endfunction()

function(set_link_options_app TARGET_NAME)
    cmake_parse_arguments(ARGS "" "" "DEPENDS" ${ARGN})
    target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${TARGET_NAME} PUBLIC ${ARGS_DEPENDS})
    include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
    set_project_warnings(${TARGET_NAME})
endfunction()

function(set_link_options TARGET_NAME)
    cmake_parse_arguments(ARGS "" "" "DEPENDS" ${ARGN})
    target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include ${CONAN_INCLUDE_DIRS})
    target_link_libraries(${TARGET_NAME} PRIVATE ${CONAN_LIBS} PUBLIC ${ARGS_DEPENDS})
    include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
    set_project_warnings(${TARGET_NAME})
endfunction()

macro(initialize_conan)
    download_conan_cmake()

    include(${CMAKE_BINARY_DIR}/conan/conan.cmake)
    set(CONAN_SYSTEM_INCLUDES ON)
    conan_cmake_run(
            CONANFILE ${CMAKE_SOURCE_DIR}/conanfile.txt
            BASIC_SETUP
            BUILD missing
    )
endmacro()

function(download_conan_cmake)
    if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan/conan.cmake")
        message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan/conan.cmake")
    endif ()
endfunction()