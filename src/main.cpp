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
		/*
		rfc::Lap lap;

		rfc::Team tm0(16);
		tm0.men.push_back(rfc::Man("chuy", "sa"));
		tm0.men.push_back(rfc::Man("kuz", "re"));

		ltable.addLapInfo(&tm0, lap);

		rfc::Team tm1(32);
		tm1.men.push_back(rfc::Man("pon", "na"));
		tm1.men.push_back(rfc::Man("bel", "vv"));
		ltable.addLapInfo(&tm1, lap);

		// ltable.show();
		*/

		QDir qd;
		qd.mkdir("data");

		rfc::Team team;

		team.men.push_back(rfc::Man("golovkina", "valentina"));
		team.men.push_back(rfc::Man("chuyneshena", "svetlana"));
		team.men.push_back(rfc::Man("belousova", "victoria"));

		team.saveToFile("data/team.rtm");

		rfc::Mandat mand;
		mand.show();

	} catch (const rfc::Exception &ex) {
		QLabel qlab("hell");
		qlab.show();

		QLabel ql(ex.getText());
		// ql
		QMessageBox *qmb = new QMessageBox(QString("rfc error"),
						(QString)ex.getText(),
						QMessageBox::Icon::Critical,
						QMessageBox::Button::Ok, 0, 0);
		qmb->exec();
	}

	return app.exec();
} /* end of 'main' function */
