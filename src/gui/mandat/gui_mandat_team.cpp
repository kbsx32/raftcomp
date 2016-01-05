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

/* default oncstructor */
rfc::gui::mandat::WTeam::WTeam(Dispatcher *dispatcher, men::Team *team, QWidget *parent) :
	team(team), dispatcher(dispatcher),
	QWidget(parent),
	layoutHumen(new QFormLayout),

	/* set team info widgets : */
	widgTeamId(new QLineEdit(String::number(team->id), this)),
	widgTeamName(new QLineEdit(team->teamName, this)),
	widgTeamAddress(new QLineEdit(team->address, this))
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	setLayout(layout);

	/*
	 * Global info layout init.
	 */

	QFormLayout
			*layoutTeamGlobalInfo = new QFormLayout,
			*layoutAcceptButtons = new QFormLayout;

	widgTeamId->setValidator(new QIntValidator(this));

	layoutTeamGlobalInfo->addRow(lang::teamId + ":", widgTeamId);
	layoutTeamGlobalInfo->addRow(lang::teamName + ":", widgTeamName);
	layoutTeamGlobalInfo->addRow(lang::teamAddress + ":", widgTeamAddress);

	layout->addLayout(layoutTeamGlobalInfo);

	/*
	 * Humans layout init.
	 */

	/* button to add new human */
	QPushButton *butHumanAdd = new QPushButton(lang::addNewHuman, this);
	connect(butHumanAdd, SIGNAL(clicked(bool)),
			this, SLOT(slotHumanAdd()));

	/*
	butHumanAdd->setFixedSize(WTeam::butSizeX,
							  WTeam::butSizeY);
	*/

	/* humans show */
	uint32_t menCnt = team->men.size();

	// layoutHumen->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

	/* set autostretch */
	// setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// layoutHumen->set
	// layoutHumen->setSizeConstraint(QFormLayout::SizeConstraint);

	/*
	for (uint32_t i = 1; i < menCnt; i += 2)
		layoutHumen->addRow(new WManInfo(dispatcher, team->men[i - 1], this),
							new WManInfo(dispatcher, team->men[i], this));
	*/

	for (uint32_t i = 0; i < menCnt; ++i)
		layoutHumen->addWidget(new WManInfo(dispatcher, team->men[i], this));

	layoutHumen->addWidget(butHumanAdd);

	/* add last human if needed and button to add new human */
	/*
	if (menCnt & 1)
		layoutHumen->addRow(new WManInfo(dispatcher, team->men[menCnt - 1], this), butHumanAdd);
	else
		layoutHumen->addRow(butHumanAdd, new QLabel(""));
	*/

	layout->addLayout(layoutHumen);

	/*
	 * Accept / Decline layout.
	 */

	/* applying button */
	QPushButton *butApply = new QPushButton(lang::apply, this);
	connect(butApply, SIGNAL(clicked(bool)),
			this, SLOT(slotEditApply()));

	QPushButton *butDecline = new QPushButton(lang::decline, this);
	connect(butDecline, SIGNAL(clicked(bool)),
			this, SLOT(deleteLater()));

	/* apply / decline buttons */
	layoutAcceptButtons->addRow(butApply, butDecline);

	layout->addLayout(layoutAcceptButtons);
} /* end of 'MandatTeam' constructor */

/* update widget info function */
void rfc::gui::mandat::WTeam::update()
{
} /* end of 'update' function */

/* apply all changes slot */
void rfc::gui::mandat::WTeam::slotEditApply()
{
	team->id = widgTeamId->text().toInt();
	team->address = widgTeamAddress->text();
	team->teamName = widgTeamName->text();

	emit destroyed();
} /* end of 'slotEditTeamId' function */

/* add new human */
void rfc::gui::mandat::WTeam::slotHumanAdd()
{
	men::Man *manNew = dispatcher->manAdd();
	WMan *widgMan = new WMan(manNew, this);

	/* setup QDialog */
	QDialog qDial;

	connect(widgMan, SIGNAL(destroyed()),
			&qDial, SLOT(close()));

	qDial.setLayout(new QHBoxLayout(&qDial));
	qDial.layout()->addWidget(widgMan);
	qDial.setWindowTitle(lang::addNewHuman);

	qDial.exec();

	team->men.push_back(manNew);

	layoutHumen->insertRow(layoutHumen->rowCount() - 1, new WManInfo(dispatcher, manNew));
} /* end of 'slotHumanAdd' function */

/* constructor by pointer of team. */
rfc::gui::mandat::WTeamIntro::WTeamIntro(Dispatcher *dispatcher, men::Team *team, QWidget *parent) :
	team(team),
	dispatcher(dispatcher),
	QWidget(parent),
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
	teamInfo->setText(team->getIdString() + " : " + team->teamName);
} /* end of 'update' function */

/* slot that pushed 'edit' button */
void rfc::gui::mandat::WTeamIntro::slotClickedEditButton()
{
	QDialog qdial;
	qdial.setLayout(new QFormLayout(&qdial));
	WTeam *mandTeam = new WTeam(dispatcher, team, &qdial);

	/* connect destroying window as closing dialog */
	connect(mandTeam, SIGNAL(destroyed(QObject*)),
			&qdial, SLOT(close()));

	qdial.layout()->addWidget(mandTeam);

	qdial.exec();

	update();
} /* end of 'slotClickedEditButton' function */
