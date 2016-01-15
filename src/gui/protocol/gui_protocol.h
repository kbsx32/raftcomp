/*
 * Rafting competition dispatcher program.
 *
 * Gui preview protocol window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */


#ifndef RFC_GUI_PROTOCOL_H
#define RFC_GUI_PROTOCOL_H

#include <QWidget>
#include <QTableWidget>

#include "../../core/dispatcher.h"

namespace rfc
{
	namespace gui
	{
		/* previwe protocol gui */
		class Protocol : public QTableWidget
		{
			Q_OBJECT

			Dispatcher *dispatcher;
		public:
			explicit Protocol(Dispatcher *disp, QWidget *parent = nullptr);

			/* reinitting info in table */
			void update();

		public slots:
			/* activated window slot.
			 * calls window updating.
			 */
			void slotWindowActivated();

		}; /* end of 'Protocol' class */
	} /* end of 'gui' */
} /* end of 'rfc' */

#endif /* RFC_GUI_PROTOCOL_H */
