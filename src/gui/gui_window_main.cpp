/*
 * Rafting competition dispatcher program.
 *
 * Gui main window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QSplitter>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QTabWidget>
#include <QFileDialog>

#include "gui_window_main.h"

#include "mandat/gui_mandat.h"
#include "qualify/gui_qualify.h"
#include "longrace/gui_longrace.h"
#include "slalom/gui_slalom.h"
#include "sprint/gui_sprint.h"
#include "protocol/gui_protocol.h"

/* main window constructor */
rfc::gui::WindowMain::WindowMain(Dispatcher *dispatcher, QWidget *parent) :
	dispatcher(dispatcher), QMainWindow(parent),
	stackWidgetsFields(new QStackedWidget(this)),
	splitter(new QSplitter(this))
{
	/* add splitter to widget */
	setCentralWidget(splitter);

	/* add menu */
	QMenuBar *qMenuBar = new QMenuBar(this);

	/* create 'save' button */
	QAction *act = new QAction(lang::save, qMenuBar);
	connect(act, SIGNAL(triggered(bool)),
			this, SLOT(slotSavePushed()));
	qMenuBar->addAction(act);

	setMenuBar(qMenuBar);

	/* all rules tabs */
	QTabWidget *tabWidget = new QTabWidget(this);
	splitter->addWidget(tabWidget);

	tabWidget->addTab(new gui::mandat::Mandat(dispatcher, this), lang::mandat);

	tabWidget->addTab(new gui::Qualify(dispatcher,  this),	lang::qualify);
	tabWidget->addTab(new gui::Sprint(dispatcher,   this),	lang::sprint);
	tabWidget->addTab(new gui::Slalom(dispatcher,	this),	lang::slalom);
	tabWidget->addTab(new gui::LongRace(dispatcher, this),	lang::longRace);
	tabWidget->addTab(new gui::Protocol(dispatcher, this),	lang::protocol);
} /* end of 'WindowMain' constructor */

/* saving dispatcher state slot */
void rfc::gui::WindowMain::slotSavePushed()
{
	if (dispatcher->getSavingFile() == QString()) {
		/* if no previous saving file */
		QString saveFileName = QFileDialog::getSaveFileName(this, lang::competitionDatabase,
											QString(), String("*") + Dispatcher::fileExt);
		/* if user didn't choose any saving file or pushed 'ESC' */
		if (saveFileName == QString())
			return ;

		/* check is added 'extension to end of the file name */
		if (saveFileName.indexOf(Dispatcher::fileExt) == -1)
			saveFileName += Dispatcher::fileExt;

		dispatcher->setSavingFile(saveFileName);

	}

	dispatcher->save();
} /* end of 'slotSavePushed' function */
