cmake_minimum_required(VERSION 3.5)

project(SmartSensors VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CMAKE_PREFIX_PATH the path where Qt is installed
set(CMAKE_PREFIX_PATH "$ENV{QT_PATH}/6.6.1/gcc_64/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts Core PrintSupport Gui OpenGL OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts Core PrintSupport Gui OpenGL OpenGLWidgets)
add_compile_definitions(QCUSTOMPLOT_USE_OPENGL)
string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)

set(PROJECT_SOURCES
        main.cpp
        src/view/MainView.cpp
        src/view/MainView.h
        src/view/core/AbstractContainer.cpp
        src/view/core/AbstractContainer.h
        src/view/core/AbstractView.cpp
        src/view/core/AbstractView.h
        src/view/containers/SidebarContainer.cpp
        src/view/containers/SidebarContainer.h
        src/view/containers/MainContentContainer.cpp
        src/view/containers/MainContentContainer.h
        src/view/views/GroupListView.cpp
        src/view/views/GroupListView.h
        src/view/views/SingleView/SingleView.cpp
        src/view/views/SingleView/SingleView.h
        src/view/views/Editor/EditorView.cpp
        src/view/views/Editor/EditorView.h
        src/model/datagen/DataGenObj.cpp
        src/model/datagen/DataGenObj.h
        src/model/core/AbstractItem.cpp
        src/model/core/AbstractItem.h
        src/model/core/Category.cpp
        src/model/core/Category.h
        src/model/core/Sensor.cpp
        src/model/core/Sensor.h
        src/model/datagen/DataGeneratorWorker.cpp
        src/model/datagen/DataGeneratorWorker.h
        src/controller/storage/StorageController.cpp
        src/controller/storage/StorageController.h
        src/controller/core/AbstractController.cpp
        src/controller/core/AbstractController.h
        src/controller/LocatorController.cpp
        src/controller/LocatorController.h
        src/controller/window/WindowController.cpp
        src/controller/window/WindowController.h
        src/controller/business/BusinessController.cpp
        src/controller/business/BusinessController.h
        src/utility/logger/Logger.cpp
        src/utility/logger/Logger.h
        src/view/views/CreateView.cpp
        src/view/views/CreateView.h
        src/view/views/SettingsView.cpp
        src/view/views/SettingsView.h
        src/view/widgets/GroupItem/GroupItemWidget.cpp
        src/view/widgets/GroupItem/GroupItemWidget.h
        src/view/core/AbstractWidget.cpp
        src/view/core/AbstractWidget.h
        src/view/widgets/SidebarLowControlWidget.cpp
        src/view/widgets/SidebarLowControlWidget.h
        src/view/core/AbstractGraphicalElement.cpp
        src/view/core/AbstractGraphicalElement.h
        src/utility/storage/StorageUtility.h
        src/model/storage/StorageObject.cpp
        src/model/storage/StorageObject.h
        src/model/exception/BaseException.cpp
        src/model/exception/BaseException.h
        src/controller/error/ErrorController.cpp
        src/controller/error/ErrorController.h
        src/model/exception/FatalException.cpp
        src/model/exception/FatalException.h
        src/model/exception/NormalException.cpp
        src/model/exception/NormalException.h
        src/MyApp.cpp
        src/MyApp.h
        src/utility/storage/StorageWorker.cpp
        src/utility/storage/StorageWorker.h
        src/utility/storage/StorageUtility.cpp
        src/utility/datagenerator/RandomDataGenerator.cpp
        src/utility/datagenerator/RandomDataGenerator.h
        src/utility/event/EventHandler.h
        src/utility/limitedqmap/LimitedQMap.h
        src/view/utility/CustomElements.h
        src/view/utility/CustomElements.cpp
        resources.qrc
        src/view/widgets/SingleWidget/SingleSensorWidget.cpp
        src/view/widgets/SingleWidget/SingleSensorWidget.h
        src/view/widgets/RealtimeChart.cpp
        src/view/widgets/RealtimeChart.h
        src/view/widgets/ChartHandler.cpp
        src/view/widgets/ChartHandler.h
        src/view/widgets/SingleWidget/SingleViewGroup.h
        src/view/widgets/SingleWidget/SingleViewGroup.cpp
        src/view/widgets/InformationWidget.cpp
        src/view/widgets/InformationWidget.h
        src/view/widgets/Editor/AbstractFormWidget.cpp
        src/view/widgets/Editor/AbstractFormWidget.h
        src/view/widgets/Editor/SensorFormWidget.cpp
        src/view/widgets/Editor/SensorFormWidget.h
        src/view/widgets/Editor/CategoryFormWidget.cpp
        src/view/widgets/Editor/CategoryFormWidget.h
        src/view/widgets/Editor/ItemEditor.cpp
        src/view/widgets/Editor/ItemEditor.h
        src/model/visitor/IConstVisitor.h
        src/view/widgets/GroupItem/GroupItemRender.cpp
        src/view/widgets/GroupItem/GroupItemRender.h
        src/view/widgets/SingleWidget/SingleCategoryWidget.cpp
        src/view/widgets/SingleWidget/SingleCategoryWidget.h
        src/view/widgets/SingleWidget/SingleWidgetRender.cpp
        src/view/widgets/SingleWidget/SingleWidgetRender.h
        src/model/visitor/DeleteItem.cpp
        src/model/visitor/DeleteItem.h
        src/model/visitor/IVisitor.h
        src/view/widgets/SearchBar.cpp
        src/view/widgets/SearchBar.h
        src/view/views/DefaultView.cpp
        src/view/views/DefaultView.h
        src/model/visitor/AddItem.cpp
        src/model/visitor/AddItem.h
        src/utility/icons/Icons.cpp
        src/utility/icons/Icons.h
        src/utility/distributionType/DistributionUtility.cpp
        src/utility/distributionType/DistributionUtility.h
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

add_library(qcustomplot
        include/CustomPlot/qcustomplot.h
        include/CustomPlot/qcustomplot.cpp
)
target_link_libraries(qcustomplot PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::PrintSupport Qt${QT_VERSION_MAJOR}::OpenGL Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

target_link_libraries(SmartSensors PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts qcustomplot Qt${QT_VERSION_MAJOR}::OpenGL Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

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
if (build_type STREQUAL release)
    #target_compile_definitions(${PROJECT_NAME} PUBLIC
    #        QT_NO_DEBUG_OUTPUT
    #        QT_NO_INFO_OUTPUT
    #        QT_NO_WARNING_OUTPUT
    #)
else ()
    #add_compile_definitions(DEBUG)
endif ()