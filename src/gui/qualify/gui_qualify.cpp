/*
 * Rafting competition dispatcher program.
 *
 * Gui qualification window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>

#include "gui_qualify.h"
#include "../gui.h"

/* default constructor */
rfc::gui::Qualify::Qualify(Dispatcher *dispatcher, QWidget *parent) :
	rfc::disc::Qualify(dispatcher),
	DiscAbstract(parent)
{
	setSizePolicy(QSizePolicy::Minimum,
				  QSizePolicy::Minimum);

    if (dispatcher->checkIsDisciplineFinished(disc::TypeDisc::QUALIFY))
        activateDiscipline();
} /* end of 'Qualify' constructor */

/* activate competition */
void rfc::gui::Qualify::activateDiscipline()
{
	if (dispatcher->setDiscipline(disc::TypeDisc::QUALIFY) == disc::Rides::DiscState::WAS_NOT) {
		DiscAbstract::showMessageNotReady();
		return ;
	}

	DiscAbstract::setActivated();

	/* pushpins changer */
    pushPins = new QSpinBox(this);
    pushPins->setPrefix(lang::pins);
    pushPins->setRange(0, 30);
    pushPins->setButtonSymbols(QSpinBox::PlusMinus);
    connect(pushPins, SIGNAL(valueChanged(int)),
			this, SLOT(slotChangePushpinsCount(int)));
    pushPins->setValue(getPinsCount());
    pushPins->update();

    widget()->layout()->addWidget(pushPins);

	/* main table */
	rideTable = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeDisc::QUALIFY), this);

	init();
	rideTable->addTeams(rides);

    widget()->layout()->addWidget(rideTable);

	if (dispatcher->checkIsDisciplineFinished(disc::TypeDisc::QUALIFY))
		finalizeDiscipline();
} /* end of 'slotActivateButtonClicked' slot */

void rfc::gui::Qualify::slotChangePushpinsCount(int countNew)
{
	dispatcher->setPinsCount(disc::TypeDisc::QUALIFY, countNew);

	rideTable->updateTable();
} /* end of 'slotChangePushpinsCount' function */

/* finalization virtual function.
 * get signal to prepare child-class
 * widgets to set disabled or hided.
 */
void rfc::gui::Qualify::finalizeDiscipline()
{
	/* set disabled all widgets */
    // setEnabled(false);

    pushPins->setEnabled(false);
    widget()->setEnabled(false);
	dispatcher->addProtocol(disc::TypeDisc::QUALIFY, getProtocol());
	dispatcher->finishDiscipline();

    setFinished();
} /* end of 'finalizeDiscipline' function */
