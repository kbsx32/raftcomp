/*
 * Rafting competition dispatcher program.
 *
 * Mandat comission teams widget functions implement file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QFormLayout>
#include <QDialog>
#include <QLineEdit>
#include <QLayout>
#include <QScrollArea>

#include "gui_mandat.h"
#include "../discabstr/gui_disc_abstract.h"

/* default constructor */
rfc::gui::mandat::Mandat::Mandat(rfc::Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QWidget(parent)
{
    QScrollArea *scroll = new QScrollArea;
    scroll->setWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(this);

	QPushButton *buttonFinalize = new QPushButton(lang::finalize);
	connect(buttonFinalize, SIGNAL(clicked(bool)),
			this, SLOT(slotFinalize()));
	layout->addWidget(buttonFinalize);

	/* add new team button */
	QPushButton *addTeamBut = new QPushButton(lang::addNewTeam, this);
	connect(addTeamBut, SIGNAL(clicked(bool)),
			this, SLOT(slotCreateNewTeam()));
	layout->addWidget(addTeamBut);

	for (rfc::men::Team *team : dispatcher->teams)
		layout->addWidget(new WTeamIntro(dispatcher, team, this));

	/* check if mandat comission already done */
	if (dispatcher->isMandatFinished())
		finalize();

    // setMouseTracking(true);
} /* end of 'Mandat' constructor */

/* pushed button to create new team */
void rfc::gui::mandat::Mandat::slotCreateNewTeam()
{
	men::Team *team = new men::Team;
	dispatcher->addTeam(team);

	WTeamIntro *teamIntro = new WTeamIntro(dispatcher, team, this);

	/* emit button pushed */
	emit teamIntro->slotClickedEditButton();

	/* add widget, connected with this team */
	layout()->addWidget(teamIntro);
} /* end of 'slotCreateNewTeam' slot */

/* applying mandat comission */
void rfc::gui::mandat::Mandat::finalize()
{
	dispatcher->setMandatComissionFinished();

	setEnabled(false);
} /* end of 'slotFinalize' function */

/* applying mandat comission */
void rfc::gui::mandat::Mandat::slotFinalize()
{
	/* confirm */
	if (DiscAbstract::showMessageSureToFinalize())
		finalize();
} /* end of 'slotFinalize' function */
