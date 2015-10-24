/*
 * Rafting competition dispatcher program.
 *
 * Mandat comission teams widget declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */


#pragma once
#ifndef RFC_GUI_MANDAT_H
#define RFC_GUI_MANDAT_H

#include <QWidget>

/* include all core dispatcher support */
#include "../../core/dispatcher.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* graphical user interface elements namespace */
	namespace gui {

		/* Mandat comission single team drawer class */
		class MandatTeam : public QWidget
		{
			Q_OBJECT

			rfc::Dispatcher *dispatcher;

		public:
			/* default constructor */
			explicit MandatTeam(QWidget *parent = nullptr);
		public:
		}; /* end of 'MandatTeam' class */

		// class MandatMen
		class Mandat : public QWidget
		{
			Q_OBJECT

			rfc::Dispatcher *dispatcher;
		public:
			/* default constructor */
			explicit Mandat(rfc::Dispatcher *dispatcher, QWidget *parent = 0);

		signals:

		public slots:
		}; /* end of 'Mandat' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_MANDAT_H */
