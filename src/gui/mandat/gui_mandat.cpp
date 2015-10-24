/*
 * Rafting competition dispatcher program.
 *
 * Mandat comission teams widget functions implement file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QLabel>
#include <QVBoxLayout>

#include "gui_mandat.h"

/* default constructor */
rfc::gui::Mandat::Mandat(rfc::Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);

	// lay->addWidget(new QLabel("mandat window"));

	for (const rfc::men::Team *team : dispatcher->teams)
		layout->addWidget(new QLabel(team->getIdString() + " : " + team->getSurnames()));

} /* end of 'Mandat' constructor */

