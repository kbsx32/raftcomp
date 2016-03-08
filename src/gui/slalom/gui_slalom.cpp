/*
 * Rafting competition dispatcher program.
 *
 * Gui slalom window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QTabWidget>

#include "gui_slalom.h"
#include "../gui.h"

/* default constructor */
rfc::gui::Slalom::Slalom(Dispatcher *dispatcher, QWidget *parent) :
	rfc::disc::Slalom(dispatcher),
	DiscAbstract(parent)
{
	setSizePolicy(QSizePolicy::Minimum,
				  QSizePolicy::Minimum);

    if (dispatcher->checkIsDisciplineFinished(disc::TypeDisc::SLALOM))
        activateDiscipline();
} /* end of 'Qualify' constructor */

/* activate competition */
void rfc::gui::Slalom::activateDiscipline()
{
	/* check if previous stage is finalized */
	if (dispatcher->setDiscipline(disc::TypeDisc::SLALOM) == disc::Rides::DiscState::WAS_NOT) {

		DiscAbstract::showMessageNotReady();
		return ;
	}

	DiscAbstract::setActivated();

	/* pushpins changer */
    pushPins = new QSpinBox(this);
    pushPins->setPrefix(lang::pins);
    pushPins->setRange(0, 30);
    pushPins->setButtonSymbols(QSpinBox::PlusMinus);
    connect(pushPins , SIGNAL(valueChanged(int)),
			this, SLOT(slotChangePushpinsCount(int)));

    pushPins->setValue(getPinsCount());
    pushPins->update();

    widget()->layout()->addWidget(pushPins);

	/* switcher between two tries */
	QTabWidget *tabWidget = new QTabWidget;

	/* disconnecting auto calling higher widgets */
	// disconnect((QAbstractButton *)tabWidget, SIGNAL(clicked(bool)));

    widget()->layout()->addWidget(tabWidget);

	/* main tables */
	init();

	rideTable1 = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeSlalom::SLALOM_1), this);
	rideTable1->addTeams(rides[0]);
	tabWidget->addTab(rideTable1, lang::slalom1);

	rideTable2 = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeSlalom::SLALOM_2), this);
	rideTable2->addTeams(rides[1]);
	tabWidget->addTab(rideTable2, lang::slalom2);

	if (dispatcher->checkIsDisciplineFinished(disc::TypeDisc::SLALOM))
		finalizeDiscipline();
} /* end of 'slotActivateButtonClicked' slot */

void rfc::gui::Slalom::slotChangePushpinsCount(int countNew)
{
	dispatcher->setPinsCount(disc::TypeDisc::SLALOM, countNew);

	rideTable1->updateTable();
	rideTable2->updateTable();
} /* end of 'slotChangePushpinsCount' function */

/* finalization virtual function.
 * get signal to prepare child-class
 * widgets to set disabled or hided.
 */
void rfc::gui::Slalom::finalizeDiscipline()
{
	/* set disabled all widgets */
    rideTable1->setEnabled(false);
    rideTable2->setEnabled(false);
    pushPins->setEnabled(false);

	dispatcher->addProtocol(disc::TypeDisc::SLALOM, getProtocol());
	dispatcher->finishDiscipline();

    hideFinalizer();
    setFinished();
} /* end of 'finalizeDiscipline' function */
