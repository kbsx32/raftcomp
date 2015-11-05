/*
 * Rafting competition dispatcher program.
 *
 * Gui greeting window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_GREET_H
#define RFC_GUI_GREET_H

#include <QWidget>

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
		/* window main forward declaration */
		class WindowMain;

		/* main window class */
		class WindowGreet : public QWidget
		{
			Q_OBJECT

			rfc::Dispatcher dispatcher;    /* project main dispatcher */
			WindowMain *windowMain = nullptr;

			String openedPreviousFile;		/* previous opened database */
			const String keysetOpenedPrevFile = "openedPrevFile";

		public:
			/* window greet constructor */
			WindowGreet(QWidget *parent = nullptr);

			/* window greet destructor */
			~WindowGreet();

			/* start window main.
			 * hides current window.
			 * becomes visible after Window Main closes.
			 */
			void runWindowMain();

		public slots:
			/* loading database slot */
			void createDatabase();

			/* loading database slot */
			void loadDatabase();

			/* loading database slot */
			void loadDatabasePrev();

		}; /* end of 'WindowMain' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_GREET_H */
