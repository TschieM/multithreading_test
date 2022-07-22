FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_executable (test
    # main
    main.cpp
    # port
    linux_interface/linux_interface.cpp
    )

target_include_directories(test
    PRIVATE
    # project wide
    ${PROJECT_SOURCE_DIR}/include
    # pre-generated
    ${CMAKE_BINARY_DIR}/include
    # port
    linux_interface
)

install(TARGETS test  DESTINATION ${CMAKE_BINARY_DIR}/bin)