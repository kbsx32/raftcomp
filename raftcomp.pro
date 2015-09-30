#-------------------------------------------------
#
# Project created by QtCreator 2015-08-14T20:55:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raftcomp
TEMPLATE = app


SOURCES += \
    src/core/team.cpp \
    src/core/dispatcher.cpp \
    src/core/discipline/disciplines.cpp \
    src/core/base/laptime.cpp \
    src/core/base/exception.cpp \
    src/main.cpp \
    src/core/base/rstring.cpp \
    src/gui/gui_ride.cpp \
    src/gui/gui_ride_item.cpp \
    src/gui/gui_mandat.cpp \
    src/core/discipline/ride_team.cpp \
    src/gui/gui_ride_pushpins.cpp

HEADERS  += \
    src/core/team.h \
    src/core/def.h \
    src/core/dispatcher.h \
    src/core/discipline/disciplines.h \
    src/core/base/laptime.h \
    src/gui/gui.h \
    src/raftcomp.h \
    src/core/base/exception.h \
    src/core/base/rstring.h \
    src/gui/gui_ride.h \
    src/gui/gui_mandat.h \
    src/core/discipline/ride_team.h \
    src/gui/gui_ride_item.h

# FORMS    +=

QMAKE_CXXFLAGS += -std=c++11 -msse2 -Wno-reorder
