#-------------------------------------------------
#
# Project created by QtCreator 2015-08-14T20:55:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raftcomp
TEMPLATE = app

debug {
	DEFINES += RFC_DEBUG

	# sets current directory as project directory.
	DEFINES += RFC_SET_APP_DIR_AS_PROJ
}

release {
	DEFINES += RFC_RELEASE RFC_NO_DEBUG
}

SOURCES += \
    src/main.cpp \
    src/core/dispatcher.cpp \
    src/core/discipline/disciplines.cpp \
    src/core/base/laptime.cpp \
    src/core/base/exception.cpp \
    src/core/base/rstring.cpp \
    src/core/discipline/ride_team.cpp \
    src/gui/mandat/gui_mandat.cpp \
    src/core/base/memleak.cpp \
    src/gui/ridetable/gui_ride.cpp \
    src/gui/ridetable/gui_ride_item.cpp \
    src/gui/ridetable/gui_ride_pushpins.cpp \
    src/gui/gui_window_main.cpp \
    src/gui/gui_menu.cpp \
    src/lang_translate.cpp \
    src/gui/gui_greet.cpp \
    src/core/humen/team.cpp \
    src/core/humen/human.cpp \
    src/gui/mandat/gui_mandat_men.cpp \
    src/gui/mandat/gui_mandat_team.cpp

HEADERS  += \
    src/core/def.h \
    src/core/dispatcher.h \
    src/core/discipline/disciplines.h \
    src/core/base/laptime.h \
    src/gui/gui.h \
    src/raftcomp.h \
    src/core/base/exception.h \
    src/core/base/rstring.h \
    src/gui/gui_ride.h \
    src/core/discipline/ride_team.h \
    src/gui/gui_ride_item.h \
    src/gui/mandat/gui_mandat.h \
    src/core/base/memleak.h \
    src/gui/ridetable/gui_ride.h \
    src/gui/ridetable/gui_ride_item.h \
    src/gui/gui_window_main.h \
    src/gui/gui_menu.h \
    src/lang_translate.h \
    src/gui/gui_greet.h \
    src/core/humen/team.h \
    src/core/humen/human.h

# FORMS    +=

QMAKE_CXXFLAGS += -std=c++11 -msse2 -Wno-reorder -Wno-unused-parameter
