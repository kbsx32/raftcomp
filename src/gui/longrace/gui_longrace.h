/*
 * Rafting competition dispatcher program.
 *
 * Gui long race window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#ifndef RFC_GUI_LONGRACE_H
#define RFC_GUI_LONGRACE_H

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
		class LongRace : public gui::DiscAbstract,
						 public disc::LongRace
		{
			Q_OBJECT

			/* main info */
			gui::ride::Ride *rideTable = nullptr;

		public:
			/* default constructor */
			LongRace(Dispatcher *dispatcher, QWidget *parent = nullptr);

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
		}; /* end of 'LongRace' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_LONGRACE_H */
