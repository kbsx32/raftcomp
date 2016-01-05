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
} /* end of 'Qualify' constructor */

/* activate competition */
void rfc::gui::Slalom::activateDiscipline()
{
	/* check if previous stage is finalized */
	if (dispatcher->compareDisciplinesOrder(disc::TypeDisc::SLALOM) > 0) {

		DiscAbstract::showMessageNotReady();
		return ;
	}

	DiscAbstract::setActivated();

	/* pushpins changer */
	QSpinBox *spinBox = new QSpinBox(this);
	spinBox->setPrefix(lang::pins);
	spinBox->setRange(0, 30);
	spinBox->setButtonSymbols(QSpinBox::PlusMinus);
	connect(spinBox, SIGNAL(valueChanged(int)),
			this, SLOT(slotChangePushpinsCount(int)));

	layout()->addWidget(spinBox);

	/* switcher between two tries */
	QTabWidget *tabWidget = new QTabWidget;

	/* disconnecting auto calling higher widgets */
	// disconnect((QAbstractButton *)tabWidget, SIGNAL(clicked(bool)));

	layout()->addWidget(tabWidget);

	/* main tables */
	init();

	rideTable1 = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeSlalom::SLALOM_1), this);
	rideTable1->addTeams(rides[0]);
	tabWidget->addTab(rideTable1, lang::slalom1);

	rideTable2 = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeSlalom::SLALOM_2), this);
	rideTable2->addTeams(rides[1]);
	tabWidget->addTab(rideTable2, lang::slalom2);
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
	setEnabled(false);

	dispatcher->addProtocol(disc::TypeDisc::SLALOM, getProtocol());
	dispatcher->setNextDiscipline();
} /* end of 'finalizeDiscipline' function */
