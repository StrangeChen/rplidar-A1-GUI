# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = rplidar_a1_gui
DESTDIR = ../x64/Debug
QT += core opengl gui widgets serialport
CONFIG += debug
DEFINES += _UNICODE WIN64 QT_DLL QT_OPENGL_LIB QT_SERIALPORT_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
LIBS += -L"../" \
    -lrplidar_driver \
    -lopengl32 \
    -lglu32
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(rplidar_a1_gui.pri)
win32:RC_FILE = rplidar_a1_gui.rc
