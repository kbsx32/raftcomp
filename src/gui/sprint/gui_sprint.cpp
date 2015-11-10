/*
 * Rafting competition dispatcher program.
 *
 * Gui sprint window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>

#include "gui_sprint.h"
#include "../gui.h"

/* default constructor */
rfc::gui::Sprint::Sprint(Dispatcher *dispatcher, QWidget *parent) :
	rfc::disc::Sprint(dispatcher),
	DiscAbstract(parent)
{
	setSizePolicy(QSizePolicy::Minimum,
				  QSizePolicy::Minimum);
} /* end of 'Qualify' constructor */

/* activate competition */
void rfc::gui::Sprint::activateDiscipline()
{
	/* check if previous stage is finalized */
	if (dispatcher->compareDisciplinesOrder(disc::TypeDisc::SPRINT) > 0) {

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

	/* main table */
	rideTable = new gui::ride::Ride(*dispatcher, disc::Type(currentStage), this);

	sortStartTeams();
	rideTable->addTeams(rides[currentStage]);

	layout()->addWidget(rideTable);
} /* end of 'slotActivateButtonClicked' slot */

void rfc::gui::Sprint::slotChangePushpinsCount(int countNew)
{
	dispatcher->setPinsCount(disc::TypeDisc::SPRINT, countNew);

	rideTable->updateTable();
} /* end of 'slotChangePushpinsCount' function */

/* finalization virtual function.
 * get signal to prepare child-class
 * widgets to set disabled or hided.
 */
void rfc::gui::Sprint::finalizeDiscipline()
{
	/* set disabled all widgets */
	setEnabled(false);

	dispatcher->addProtocol(disc::TypeDisc::SPRINT, getProtocol());
	dispatcher->setNextDiscipline();
} /* end of 'finalizeDiscipline' function */
