# __          __     _____  _   _ _____ _   _  _____
# \ \        / /\   |  __ \| \ | |_   _| \ | |/ ____|
#  \ \  /\  / /  \  | |__) |  \| | | | |  \| | |  __
#   \ \/  \/ / /\ \ |  _  /| . ` | | | | . ` | | |_ |
#    \  /\  / ____ \| | \ \| |\  |_| |_| |\  | |__| |
#     \/  \/_/    \_\_|  \_\_| \_|_____|_| \_|\_____|
#
# THIS FILE IS NOT AUTOMATICALLY GENERATED, AND SHOULD BE MANUALLY UPDATED

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
        ../../main.cpp \
        ../../src/view/MainView.cpp \
        ../../src/view/core/AbstractContainer.cpp \
        ../../src/view/core/AbstractView.cpp \
        ../../src/view/containers/SidebarContainer.cpp \
        ../../src/view/containers/MainContentContainer.cpp \
        ../../src/view/views/GroupListView.cpp \
        ../../src/view/views/SingleView.cpp \
        ../../src/view/views/ModifyView.cpp \
        ../../src/model/datagen/AbstractDataGen.cpp \
        ../../src/model/core/AbstractItem.cpp \
        ../../src/model/core/Category.cpp \
        ../../src/model/core/Sensor.cpp \
        ../../src/model/datagen/LinearDataGen.cpp \
        ../../src/model/datagen/RandomDataGen.cpp \
        ../../src/model/datagen/DataGeneratorWorker.cpp \
        ../../src/controller/storage/StorageController.cpp \
        ../../src/controller/core/AbstractController.cpp \
        ../../src/controller/LocatorController.cpp \
        ../../src/controller/window/WindowController.cpp \
        ../../src/controller/business/BusinessController.cpp \
        ../../src/utility/Logger.cpp \
        ../../src/model/storage/StorageObject.cpp

HEADERS += \
        ../../src/model/storage/StorageObject.h \
        ../../src/utility/Logger.h \
        ../../src/utility/StorageUtility.h \
        ../../src/view/MainView.h \
        ../../src/view/core/AbstractContainer.h \
        ../../src/view/core/AbstractView.h \
        ../../src/controller/business/BusinessController.h \
        ../../src/controller/window/WindowController.h \
        ../../src/controller/LocatorController.h \
        ../../src/controller/core/AbstractController.h \
        ../../src/tests/testDavide.h \
        ../../src/model/datagen/RandomDataGen.h \
        ../../src/controller/storage/StorageController.h \
        ../../src/model/datagen/DataGeneratorWorker.h \
        ../../src/model/datagen/LinearDataGen.h \
        ../../src/model/core/Sensor.h \
        ../../src/model/core/Category.h \
        ../../src/model/core/AbstractItem.h \
        ../../src/model/datagen/AbstractDataGen.h \
        ../../src/view/views/ModifyView.h \
        ../../src/view/views/SingleView.h \
        ../../src/view/views/GroupListView.h \
        ../../src/view/containers/MainContentContainer.h \
        ../../src/view/containers/SidebarContainer.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target