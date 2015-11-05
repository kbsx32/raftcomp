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

/* rafting competition namespace */
namespace rfc
{
	/* graphical user interface widgets namespace */
	namespace gui
	{
		/* qualify gui class */
		class Qualify : public QWidget,
						public disc::Qualify
		{
			Q_OBJECT

			QPushButton *activator;

		public:
			/* default constructor */
			Qualify(Dispatcher *dispatcher, QWidget *parent = nullptr);

		public slots:
			/* activate competition */
			void slotActivateButtonClicked();
		}; /* end of 'Qualify' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_QUALIFY_H */
