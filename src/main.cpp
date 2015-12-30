/*
 * Rafting competition dispatcher program.
 *
 * Client side program entry point file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QApplication>

#include <QDir>
#include <QMessageBox>

#include "raftcomp.h"

/* entry point function */
int main(int argc, char *argv[])
{

#ifdef RFC_SET_APP_DIR_AS_PROJ
	QDir::setCurrent("../raftcomp");
#endif

	QApplication app(argc, argv);

	/* need to use settings in QSettings */
	app.setOrganizationName(RFC_APP_CREATOR);
	app.setApplicationName(RFC_APP_NAME);

	try {
		rfc::gui::WindowGreet wndGreet;
		wndGreet.show();

		/*
		rfc::Dispatcher dispatcher;
		rfc::gui::WindowMain wndMain(&dispatcher);
		wndMain.show();
		*/

		return app.exec();
	} catch (const rfc::Exception &ex) {
		QMessageBox qmb(QString(rfc::lang::rfcError),
						(QString)ex.getText(),
						QMessageBox::Icon::Critical,
						QMessageBox::Button::Ok, 0, 0);
		qmb.exec();
	}

	return 0;
} /* end of 'main' function */
