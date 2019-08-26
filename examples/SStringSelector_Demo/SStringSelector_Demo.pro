TEMPLATE     = app
TARGET       = SStringSelector_Demo
DESTDIR      = ./
QT          += core gui widgets
CONFIG      += release
DEFINES     += QT_WIDGETS_LIB

INCLUDEPATH += ../../sources
HEADERS     += ./SStringSelector_Demo.h ../../sources/SStringSelector.h
SOURCES     += ../../sources/SStringSelector.cpp ./Main.cpp ./SStringSelector_Demo.cpp

DEPENDPATH  += ./release
MOC_DIR     += ./release
OBJECTS_DIR += ./release
UI_DIR      += ./release
RCC_DIR     += ./release
