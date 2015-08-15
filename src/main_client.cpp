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

#include "raftcomp.h"

/* entry point function */
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	rfc::gui::LapTable ltable;
	rfc::Lap lap;

	rfc::Team tm0(16);
	tm0.men.push_back(rfc::Man("chuy", "sa"));
	tm0.men.push_back(rfc::Man("kuz", "re"));

	ltable.addLapInfo(&tm0, lap);

	rfc::Team tm1(32);
	tm1.men.push_back(rfc::Man("pon", "na"));
	tm1.men.push_back(rfc::Man("bel", "vv"));
	ltable.addLapInfo(&tm1, lap);

	ltable.show();

	return app.exec();
} /* end of 'main' function */
