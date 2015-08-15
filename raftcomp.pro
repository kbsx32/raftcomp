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
    src/main_client.cpp \
    src/core/team_man.cpp \
    src/core/time.cpp \
    src/core/lap.cpp

HEADERS  += \
    src/core/raftcomp.h \
    src/core/team.h \
    src/core/lap.h \
    src/core/time.h \
    src/core/def.h \
    src/core/disciplines.h

FORMS    +=

QMAKE_CXXFLAGS += -std=c++11 -msse2
