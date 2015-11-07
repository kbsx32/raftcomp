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
} /* end of 'Qualify' constructor */

/* activate competition */
void rfc::gui::Qualify::activateDiscipline()
{
	/* check if previous stage is finalized */
	if (dispatcher->compareDisciplinesOrder(disc::TypeDisc::QUALIFY) > 0) {

		DiscAbstract::showMessageNotReady();
		return ;
	}

	DiscAbstract::setActivated();

	/* pushpins changer */
	QSpinBox *spinBox = new QSpinBox(this);
	spinBox->setPrefix("pushpins : ");
	spinBox->setRange(0, 30);
	spinBox->setButtonSymbols(QSpinBox::PlusMinus);
	connect(spinBox, SIGNAL(valueChanged(int)),
			this, SLOT(slotChangePushpinsCount(int)));

	layout()->addWidget(spinBox);

	/* main table */
	rideTable = new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeDisc::QUALIFY), this);

	sortStartTeams();
	rideTable->addTeams(rides);

	layout()->addWidget(rideTable);
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
	setEnabled(false);

	dispatcher->addProtocol(disc::TypeDisc::QUALIFY, getProtocol());
	dispatcher->setNextDiscipline();
} /* end of 'finalizeDiscipline' function */
