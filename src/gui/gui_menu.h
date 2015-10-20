/*
 * Rafting competition dispatcher program.
 *
 * Gui main window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_MENU_H
#define RFC_GUI_MENU_H

#include <QWidget>
#include <QPushButton>

#include "../core/dispatcher.h"
#include "ridetable/gui_ride.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* graphical user interface elements namespace */
	namespace gui
	{
		/* forward class declaration for signals / slots */
		class Menu;

		/* single menu item class.
		 * Needs to make unity style of
		 * buttons pressing.
		 * Any instance of this class-button sends
		 * signal with their type.
		 */
		class MenuDisciplineItem : public QPushButton
		{
			Q_OBJECT

			/* type of menu discipline activator item */
			rfc::disc::TypeDisc discipline;

		public:
			/* default constructor.
			 * arguments:
			 *   title : text in button.
			 *   type : type of 'back-signal', sending where button is clicked.
			 *   connector : menu widget : binds signal 'signalChangeDiscipline'
			 *               to 'menu' slot 'slotChangeDiscipline'.
			 */
			MenuDisciplineItem(
					const rfc::String &title,
					const rfc::disc::TypeDisc type,
					gui::Menu *connector = nullptr);
		signals:
			/* sending signal that button pushed */
			void signalChangeDiscipline(const rfc::disc::TypeDisc type);
		protected slots:
			/* capturer of automatical clicked slot */
			void slotClicked();
		}; /* end of 'MenuItem' class */

		/* Left-side menu class */
		class Menu : public QWidget
		{
			Q_OBJECT

		signals:
			/* change to new discipline signal */
			void signalChangeDiscipline(const rfc::disc::TypeDisc typeNew);

			/* switch to mandat window signal */
			void signalChangeToMandat();
		public:
			/* default constructor */
			Menu(QWidget *parent = nullptr);

		public slots:
			/* recapturer of discipline changing slot */
			void slotChangeDisipline(const rfc::disc::TypeDisc typeNew);

			/* recapturer of changing slot */
			void slotChangeToMandat();
		}; /* end of 'Menu' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_MENU_H */
