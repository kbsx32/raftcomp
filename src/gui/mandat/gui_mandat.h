/*
 * Rafting competition dispatcher program.
 *
 * Gui lap table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */


#pragma once
#ifndef RFC_GUI_MANDAT_H
#define RFC_GUI_MANDAT_H

#include <QWidget>

/* 'raftcomp' support namespace */
namespace rfc {
	/* graphical user interface elements namespace */
	namespace gui {

		class MandatTeam : public QWidget
		{
			;
		}; /* end of 'MandatTeam' class */

		// class MandatMen
		class Mandat : public QWidget
		{
			Q_OBJECT
		public:
			/* default constructor */
			explicit Mandat(QWidget *parent = 0);

		signals:

		public slots:
		}; /* end of 'Mandat' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_MANDAT_H */
