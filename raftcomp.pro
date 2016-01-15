#
# Rafting competition dispatcher program.
#
# Qt '.pro' file.
#
# kbsx32. <kbsx32@yandex.ru>.
#

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raftcomp
TEMPLATE = app

VERSION = 0.0.0.0

debug {
	DEFINES += RFC_DEBUG

	# sets current directory as project directory.
	DEFINES += RFC_SET_APP_DIR_AS_PROJ
}

release {
	DEFINES += RFC_RELEASE RFC_NO_DEBUG
}

INCLUDEPATH += .
QMAKE_CXXFLAGS += -std=c++11 -msse2 -Wno-reorder -Wno-unused-parameter -Wno-sized-deallocation

SOURCES += \
    src/main.cpp \
    src/core/dispatcher.cpp \
    src/core/base/laptime.cpp \
    src/core/base/exception.cpp \
    src/core/base/rstring.cpp \
    src/core/discipline/ride_team.cpp \
    src/core/discipline/disc_type.cpp \
    src/core/discipline/disctypes/disc_abstract.cpp \
    src/core/discipline/protocol.cpp \
    src/core/humen/team.cpp \
    src/core/humen/human.cpp \
    src/core/base/memleak.cpp \
    src/gui/ridetable/gui_ride.cpp \
    src/gui/ridetable/gui_ride_item.cpp \
    src/gui/ridetable/gui_ride_pushpins.cpp \
    src/gui/gui_window_main.cpp \
    src/gui/gui_greet.cpp \
    src/gui/qualify/gui_qualify.cpp \
    src/gui/mandat/gui_mandat_men.cpp \
    src/gui/mandat/gui_mandat.cpp \
    src/gui/mandat/gui_mandat_team.cpp \
    src/core/discipline/disctypes/disc_qualify.cpp \
    src/gui/discabstr/gui_disc_abstract.cpp \
    src/gui/longrace/gui_longrace.cpp \
    src/core/discipline/disctypes/disc_longrace.cpp \
    src/core/discipline/disctypes/disc_slalom.cpp \
    src/gui/slalom/gui_slalom.cpp \
    src/core/discipline/disctypes/disc_sprint.cpp \
    src/gui/sprint/gui_sprint.cpp \
    src/lang/lang_translate_en.cpp \
    src/lang/lang_translate_ru.cpp \
    src/gui/protocol/gui_protocol.cpp

HEADERS  += \
    src/raftcomp.h \
    src/core/def.h \
    src/core/dispatcher.h \
    src/core/base/laptime.h \
    src/core/base/exception.h \
    src/core/base/rstring.h \
    src/core/discipline/ride_team.h \
    src/core/base/memleak.h \
    src/core/humen/team.h \
    src/core/humen/human.h \
    src/core/discipline/ \
    src/core/discipline/disc_type.h \
    src/core/discipline/disciplines.h \
    src/core/discipline/protocol.h \
    src/gui/gui.h \
    src/gui/gui_window_main.h \
    src/gui/mandat/gui_mandat.h \
    src/gui/ridetable/gui_ride.h \
    src/gui/ridetable/gui_ride_item.h \
    src/gui/gui_greet.h \
    src/gui/qualify/gui_qualify.h \
    src/gui/discabstr/gui_disc_abstract.h \
    src/gui/longrace/gui_longrace.h \
    src/gui/slalom/gui_slalom.h \
    src/gui/sprint/gui_sprint.h \
    src/lang/lang_translate.h \
    src/gui/protocol/gui_protocol.h
