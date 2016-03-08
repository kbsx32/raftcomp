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
    tabWidget(new QTabWidget(this)),
	splitter(new QSplitter(this))
{
    this->setWindowTitle(
      QString("raftcomp - ") + dispatcher->getSavingFile());

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
    // QTabWidget *tabWidget = new QTabWidget(this);
	splitter->addWidget(tabWidget);

	tabWidget->addTab(new gui::mandat::Mandat(dispatcher, this), lang::mandat);

    addDisciplineToTab(new gui::Qualify(dispatcher,  this),	lang::qualify);
    addDisciplineToTab(new gui::Sprint(dispatcher,   this),	lang::sprint);
    addDisciplineToTab(new gui::Slalom(dispatcher,	this),	lang::slalom);
    addDisciplineToTab(new gui::LongRace(dispatcher, this),	lang::longRace);

    protocol = new gui::Protocol(dispatcher, this);
    tabWidget->addTab(protocol,	lang::protocol);
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

        if (!saveFileName.contains(".dbc"))
            saveFileName += ".dbc";

		/* check is added 'extension to end of the file name */
		if (saveFileName.indexOf(Dispatcher::fileExt) == -1)
			saveFileName += Dispatcher::fileExt;

		dispatcher->setSavingFile(saveFileName);

	}

	dispatcher->save();
} /* end of 'slotSavePushed' function */

/* protocol updating */
void rfc::gui::WindowMain::slotProtocolUpdate()
{
    protocol->update();
} /* end if 'slotProtocolUpdate' funciton */


/* add new discipline,
 * connect signals
 * and add to tab-widget
 */
void rfc::gui::WindowMain::addDisciplineToTab(gui::DiscAbstract *disc, const String &tabTitle)
{
    connect(disc, SIGNAL(signalDisciplineFinished()),
            this, SLOT(slotProtocolUpdate()));
    tabWidget->addTab(disc, tabTitle);
}
