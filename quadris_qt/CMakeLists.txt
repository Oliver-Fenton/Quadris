cmake_minimum_required(VERSION 3.5)

project(Quadris VERSION 0.1 LANGUAGES CXX)

# Compiler settings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror=vla")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        cell.cc

        grid.cc
        hint.cpp
        quadris.cc
        score.cc

        commandinterpreter.cpp
        abstractblock.cc
        iblock.cc
        jblock.cc
        lblock.cc
        oblock.cc
        sblock.cc
        singleblock.cc
        hintblock.cpp
        tblock.cc
        zblock.cc
        abstractlevel.cc
        levelfour.cc
        levelone.cc
        levelthree.cc
        leveltwo.cc
        levelzero.cc
        mainwindow.h
        cell.h

        grid.h
        hint.h
        quadris.h
        score.h

        commandinterpreter.h
        abstractblock.h
        iblock.h
        jblock.h
        lblock.h
        oblock.h
        sblock.h
        singleblock.h
        hintblock.h
        tblock.h
        zblock.h
        abstractlevel.h
        levelfour.h
        levelone.h
        levelthree.h
        leveltwo.h
        levelzero.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Quadris
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Info.plist
        sequence.txt
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET quadris_qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Quadris SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Quadris
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Quadris PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.quadris_qt)
endif()
set_target_properties(Quadris PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Quadris
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Quadris)
endif()
