/*
 * Rafting competition dispatcher program.
 *
 * Gui abstract discipline widget class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#ifndef RFC_GUI_DISC_ABSTRACT_H
#define RFC_GUI_DISC_ABSTRACT_H

#include <QWidget>
#include <QPushButton>

#include "../../core/dispatcher.h"

/* rafting competition namespace */
namespace rfc
{
	/* graphical user interface widgets namespace. */
	namespace gui
	{
		/* dicipline gui class.
		 * note :
		 *   this widget already has layout.
		 */
		class DiscAbstract: public QWidget
		{
			Q_OBJECT

		private:
			QPushButton *activator;

		public:
			/* default constructor */
			DiscAbstract(QWidget *parent = nullptr);

			/* virtualized destructor */
			virtual ~DiscAbstract();

			/* hide 'accept' and other buttons */
			void hideButtons();

			virtual void activateDiscipline();

			/* show message that there is no
			 * possibilities to change discipline.
			 */
			static void showMessageNotReady();
		public slots:
			/* activate distance */
			void slotActivateDiscipline();
		}; /* end of 'Qualify' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_DISC_ABSTRACT_H */
