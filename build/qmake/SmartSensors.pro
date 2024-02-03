# __          __     _____  _   _ _____ _   _  _____
# \ \        / /\   |  __ \| \ | |_   _| \ | |/ ____|
#  \ \  /\  / /  \  | |__) |  \| | | | |  \| | |  __
#   \ \/  \/ / /\ \ |  _  /| . ` | | | | . ` | | |_ |
#    \  /\  / ____ \| | \ \| |\  |_| |_| |\  | |__| |
#     \/  \/_/    \_\_|  \_\_| \_|_____|_| \_|\_____|
#
# THIS FILE IS NOT AUTOMATICALLY GENERATED, AND SHOULD BE MANUALLY UPDATED

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets charts printsupport opengl openglwidgets
CONFIG += c++17
DEFINES += QCUSTOMPLOT_USE_OPENGL

SOURCES += ../../main.cpp \ 
../../src/view/MainView.cpp \ 
../../src/view/core/AbstractContainer.cpp \ 
../../src/view/core/AbstractView.cpp \ 
../../src/view/containers/SidebarContainer.cpp \ 
../../src/view/containers/MainContentContainer.cpp \ 
../../src/view/views/GroupListView.cpp \ 
../../src/view/views/SingleView/SingleView.cpp \ 
../../src/view/views/Editor/EditorView.cpp \ 
../../src/model/datagen/DataGenObj.cpp \ 
../../src/model/core/AbstractItem.cpp \ 
../../src/model/core/Category.cpp \ 
../../src/model/core/Sensor.cpp \ 
../../src/model/datagen/DataGeneratorWorker.cpp \ 
../../src/controller/storage/StorageController.cpp \ 
../../src/controller/core/AbstractController.cpp \ 
../../src/controller/LocatorController.cpp \ 
../../src/controller/window/WindowController.cpp \ 
../../src/controller/business/BusinessController.cpp \ 
../../src/utility/logger/Logger.cpp \ 
../../src/view/views/CreateView.cpp \ 
../../src/view/views/SettingsView.cpp \ 
../../src/view/widgets/GroupItem/GroupItemWidget.cpp \ 
../../src/view/core/AbstractWidget.cpp \ 
../../src/view/widgets/SidebarLowControlWidget.cpp \ 
../../src/view/core/AbstractGraphicalElement.cpp \ 
../../src/model/storage/StorageObject.cpp \ 
../../src/model/exception/BaseException.cpp \ 
../../src/controller/error/ErrorController.cpp \ 
../../src/model/exception/FatalException.cpp \ 
../../src/model/exception/NormalException.cpp \ 
../../src/MyApp.cpp \ 
../../src/utility/storage/StorageWorker.cpp \ 
../../src/utility/storage/StorageUtility.cpp \ 
../../src/utility/datagenerator/RandomDataGenerator.cpp \ 
../../src/view/utility/CustomElements.cpp \ 
../../src/view/widgets/SingleWidget/SingleSensorWidget.cpp \ 
../../src/view/widgets/RealtimeChart.cpp \ 
../../src/view/widgets/ChartHandler.cpp \ 
../../src/view/widgets/SingleWidget/SingleViewGroup.cpp \ 
../../src/view/widgets/InformationWidget.cpp \ 
../../src/view/widgets/Editor/AbstractFormWidget.cpp \ 
../../src/view/widgets/Editor/SensorFormWidget.cpp \ 
../../src/view/widgets/Editor/CategoryFormWidget.cpp \ 
../../src/view/widgets/Editor/ItemEditor.cpp \ 
../../src/view/widgets/GroupItem/GroupItemRender.cpp \ 
../../src/view/widgets/SingleWidget/SingleCategoryWidget.cpp \ 
../../src/view/widgets/SingleWidget/SingleWidgetRender.cpp \ 
../../src/model/visitor/DeleteItem.cpp \ 
../../src/view/widgets/SearchBar.cpp \ 
../../src/view/views/DefaultView.cpp \ 
../../src/model/visitor/AddItem.cpp \ 
../../src/utility/icons/Icons.cpp \ 
../../src/utility/distributionType/DistributionUtility.cpp \ 
../../include/CustomPlot/qcustomplot.cpp \ 


HEADERS += ../../src/view/MainView.h \ 
../../src/view/core/AbstractContainer.h \ 
../../src/view/core/AbstractView.h \ 
../../src/view/containers/SidebarContainer.h \ 
../../src/view/containers/MainContentContainer.h \ 
../../src/view/views/GroupListView.h \ 
../../src/view/views/SingleView/SingleView.h \ 
../../src/view/views/Editor/EditorView.h \ 
../../src/model/datagen/DataGenObj.h \ 
../../src/model/core/AbstractItem.h \ 
../../src/model/core/Category.h \ 
../../src/model/core/Sensor.h \ 
../../src/model/datagen/DataGeneratorWorker.h \ 
../../src/controller/storage/StorageController.h \ 
../../src/controller/core/AbstractController.h \ 
../../src/controller/LocatorController.h \ 
../../src/controller/window/WindowController.h \ 
../../src/controller/business/BusinessController.h \ 
../../src/utility/logger/Logger.h \ 
../../src/view/views/CreateView.h \ 
../../src/view/views/SettingsView.h \ 
../../src/view/widgets/GroupItem/GroupItemWidget.h \ 
../../src/view/core/AbstractWidget.h \ 
../../src/view/widgets/SidebarLowControlWidget.h \ 
../../src/view/core/AbstractGraphicalElement.h \ 
../../src/utility/storage/StorageUtility.h \ 
../../src/model/storage/StorageObject.h \ 
../../src/model/exception/BaseException.h \ 
../../src/controller/error/ErrorController.h \ 
../../src/model/exception/FatalException.h \ 
../../src/model/exception/NormalException.h \ 
../../src/MyApp.h \ 
../../src/utility/storage/StorageWorker.h \ 
../../src/utility/datagenerator/RandomDataGenerator.h \ 
../../src/utility/event/EventHandler.h \ 
../../src/utility/limitedqmap/LimitedQMap.h \ 
../../src/view/utility/CustomElements.h \ 
../../src/view/widgets/SingleWidget/SingleSensorWidget.h \ 
../../src/view/widgets/RealtimeChart.h \ 
../../src/view/widgets/ChartHandler.h \ 
../../src/view/widgets/SingleWidget/SingleViewGroup.h \ 
../../src/view/widgets/InformationWidget.h \ 
../../src/view/widgets/Editor/AbstractFormWidget.h \ 
../../src/view/widgets/Editor/SensorFormWidget.h \ 
../../src/view/widgets/Editor/CategoryFormWidget.h \ 
../../src/view/widgets/Editor/ItemEditor.h \ 
../../src/model/visitor/IConstVisitor.h \ 
../../src/view/widgets/GroupItem/GroupItemRender.h \ 
../../src/view/widgets/SingleWidget/SingleCategoryWidget.h \ 
../../src/view/widgets/SingleWidget/SingleWidgetRender.h \ 
../../src/model/visitor/DeleteItem.h \ 
../../src/model/visitor/IVisitor.h \ 
../../src/view/widgets/SearchBar.h \ 
../../src/view/views/DefaultView.h \ 
../../src/model/visitor/AddItem.h \ 
../../src/utility/icons/Icons.h \ 
../../src/utility/distributionType/DistributionUtility.h \ 
../../include/CustomPlot/qcustomplot.h \ 


RESOURCES+=../../resources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target