/*
 * Rafting competition dispatcher program.
 *
 * Gui qualification window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#ifndef RFC_GUI_QUALIFY_H
#define RFC_GUI_QUALIFY_H

#include <QWidget>
#include <QPushButton>

#include "../../core/dispatcher.h"
#include "../ridetable/gui_ride.h"
#include "../discabstr/gui_disc_abstract.h"

/* rafting competition namespace */
namespace rfc
{
	/* graphical user interface widgets namespace */
	namespace gui
	{
		/* qualify gui class */
		class Qualify : public gui::DiscAbstract,
						public disc::Qualify
		{
			Q_OBJECT

			/* main info */
			gui::ride::Ride *rideTable = nullptr;

		public:
			/* default constructor */
			Qualify(Dispatcher *dispatcher, QWidget *parent = nullptr);

			void activateDiscipline();

		public slots:
			/* change count of pushpins slot */
			void slotChangePushpinsCount(int countNew);

		}; /* end of 'Qualify' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_QUALIFY_H */
