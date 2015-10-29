/*
 * Rafting competition dispatcher program.
 *
 * Mandat comission teams widget functions implement file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QFormLayout>
#include <QDialog>
#include <QIntValidator>
#include <QLineEdit>
#include <QLayout>
#include <QTreeWidget>

#include "../../core/dispatcher.h"

#include "gui_mandat.h"

/* default constructor */
rfc::gui::mandat::Mandat::Mandat(rfc::Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);

	/* add new team button */
	QPushButton *addTeamBut = new QPushButton(lang::addNewTeam, this);
	connect(addTeamBut, SIGNAL(clicked(bool)),
			this, SLOT(slotCreateNewTeam()));
	layout->addWidget(addTeamBut);

	for (rfc::men::Team *team : dispatcher->teams)
		layout->addWidget(new WTeamIntro(dispatcher, team, this));
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
