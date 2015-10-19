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

#include "../core/dispatcher.h"
#include "ridetable/gui_ride.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* graphical user interface elements namespace */
	namespace gui
	{
		/* Left-side menu class */
		class Menu : public QWidget
		{
			Q_OBJECT

		public:
			/* default constructor */
			Menu(QWidget *parent = nullptr);
		}; /* end of 'Menu' class */

		/* main window class */
		class WindowMain : public QWidget
		{
			Q_OBJECT

			Dispatcher *dispatcher;   /* dispatcher linked to this window */
		public:
			/* main window constructor */
			WindowMain(Dispatcher *dispatcher, QWidget *parent = nullptr);
		}; /* end of 'WindowMain' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_GREET_H */
