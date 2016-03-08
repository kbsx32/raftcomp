/*
 * Rafting competition dispatcher program.
 *
 * Gui long race window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>

#include "gui_longrace.h"
#include "../gui.h"

/* default constructor */
rfc::gui::LongRace::LongRace(Dispatcher *dispatcher, QWidget *parent) :
	rfc::disc::LongRace(dispatcher),
	DiscAbstract(parent)
{
	setSizePolicy(QSizePolicy::Minimum,
				  QSizePolicy::Minimum);

    if (dispatcher->checkIsDisciplineFinished(disc::TypeDisc::LONG_RACE))
        activateDiscipline();
} /* end of 'LongRace' constructor */

/* activate competition */
void rfc::gui::LongRace::activateDiscipline()
{
	/* check if previous stage is finalized */
	if (dispatcher->setDiscipline(disc::TypeDisc::LONG_RACE) == disc::Rides::DiscState::WAS_NOT) {

		DiscAbstract::showMessageNotReady();
		return ;
	}

	// LongRace::
	DiscAbstract::setActivated();

	/* main table */
	rideTable = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeDisc::LONG_RACE), this);

	init();
	rideTable->addTeams(rides);

    widget()->layout()->addWidget(rideTable);

	if (dispatcher->checkIsDisciplineFinished(disc::TypeDisc::LONG_RACE))
		finalizeDiscipline();
} /* end of 'activateDiscipline' slot */

/* finalization virtual function.
 * get signal to prepare child-class
 * widgets to set disabled or hided.
 */
void rfc::gui::LongRace::finalizeDiscipline()
{
	/* set disabled all widgets */
	setEnabled(false);

	dispatcher->addProtocol(disc::TypeDisc::LONG_RACE, getProtocol());
	dispatcher->finishDiscipline();

    setFinished();
} /* end of 'finalizeDiscipline' function */
