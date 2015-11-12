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
	DiscAbstract(parent),

	butNextStage(new QPushButton(this))
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

		/* disable finalizer button */
		hideFinalizer();
		return ;
	}

	DiscAbstract::setActivated();

	/* TODO : change names for stages */
	tabWidget->addTab(new gui::ride::Ride(*dispatcher, currentStage, this), "step");

	sortStartTeams();
	// rideTable->addTeams(rides[currentStage]);
} /* end of 'slotActivateButtonClicked' slot */

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

/* switching button */
void rfc::gui::Sprint::slotSwitchStage()
{
	if (!switchNextStage())
		slotFinalize(); /* finish if there no more stages */

	tabWidget->addTab(new gui::ride::Ride(*dispatcher, currentStage, this), "step");
} /* end of 'slotSwitchStage' function */
