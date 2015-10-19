/*
 * Rafting competition dispatcher program.
 *
 * Client side program entry point file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <iostream>
#include <QApplication>

#include <QLabel>
#include <QTableView>
#include <QMessageBox>
#include <QDir>
#include <QMap>

#include "core/base/memleak.h"

#include "raftcomp.h"

/* entry point function */
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	try {
		rfc::Dispatcher dispatcher;

		rfc::gui::WindowMain wndMain(&dispatcher);
		wndMain.show();

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
