/*
 * Rafting competition dispatcher program.
 *
 * Mandat comission teams widget functions implement file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QLabel>
#include <QHBoxLayout>

#include "gui_mandat.h"

/* default constructor */
rfc::gui::Mandat::Mandat(rfc::Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QWidget(parent)
{
	QHBoxLayout *lay = new QHBoxLayout(this);

	lay->addWidget(new QLabel("mandat window"));
} /* end of 'Mandat' constructor */

