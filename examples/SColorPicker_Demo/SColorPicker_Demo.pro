TEMPLATE     = app
TARGET       = SColorPicker_Demo
DESTDIR      = ./
QT          += core gui widgets
CONFIG      += release
DEFINES     += QT_WIDGETS_LIB

INCLUDEPATH += ../../sources
HEADERS     += ./SColorPicker_Demo.h ../../sources/SColorPicker.h
SOURCES     += ../../sources/SColorPicker.cpp ./Main.cpp ./SColorPicker_Demo.cpp

DEPENDPATH  += ./release
MOC_DIR     += ./release
OBJECTS_DIR += ./release
UI_DIR      += ./release
RCC_DIR     += ./release
