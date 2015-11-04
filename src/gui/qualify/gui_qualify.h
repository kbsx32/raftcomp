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
		public:
			/* default constructor */
			Qualify(QWidget *parent = nullptr);
		}; /* end of 'Qualify' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_QUALIFY_H */
