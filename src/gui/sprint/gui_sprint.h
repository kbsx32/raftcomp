/*
 * Rafting competition dispatcher program.
 *
 * Gui sprint window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#ifndef RFC_GUI_SPRINT_H
#define RFC_GUI_SPRINT_H

#include <QWidget>
#include <QPushButton>
#include <QTabWidget>

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
		class Sprint : public gui::DiscAbstract,
					   public disc::Sprint
		{
			Q_OBJECT

			QTabWidget *tabWidget;		 /* union of all rides */
			QPushButton *butNextStage;   /* switch to next stage */
		public:
			/* default constructor */
			Sprint(Dispatcher *dispatcher, QWidget *parent = nullptr);

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

		private:
			/* adding new table */
			void addDuelTables(QWidget *widget, const DuelGroup &duels);

			/* get stage name by type sprint */
			rfc::String stageName(const disc::TypeSprint type);

            void activateGuiNextStage();
		public slots:
			/* switching button */
            bool slotSwitchStage();
		}; /* end of 'Sprint' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_SPRINT_H */
