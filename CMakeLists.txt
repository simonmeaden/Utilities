cmake_minimum_required(VERSION 3.7)

project(utilities VERSION 0.1.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} "")
add_library(Utilities::Utilities ALIAS ${PROJECT_NAME})

if (USE_QT_VERSION EQUAL 5)
    message("QT5")
    find_package(Qt5
      REQUIRED
      COMPONENTS
        Core
        Gui
        Widgets
        Network
        Xml
        Svg
        LinguistTools
    )
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTORCC ON)
    include(GNUInstallDirs)
elseif(USE_QT_VERSION EQUAL 6)
    message("QT6")
    find_package(Qt6
      REQUIRED
      COMPONENTS
        Core
        Gui
        Widgets
        Network
        Xml
        Svg
        LinguistTools
      OPTIONAL_COMPONENTS
        Core5Compat
    )
    qt_standard_project_setup()
else()
    find_package(Qt6
      REQUIRED
      COMPONENTS
        Core
        Gui
        Widgets
        Network
        Xml
        Svg
        LinguistTools
      OPTIONAL_COMPONENTS
        Core5Compat
    )
    qt_standard_project_setup()
    if (NOT Qt6_FOUND)
        find_package(Qt5
          REQUIRED
          COMPONENTS
            Core
            Gui
            Widgets
            Network
            Xml
            Svg
            LinguistTools
        )
        set(CMAKE_AUTOMOC ON)
        set(CMAKE_AUTOUIC ON)
        set(CMAKE_AUTORCC ON)
        include(GNUInstallDirs)
    endif()
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Werror
)

target_sources(
    ${PROJECT_NAME}

  INTERFACE
#    include/utilities/x11colors.h            # header only
#    include/utilities/characters.h  # header only
#    include/circularbuffer/circularbuffer.h  # header only
#    include/circularbuffer/CircularBuffer.h  # header only

  PRIVATE
    # These have to be added to get MOC to work correctly apparently
    # Not certain if there is a better way - yet.
    include/utilities/qtidydoc.h
    include/utilities/tinyxml2.h
    include/utilities/tinyxmldocument.h
    include/utilities/stringutil.h
    include/utilities/csvsplitter.h
    include/utilities/paths.h
    include/utilities/filedownloader.h
    include/utilities/keymap.h
    include/utilities/characters.h
    # end of MOC shit

    src/utilities/qtidydoc.cpp
    src/utilities/tinyxml2.cpp
    src/utilities/tinyxmldocument.cpp
    src/utilities/stringutil.cpp
    src/utilities/csvsplitter.cpp
    src/utilities/filedownloader.cpp
    src/utilities/keymap.cpp
    src/utilities/paths.cpp

)

target_compile_features(${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC

    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Xml
        Qt${QT_VERSION_MAJOR}::Svg

        tidy
)

option(BUILD_DOC "Build documentation" ON)
find_package(Doxygen)
if (DOXYGEN_FOUND)
  # Only build documentation when building in Release mode
  if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
  endif()
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
