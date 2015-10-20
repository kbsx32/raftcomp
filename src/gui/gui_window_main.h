/*
 * Rafting competition dispatcher program.
 *
 * Gui main window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_GREET_H
#define RFC_GUI_GREET_H

#include <QWidget>
#include <QSplitter>

#include "../core/dispatcher.h"
#include "ridetable/gui_ride.h"

#include "gui_menu.h"
#include "mandat/gui_mandat.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* graphical user interface elements namespace */
	namespace gui
	{
		/* main window class */
		class WindowMain : public QSplitter
		{
			Q_OBJECT

			Dispatcher *dispatcher;   /* dispatcher linked to this window */
		public:
			/* main window constructor */
			WindowMain(Dispatcher *dispatcher, QWidget *parent = nullptr);

		public slots:
			/* change right-side window state */
			void slotChangeDiscipline(rfc::disc::TypeDisc typeNew);

			/* change right-side window state */
			void slotChangeToMandat();
		}; /* end of 'WindowMain' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_GREET_H */
