/*
 * Rafting competition dispatcher program.
 *
 * Client side program entry point file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QApplication>

#include <QLabel>

#include "core/raftcomp.h"

/* entry point function */
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	QLabel qLab;

	qLab.setText("hell");
	qLab.show();

	rfc::raftcomp rf;
	rfc::Lap lp;

	rfc::Time time0, time1, time;

	time0.set(1, 55, 30, 902);
	time1.set(1, 55, 30, 903);

	time = time1 - time0;

	int
		h = time.getHours(),
		m = time.getMinutes(),
		s = time.getSeconds(),
		ms = time.getMilliSec();

	return app.exec();
} /* end of 'main' function */
