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
#include "gui_mandat.h"

/* constructor by pointer of team. */
rfc::gui::MandatTeamIntro::MandatTeamIntro(men::Team *team, QWidget *parent) :
	team(team), QWidget(parent)
{
	QHBoxLayout *layout = new QHBoxLayout(this);
	setLayout(layout);

	QLabel *teamInfo = new QLabel(this);
	teamInfo->setEnabled(false);
	teamInfo->setText(team->getIdString() + " : " + team->getSurnames());

	layout->addWidget(teamInfo);

	QPushButton *editButton = new QPushButton(lang::edit, this);
	editButton->setFixedSize(100, 30);
	layout->addWidget(editButton);

} /* end of 'MandatTeamMinimal' constructor */

/* default constructor */
rfc::gui::Mandat::Mandat(rfc::Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);

	// lay->addWidget(new QLabel("mandat window"));

	for (rfc::men::Team *team : dispatcher->teams)
		layout->addWidget(new MandatTeamIntro(team, this));

} /* end of 'Mandat' constructor */
