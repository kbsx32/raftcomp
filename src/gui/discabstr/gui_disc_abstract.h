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
#include "../../core/dispatcher.h"

/* rafting competition namespace */
namespace rfc
{
	/* graphical user interface widgets namespace */
	namespace gui
	{
		/* dicipline gui class */
		class DiscAbstract: public QWidget
		{
		public:
			/* default constructor */
			DiscAbstract(Dispatcher *dispatcher, QWidget *parent = nullptr);
		}; /* end of 'Qualify' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_DISC_ABSTRACT_H */
