set(IRODS_TEST_TARGET irods_get_delay_rule_info)

set(IRODS_TEST_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
                            ${CMAKE_CURRENT_SOURCE_DIR}/src/test_get_delay_rule_info.cpp)

set(IRODS_TEST_INCLUDE_PATH ${CMAKE_BINARY_DIR}/lib/core/include
                            ${CMAKE_SOURCE_DIR}/lib/core/include
                            ${CMAKE_SOURCE_DIR}/lib/api/include
                            ${CMAKE_SOURCE_DIR}/lib/filesystem/include
                            ${CMAKE_SOURCE_DIR}/plugins/api/include
                            ${CMAKE_SOURCE_DIR}/server/core/include
                            ${CMAKE_SOURCE_DIR}/server/icat/include
                            ${CMAKE_SOURCE_DIR}/server/re/include
                            ${IRODS_EXTERNALS_FULLPATH_CATCH2}/include
                            ${IRODS_EXTERNALS_FULLPATH_BOOST}/include
                            ${IRODS_EXTERNALS_FULLPATH_FMT}/include
                            ${IRODS_EXTERNALS_FULLPATH_JSON}/include)

set(IRODS_TEST_LINK_LIBRARIES irods_client
                              irods_common
                              ${IRODS_EXTERNALS_FULLPATH_FMT}/lib/libfmt.so)
