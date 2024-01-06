cmake_minimum_required(VERSION 3.5)

project(SmartSensors VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{QT_PATH})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/controller/Controller.cpp
        src/controller/Controller.h
        src/view/MainView.cpp
        src/view/MainView.h
        src/view/AbstractContainer.cpp
        src/view/AbstractContainer.h
        src/view/AbstractView.cpp
        src/view/AbstractView.h
        src/view/SidebarContainer.cpp
        src/view/SidebarContainer.h
        src/view/MainContentContainer.cpp
        src/view/MainContentContainer.h
        src/view/GroupListView.cpp
        src/view/GroupListView.h
        src/view/SingleView.cpp
        src/view/SingleView.h
        src/view/ModifyView.cpp
        src/view/ModifyView.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartSensors
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(SmartSensors SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(SmartSensors
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SmartSensors PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SmartSensors)
endif()
set_target_properties(SmartSensors PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SmartSensors
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartSensors)
endif()
