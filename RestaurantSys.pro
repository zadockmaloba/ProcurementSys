# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = RestaurantSys
DESTDIR = ./Debug
CONFIG += debug
QT += widgets gui core sql
HEADERS += "." \
    dbdriver.h \
    infosetup.h
LIBS += -L"."
DEPENDPATH += .
MOC_DIR += GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += GeneratedFiles
RCC_DIR += GeneratedFiles
include(RestaurantSys.pri)

SOURCES += \
    dbdriver.cpp \
    infosetup.cpp

FORMS += \
    infosetup.ui