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
			QPushButton
				*activator,
				*finalizer;			/* start and finish discipline buttons */
		public:
			/* default constructor */
			DiscAbstract(QWidget *parent = nullptr);

			/* virtualized destructor */
			virtual ~DiscAbstract();

			/* change 'accept' button to disabled.
			 * add 'finalizer' button.
			 */
			void setActivated();

			/* virtualized discipline activation.
			 * if activation already done
			 * without problem, child class
			 * must call 'setActivated' to
			 * accept this.
			 */
			virtual void activateDiscipline();

			/* finalization virtual function.
			 * get signal to prepare child-class
			 * widgets to set disabled or hided.
			 */
			virtual void finalizeDiscipline();

			/* show message that there is no
			 * possibilities to change discipline.
			 */
			static void showMessageNotReady();

			/* show confirm question message
			 * that user wants to finalize.
			 * returns result of confirmation.
			 * (true if user answered to finish).
			 */
			static bool showMessageSureToFinalize();

			/* hide finalizer button.
			 * it can give manual disable
			 * for some disciplines.
			 */
			void hideFinalizer();

		public slots:
			/* activate distance */
			void slotActivateDiscipline();

			/* activate distance */
			void slotFinalize();
		}; /* end of 'DiscAbstract' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_DISC_ABSTRACT_H */
