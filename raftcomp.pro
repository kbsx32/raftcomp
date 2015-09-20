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
    src/core/discipline/lap.cpp \
    src/core/base/laptime.cpp \
    src/gui/lap_table.cpp \
    src/gui/mandat.cpp \
    src/core/base/exception.cpp \
    src/main.cpp \
    src/core/base/rstring.cpp

HEADERS  += \
    src/core/team.h \
    src/core/def.h \
    src/core/dispatcher.h \
    src/core/discipline/disciplines.h \
    src/core/discipline/lap.h \
    src/core/base/laptime.h \
    src/gui/lap_table.h \
    src/gui/gui.h \
    src/raftcomp.h \
    src/gui/mandat.h \
    src/core/base/exception.h \
    src/core/base/rstring.h

# FORMS    +=

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -msse2
