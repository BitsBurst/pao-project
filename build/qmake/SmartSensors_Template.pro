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

SOURCES += {SOURCES}

HEADERS += {HEADERS}

RESOURCES+=../../resources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target