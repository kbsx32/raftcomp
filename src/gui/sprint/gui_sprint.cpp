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
#include <QScrollArea>
#include <QScrollBar>

#include "gui_sprint.h"
#include "../gui.h"

/* default constructor */
rfc::gui::Sprint::Sprint(Dispatcher *dispatcher, QWidget *parent) :
	rfc::disc::Sprint(dispatcher),
	DiscAbstract(parent),

	butNextStage(new QPushButton(lang::nextStage, this)),
	tabWidget(new QTabWidget(this))
{
	setSizePolicy(QSizePolicy::Minimum,
				  QSizePolicy::Minimum);

	/* layout already created on parent-class widget */
	// setLayout(new QVBoxLayout);
	layout()->addWidget(butNextStage);
	layout()->addWidget(tabWidget);

	/* disable finalizer button */
	hideFinalizer();

	butNextStage->hide();

	/* connecting 'next stage' button */
	connect(butNextStage, SIGNAL(clicked(bool)),
			this, SLOT(slotSwitchStage()));
} /* end of 'Qualify' constructor */

/* adding new table */
void rfc::gui::Sprint::addDuelTables(QWidget *widget, const DuelGroup &duels)
{
	uint32_t duelsCnt = duels.size();
	for (uint32_t i = 0; i < duelsCnt; ++i) {
		gui::ride::Ride *ride = new gui::ride::Ride(*dispatcher, currentStage, widget);

		ride->addTeams({duels[i].teams[0], duels[i].teams[1]});

		/* drawing widget */
		widget->layout()->addWidget(
					new QLabel(lang::sprintLap + " #" + QString::number(i + 1), widget));

		widget->layout()->addWidget(ride);
	}
} /* end of 'addDuelTables' function */

/* activate competition */
void rfc::gui::Sprint::activateDiscipline()
{
	/* check if previous stage is finalized */
	if (dispatcher->compareDisciplinesOrder(disc::TypeDisc::SPRINT) > 0) {

		DiscAbstract::showMessageNotReady();
		return ;
	}

	DiscAbstract::setActivated();

	/* creating widget for current table */
	QScrollArea *qRideCurrent = new QScrollArea(this);
	layout()->addWidget(qRideCurrent);

	// QScrollBar *qSCroll = new QScrollBar(qRideCurrent);
	qRideCurrent->addScrollBarWidget(
				new QScrollBar(Qt::Vertical, this), Qt::AlignRight);

	qRideCurrent->setLayout(new QVBoxLayout);
	qRideCurrent->setMouseTracking(true);

	/* show next stage button */
	butNextStage->show();

	/* disable activator button */
	hideActivator();

	/* setting widget */
	tabWidget->setCurrentIndex(0);

	/* generating first list of teams */
	init();

	addDuelTables(qRideCurrent, rides[currentStage]);

	tabWidget->addTab(qRideCurrent, stageName(currentStage));
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
	else {
		QWidget *widgCurrent = new QWidget(this);
		widgCurrent->setLayout(new QVBoxLayout);
		addDuelTables(widgCurrent, rides[currentStage]);

		tabWidget->addTab(widgCurrent, stageName(currentStage));
	}
} /* end of 'slotSwitchStage' function */

/* get stage name by type sprint */
rfc::String rfc::gui::Sprint::stageName(const disc::TypeSprint type)
{
	switch(type) {
		case disc::TypeSprint::SPRINT_1_32:
			return lang::sprint_1_32;
		case disc::TypeSprint::SPRINT_1_16:
			return lang::sprint_1_16;
		case disc::TypeSprint::SPRINT_1_8:
			return lang::sprint_1_8;
		case disc::TypeSprint::SPRINT_1_4:
			return lang::sprint_1_4;
		case disc::TypeSprint::SPRINT_1_2:
			return lang::sprint_1_2;
		case disc::TypeSprint::FINAL_B:
			return lang::sprint_final_b;
		case disc::TypeSprint::FINAL_A:
			return lang::sprint_final_a;
		case disc::TypeSprint::END:
			return lang::errorLogical;

	}

	return "wtf ???";
} /* end of 'stageName' function */
