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

#include "gui_mandat.h"

rfc::gui::mandat::WMan::WMan(men::Man *man, QWidget *parent) :
	man(man), QWidget(parent),
	widgLastName(new QLineEdit(man->lastName, this)),
	widgFirstName(new QLineEdit(man->firstName, this)),
	widgSecondName(new QLineEdit(man->secondName, this)),
	widgRank(new QLineEdit(men::Man::stringRank(man->rank), this)),
	widgBirthYear(new QLineEdit(String::number(man->birthYear), this))
{
	/* help for rank */
	widgRank->setWhatsThis(lang::rankAbout);

	QFormLayout *layout = new QFormLayout(this);
	setLayout(layout);

	QHBoxLayout *layNames = new QHBoxLayout;
	layNames->addWidget(new QLabel(lang::familyNameSecName, this));
	layNames->addWidget(widgLastName);
	layNames->addWidget(widgFirstName);
	layNames->addWidget(widgSecondName);

	layout->addRow(layNames);
	layout->addRow(new QLabel(lang::rank, this), widgRank);
	layout->addRow(new QLabel(lang::birthYear, this), widgBirthYear);

	/* button apply and decline */
	QPushButton *butApply = new QPushButton(lang::apply, this);
	connect(butApply, SIGNAL(clicked(bool)),
			this, SLOT(slotChangesApply()));

	QPushButton *butDecline = new QPushButton(lang::decline, this);
	connect(butDecline, SIGNAL(clicked(bool)),
			this, SLOT(deleteLater()));

	layout->addRow(butApply, butDecline);
} /* end of 'MandatMan' constructor */

/* apply changes slot */
void rfc::gui::mandat::WMan::slotChangesApply()
{
	man->lastName = widgLastName->text();
	man->firstName = widgFirstName->text();
	man->secondName = widgSecondName->text();
	man->rank = men::Man::parseRank(widgRank->text());
	man->birthYear = widgBirthYear->text().toInt();

	emit destroyed();
} /* end of 'slotChangesApply' slot */

/* constructor */
rfc::gui::mandat::WManInfo::WManInfo(men::Man *man, QWidget *parent) :
	man(man), QWidget(parent),
	widgInfo(new QPushButton(this))
{
	QFormLayout *layout = new QFormLayout(this);
	setLayout(layout);

	connect(widgInfo, SIGNAL(clicked(bool)),
			this, SLOT(slotEditClicked()));

	layout->addWidget(widgInfo);

	update();
} /* end of 'WManInfo' constructor */

/* update info */
void rfc::gui::mandat::WManInfo::update()
{
	widgInfo->setText(man->lastName + " " + man->firstName + " " + man->secondName);
} /* end of 'update' function */

/* edit human */
void rfc::gui::mandat::WManInfo::slotEditClicked()
{
	QDialog qdial;
	qdial.setLayout(new QHBoxLayout(&qdial));

	WMan *widgMan = new WMan(man, &qdial);
	connect(widgMan, SIGNAL(destroyed(QObject*)),
			&qdial, SLOT(close()));
	qdial.layout()->addWidget(widgMan);
	qdial.exec();

	/* update all changes */
	update();
} /* end of 'sloEditClicked' slot */

/* default oncstructor */
rfc::gui::mandat::WTeam::WTeam(men::Team *team, QWidget *parent) :
	team(team), QWidget(parent),

	/* set team info widgets : */
	widgTeamId(new QLineEdit(String::number(team->id), this)),
	widgTeamName(new QLineEdit(team->teamName, this)),
	widgTeamAddress(new QLineEdit(team->address, this))
{
	QFormLayout *layout = new QFormLayout(this);

	setLayout(layout);

	widgTeamId->setValidator(new QIntValidator(this));

	layout->addRow(lang::teamId + ":", widgTeamId);
	layout->addRow(lang::teamName + ":", widgTeamName);
	layout->addRow(lang::teamAddress + ":", widgTeamAddress);

	/* humen intro widgets */

	/* intro about team */
	// layout->addRow(lang::participants, new QLabel(lang::name, this));
	layout->addRow(lang::participants, new QLabel("", this));

	uint32_t menCnt = team->men.size();

	for (uint32_t i = 0; i < menCnt; ++i)
		// layout->addRow(String::number(i) + ":", new WManInfo(team->men[i]));
		layout->addRow("", new WManInfo(team->men[i]));

	/* applying button */
	QPushButton *butApply = new QPushButton(lang::apply, this);
	connect(butApply, SIGNAL(clicked(bool)),
			this, SLOT(slotEditApply()));

	QPushButton *butDecline = new QPushButton(lang::decline, this);
	connect(butDecline, SIGNAL(clicked(bool)),
			this, SLOT(deleteLater()));

	/* apply / decline buttons */
	layout->addRow(butApply, butDecline);
} /* end of 'MandatTeam' constructor */

/* apply all changes slot */
void rfc::gui::mandat::WTeam::slotEditApply()
{
	team->id = widgTeamId->text().toInt();
	team->address = widgTeamAddress->text();
	team->teamName = widgTeamName->text();

	emit destroyed();
} /* end of 'slotEditTeamId' function */

/* constructor by pointer of team. */
rfc::gui::mandat::WTeamIntro::WTeamIntro(men::Team *team, QWidget *parent) :
	team(team), QWidget(parent),
	teamInfo(new QLabel(this))
{
	QHBoxLayout *layout = new QHBoxLayout(this);
	setLayout(layout);

	teamInfo->setEnabled(false);
	layout->addWidget(teamInfo);

	/* edit button */
	QPushButton *editButton = new QPushButton(lang::edit, this);

	editButton->setFixedSize(100, 30);

	/* connecting button */
	connect(editButton, SIGNAL(clicked(bool)),
			this, SLOT(slotClickedEditButton()));

	layout->addWidget(editButton);

	update();
} /* end of 'MandatTeamMinimal' constructor */

/* update all widgets info */
void rfc::gui::mandat::WTeamIntro::update()
{
	teamInfo->setText(team->getIdString() + " : " + team->getSurnames());
} /* end of 'update' function */

/* slot that pushed 'edit' button */
void rfc::gui::mandat::WTeamIntro::slotClickedEditButton()
{
	QDialog qdial;
	qdial.setLayout(new QFormLayout(&qdial));
	WTeam *mandTeam = new WTeam(team, &qdial);

	/* connect destroying window as closing dialog */
	connect(mandTeam, SIGNAL(destroyed(QObject*)),
			&qdial, SLOT(close()));

	qdial.layout()->addWidget(mandTeam);

	qdial.exec();

	update();
} /* end of 'slotClickedEditButton' function */

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
		layout->addWidget(new WTeamIntro(team, this));
} /* end of 'Mandat' constructor */

/* pushed button to create new team */
void rfc::gui::mandat::Mandat::slotCreateNewTeam()
{
	men::Team *team = new men::Team;
	dispatcher->addTeam(team);

	WTeamIntro *teamIntro = new WTeamIntro(team, this);

	/* emit button pushed */
	emit teamIntro->slotClickedEditButton();

	/* add widget, connected with this team */
	layout()->addWidget(teamIntro);
} /* end of 'slotCreateNewTeam' slot */
