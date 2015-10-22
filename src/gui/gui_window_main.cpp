/*
 * Rafting competition dispatcher program.
 *
 * Gui main window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QLabel>
#include <QSplitter>
#include <QHBoxLayout>

#include "gui_window_main.h"

#include "gui_menu.h"

/* main window constructor */
rfc::gui::WindowMain::WindowMain(Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QSplitter(parent)
{
	/* TODO : make not-changing left-menu widget while swaping active windows */
	setLayout(new QHBoxLayout(this));

	gui::Menu *menu = new gui::Menu(this);

	/* connecting menu signals */
	connect(menu, SIGNAL(signalChangeDiscipline(rfc::disc::TypeDisc)),
			this, SLOT(slotChangeDiscipline(rfc::disc::TypeDisc)));

	connect(menu, SIGNAL(signalChangeToMandat()),
			this, SLOT(slotChangeToMandat()));

	addWidget(menu);

	/* init test teams */
	rfc::Team *tm0 = new rfc::Team(16);
	dispatcher->addTeam(tm0);

	tm0->men.push_back(rfc::Man("feder", "evgeny"));
	tm0->men.push_back(rfc::Man("ponomareva", "natalia"));
	tm0->men.push_back(rfc::Man("alexeeva", "valentina"));
	rfc::RideTeam *rt0 = dispatcher->getLap(rfc::disc::Type(rfc::disc::TypeDisc::QUALIFY, 16));
	rt0->setTimeStart(rfc::Time(1, 11, 59, 0));
	rt0->setTimeEnd(rfc::Time(1, 30, 58, 0));
	rt0->setPinsCount(4);
	// ltable->addTeamInfo(tm0);

	rfc::Team *tm1 = new rfc::Team(32);
	dispatcher->addTeam(tm1);

	tm1->men.push_back(rfc::Man("chuinyshena", "svetlana"));
	tm1->men.push_back(rfc::Man("smirnova", "anna"));
	tm1->men.push_back(rfc::Man("belousova", "victoria"));
	rfc::RideTeam *rt1 = dispatcher->getLap(rfc::disc::Type(rfc::disc::TypeDisc::QUALIFY, 32));
	rt1->setTimeStart(rfc::Time(1, 1, 0, 0));
	rt1->setTimeEnd(rfc::Time(1, 30, 33, 0));
	rt1->setPinsCount(4);
	// ltable->addTeamInfo(tm1);

	rfc::Team *tm2 = new rfc::Team(4);
	dispatcher->addTeam(tm2);

	tm2->men.push_back(rfc::Man("denisov", "pavel"));
	tm2->men.push_back(rfc::Man("tochyonykh", "ksenia"));
	tm2->men.push_back(rfc::Man("kuznetsova", "anna"));
	rfc::RideTeam *rt2 = dispatcher->getLap(rfc::disc::Type(rfc::disc::TypeDisc::QUALIFY, 4));
	rt2->setTimeStart(rfc::Time(1, 1, 0, 0));
	rt2->setTimeEnd(rfc::Time(1, 30, 33, 0));
	rt2->setPinsCount(4);
	// ltable->addTeamInfo(tm2);

	rfc::Team *tm3 = new rfc::Team(8);
	dispatcher->addTeam(tm3);

	tm3->men.push_back(rfc::Man("kislukhina", "katya"));
	tm3->men.push_back(rfc::Man("sennikov", "ivan"));
	tm3->men.push_back(rfc::Man("kapralova", "liza"));
	rfc::RideTeam *rt3 = dispatcher->getLap(rfc::disc::Type(rfc::disc::TypeDisc::QUALIFY, 8));
	rt3->setTimeStart(rfc::Time(1, 1, 0, 0));
	rt3->setTimeEnd(rfc::Time(1, 30, 33, 0));
	rt3->setPinsCount(4);

	dispatcher->save("var/test.db");
	dispatcher->load("var/test.db");
	} /* end of 'WindowMain' constructor */

/* change right-side window state */
void rfc::gui::WindowMain::slotChangeDiscipline(const rfc::disc::TypeDisc type)
{
	widget(1)->deleteLater();

	switch (type) {
		case disc::TypeDisc::QUALIFY:
			addWidget(new QLabel("there will be qualify"));
			break;
		case disc::TypeDisc::SPRINT:
			addWidget(new QLabel("there will be sprint"));
			break;
		case disc::TypeDisc::SLALOM_0:
			addWidget(new QLabel("there will be slalom 0"));
			break;
		case disc::TypeDisc::SLALOM_1:
			addWidget(new QLabel("there will be slalom 1"));
			break;
		case disc::TypeDisc::LONG_RACE:
			addWidget(new QLabel("there will be long race"));
			break;
	}
} /* end of 'gui::WindowMain::slotChangeDiscipline' function */

/* change right-side window state */
void rfc::gui::WindowMain::slotChangeToMandat()
{
	/* setting stretch factors.
	 * set to do not change size when adds new widget.
	 */
	setStretchFactor(0, 0);

	widget(1)->deleteLater();
	insertWidget(1, new gui::Mandat(dispatcher, this));
} /* end of 'gui::WindowMain::slotChangeToMandat' function */
