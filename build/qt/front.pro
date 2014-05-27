#
#  Project file for afront application
#  as part (client side) of apery project system
#

TEMPLATE = app
TARGET = afront

BUILD_DIR = $$PWD/../out
ROOT_SRC_DIR = &&PWD/../../src

MODULE_OUT_DIR = $$BUILD_DIR/mods
DOCS_OUT_DIR = $$BUILD_DIR/docs
DESTDIR = $$BUILD_DIR/bin

QT += core gui

INCLUDEPATH += \
    $$ROOT_SRC_DIR/core/queue \
    $$ROOT_SRC_DIR/core/loader

HEADERS += \
    queue.h \
    loader.h \
    front_loader.h \
    base_types.h \
    application.h

SOURCES += \
    main.cpp \
    queue.cpp \
    front_loader.cpp


# afront global defines
DEFINES += FRONT_BUILD_MODE=1