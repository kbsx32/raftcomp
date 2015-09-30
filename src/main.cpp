/*
 * Rafting competition dispatcher program.
 *
 * Client side program entry point file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QApplication>

#include <QLabel>
#include <QTableView>
#include <QMessageBox>
#include <QDir>

#include "raftcomp.h"

/* entry point function */
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	try {
		rfc::Dispatcher dispatcher;

		rfc::gui::Ride ltable(dispatcher, rfc::disc::TypeDisc::QUALIFY);


		rfc::Team tm0(16);
		tm0.men.push_back(rfc::Man("feder", "evgeny"));
		tm0.men.push_back(rfc::Man("ponomareva", "natalia"));
		tm0.men.push_back(rfc::Man("alexeeva", "valentina"));

		rfc::RideTeam *rt0 = dispatcher.getLap(16, rfc::disc::TypeDisc::QUALIFY);
		rt0->setTimeStart(rfc::Time(1, 11, 59, 0));
		rt0->setTimeEnd(rfc::Time(1, 30, 58, 0));
		rt0->setPinsCount(4);

		ltable.addTeamInfo(&tm0);

		rfc::Team tm1(32);
		tm1.men.push_back(rfc::Man("chuinyshena", "svetlana"));
		tm1.men.push_back(rfc::Man("smirnova", "anna"));
		tm1.men.push_back(rfc::Man("belousova", "victoria"));

		rfc::RideTeam *rt1 = dispatcher.getLap(32, rfc::disc::TypeDisc::QUALIFY);
		rt1->setTimeStart(rfc::Time(1, 1, 0, 0));
		rt1->setTimeEnd(rfc::Time(1, 30, 33, 0));
		rt1->setPinsCount(4);

		ltable.addTeamInfo(&tm1);

		ltable.show();

		return app.exec();
	} catch (const rfc::Exception &ex) {
		QMessageBox *qmb =
				new QMessageBox(QString("rfc error"),
						(QString)ex.getText(),
						QMessageBox::Icon::Critical,
						QMessageBox::Button::Ok, 0, 0);
		qmb->exec();

		delete qmb;
	}

	return 0;
} /* end of 'main' function */
