/*
 * Rafting competition dispatcher program.
 *
 * Gui slalom window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#ifndef RFC_GUI_SLALOM_H
#define RFC_GUI_SLALOM_H

#include <QWidget>
#include <QPushButton>
#include <QSpinBox>

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
		class Slalom :  public gui::DiscAbstract,
						public disc::Slalom
		{
			Q_OBJECT

			/* main info */
			gui::ride::Ride *rideTable1 = nullptr;
			gui::ride::Ride *rideTable2 = nullptr;
            QSpinBox *pushPins;

		public:
			/* default constructor */
			Slalom(Dispatcher *dispatcher, QWidget *parent = nullptr);

			/* virtualized discipline activation.
			 * if activation already done
			 * without problem, child class
			 * must call 'setActivated' to
			 * accept this.
			 */
			void activateDiscipline();

			/* finalization virtual function.
			 * get signal to prepare child-class
			 * widgets to set disabled or hided.
			 */
			void finalizeDiscipline();

		public slots:
			/* change count of pushpins slot */
			void slotChangePushpinsCount(int countNew);
		}; /* end of 'Slalom' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_SLALOM_H */
