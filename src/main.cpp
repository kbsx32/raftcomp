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
		rfc::Lap lap;

		rfc::Team tm0(16);
		tm0.men.push_back(rfc::Man("feder", "evgeny"));
		tm0.men.push_back(rfc::Man("ponomareva", "natalia"));
		tm0.men.push_back(rfc::Man("alexeeva", "valentina"));
		rfc::gui::LapTable ltable(&lap);
		ltable.addTeamInfo(&tm0, &tm0.discQualif);

		rfc::Team tm1(32);
		tm1.men.push_back(rfc::Man("chuyneshena", "svetlana"));
		tm1.men.push_back(rfc::Man("smirnova", "anna"));
		tm1.men.push_back(rfc::Man("belousova", "victoria"));

		ltable.addTeamInfo(&tm1, &tm1.discQualif);

		ltable.show();

		/*
		QDir qd;
		qd.mkdir("data");

		rfc::Team team;

		team.men.push_back(rfc::Man("golovkina", "valentina"));
		team.men.push_back(rfc::Man("chuyneshena", "svetlana"));
		team.men.push_back(rfc::Man("belousova", "victoria"));

		team.saveToFile("data/team.rtm");

		rfc::Mandat mand;
		mand.show();
		*/
		return app.exec();
	} catch (const rfc::Exception &ex) {
		QMessageBox *qmb = new QMessageBox(QString("rfc error"),
						(QString)ex.getText(),
						QMessageBox::Icon::Critical,
						QMessageBox::Button::Ok, 0, 0);
		qmb->exec();

		delete qmb;
	}

	return 0;
} /* end of 'main' function */
