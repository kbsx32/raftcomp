/*
 * Rafting competition dispatcher program.
 *
 * Gui qualification window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QVBoxLayout>
#include <QPushButton>
#include "gui_qualify.h"
#include "../gui.h"

/* default constructor */
rfc::gui::Qualify::Qualify(Dispatcher *dispatcher, QWidget *parent) :
	QWidget(parent),
	rfc::disc::Qualify(dispatcher)
{
	QLayout *lay = new QVBoxLayout(this);

	activator = new QPushButton(lang::activate, this);
	connect(activator, SIGNAL(clicked(bool)),
			this, SLOT(slotActivateButtonClicked()));

	lay->addWidget(activator);
} /* end of 'Qualify' constructor */

/* activate competition */
void rfc::gui::Qualify::slotActivateButtonClicked()
{
	activator->hide();

	gui::ride::Ride *guiRide = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeDisc::QUALIFY), this);

	sortStartTeams();
	guiRide->addTeams(rides);

	layout()->addWidget(guiRide);
} /* end of 'slotActivateButtonClicked' slot */
