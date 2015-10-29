/*
 * Rafting competition dispatcher program.
 *
 * Mandat men widget functions implement file.
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
rfc::gui::mandat::WManInfo::WManInfo(rfc::Dispatcher *dispatcher, men::Man *man, QWidget *parent) :
	man(man),
	dispatcher(dispatcher),

	QWidget(parent),
	widgInfo(new QPushButton(this))
{

	// setFixedSize(WTeam::butSizeX, WTeam::butSizeY);

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
