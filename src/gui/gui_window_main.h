/*
 * Rafting competition dispatcher program.
 *
 * Gui main window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_WINDOW_MAIN_H
#define RFC_GUI_WINDOW_MAIN_H

#include <QMainWindow>
#include <QWidget>
#include <QSplitter>
#include <QStackedWidget>

#include "../core/dispatcher.h"
#include "ridetable/gui_ride.h"

#include "gui_menu.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* graphical user interface elements namespace */
	namespace gui
	{
		/* main window class */
		class WindowMain : public QMainWindow
		{
			Q_OBJECT

			/* Right-sided discipline widget */
			QStackedWidget *stackWidgetsFields;
			QSplitter *splitter;

			Dispatcher *dispatcher;   /* dispatcher linked to this window */
		public:
			/* menu-variants */
			enum class FieldType
			{
				MANDAT,
				QUALIFY,
				SPRINT,
				SLALOM,
				LONG_RACE,
			}; /* end of 'FieldType' class */

			/* main window constructor */
			WindowMain(Dispatcher *dispatcher, QWidget *parent = nullptr);
		public slots:
			/* saving dispatcher state slot */
			void slotSavePushed();
		}; /* end of 'WindowMain' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_WINDOW_MAIN_H */
