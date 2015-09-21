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
		rfc::gui::LapTable ltable(rfc::disc::TypeDisc::QUALIFY);

		/*
		rfc::Team tm0(16);
		tm0.men.push_back(rfc::Man("feder", "evgeny"));
		tm0.men.push_back(rfc::Man("ponomareva", "natalia"));
		tm0.men.push_back(rfc::Man("alexeeva", "valentina"));

		ltable.addTeamInfo(&tm0);

		rfc::Team tm1(32);
		tm1.men.push_back(rfc::Man("chuinyshena", "svetlana"));
		tm1.men.push_back(rfc::Man("smirnova", "anna"));
		tm1.men.push_back(rfc::Man("belousova", "victoria"));

		ltable.addTeamInfo(&tm1);
		*/
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
