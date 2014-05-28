#
#  Project file for afront application
#  as part (client side) of apery project system
#

TEMPLATE = app
TARGET = afront

BUILD_DIR = $$PWD/../out
ROOT_SRC_DIR = $$PWD/../../src
MODULE_OUT_DIR = $$BUILD_DIR/mods
DOCS_OUT_DIR = $$BUILD_DIR/docs

DESTDIR = $$BUILD_DIR/bin
OBJECTS_DIR = $$BUILD_DIR

QT += core gui widgets

INCLUDEPATH += \
    $$ROOT_SRC_DIR/core/queue \
    $$ROOT_SRC_DIR/core/loader \
    $$ROOT_SRC_DIR/third_party/qt \
    $$ROOT_SRC_DIR/core/msg

HEADERS += \
    $$ROOT_SRC_DIR/core/queue/queue.h \
    $$ROOT_SRC_DIR/core/loader/loader.h \
    $$ROOT_SRC_DIR/core/loader/front_loader.h \
    $$ROOT_SRC_DIR/third_party/qt/base_types.h \
    $$ROOT_SRC_DIR/third_party/qt/application.h \
    $$ROOT_SRC_DIR/core/queue/queue_storage.h \
    $$ROOT_SRC_DIR/core/msg/message_event.h \
    $$ROOT_SRC_DIR/core/msg/message_types.h

SOURCES += \
    $$ROOT_SRC_DIR/core/loader/main.cpp \
    $$ROOT_SRC_DIR/core/queue/queue.cpp \
    $$ROOT_SRC_DIR/core/loader/front_loader.cpp \
    $$ROOT_SRC_DIR/core/queue/queue_storage.cpp \
    $$ROOT_SRC_DIR/core/msg/message_event.cpp


# afront global defines
DEFINES += FRONT_BUILD_MODE=1
