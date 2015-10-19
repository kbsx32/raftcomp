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

/* main window constructor */
rfc::gui::WindowMain::WindowMain(Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QWidget(parent)
{
	// setSizePolicy(QSizePolicy::Policy::Expanding);
	setLayout(new QHBoxLayout(this));

	QSplitter *qsplit = new QSplitter(this);
	layout()->addWidget(qsplit);

	qsplit->addWidget(new Menu(this));

	/* init test teams */
	rfc::gui::Ride *ltable = new rfc::gui::Ride(*dispatcher, rfc::disc::TypeDisc::QUALIFY);

	rfc::Team *tm0 = new rfc::Team(16);
	tm0->men.push_back(rfc::Man("feder", "evgeny"));
	tm0->men.push_back(rfc::Man("ponomareva", "natalia"));
	tm0->men.push_back(rfc::Man("alexeeva", "valentina"));
	rfc::RideTeam *rt0 = dispatcher->getLap(16, rfc::disc::TypeDisc::QUALIFY);
	rt0->setTimeStart(rfc::Time(1, 11, 59, 0));
	rt0->setTimeEnd(rfc::Time(1, 30, 58, 0));
	rt0->setPinsCount(4);
	ltable->addTeamInfo(tm0);

	rfc::Team *tm1 = new rfc::Team(32);
	tm1->men.push_back(rfc::Man("chuinyshena", "svetlana"));
	tm1->men.push_back(rfc::Man("smirnova", "anna"));
	tm1->men.push_back(rfc::Man("belousova", "victoria"));
	rfc::RideTeam *rt1 = dispatcher->getLap(32, rfc::disc::TypeDisc::QUALIFY);
	rt1->setTimeStart(rfc::Time(1, 1, 0, 0));
	rt1->setTimeEnd(rfc::Time(1, 30, 33, 0));
	rt1->setPinsCount(4);
	ltable->addTeamInfo(tm1);

	rfc::Team *tm2 = new rfc::Team(4);
	tm2->men.push_back(rfc::Man("denisov", "pavel"));
	tm2->men.push_back(rfc::Man("tochyonykh", "ksenia"));
	tm2->men.push_back(rfc::Man("kuznetsova", "anna"));
	rfc::RideTeam *rt2 = dispatcher->getLap(4, rfc::disc::TypeDisc::QUALIFY);
	rt2->setTimeStart(rfc::Time(1, 1, 0, 0));
	rt2->setTimeEnd(rfc::Time(1, 30, 33, 0));
	rt2->setPinsCount(4);
	ltable->addTeamInfo(tm2);

	rfc::Team *tm3 = new rfc::Team(8);
	tm3->men.push_back(rfc::Man("kislukhina", "katya"));
	tm3->men.push_back(rfc::Man("sennikov", "ivan"));
	tm3->men.push_back(rfc::Man("kapralova", "liza"));
	rfc::RideTeam *rt3 = dispatcher->getLap(8, rfc::disc::TypeDisc::QUALIFY);
	rt3->setTimeStart(rfc::Time(1, 1, 0, 0));
	rt3->setTimeEnd(rfc::Time(1, 30, 33, 0));
	rt3->setPinsCount(4);
	ltable->addTeamInfo(tm3);

	qsplit->addWidget(ltable);
} /* end of 'WindowMain' constructor */

