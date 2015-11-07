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

#include "gui_window_main.h"

#include "gui_menu.h"

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

	/* create all child widgets */
	gui::Menu *menu = new gui::Menu(this);

	/* connecting menu signals */
	connect(menu, SIGNAL(signalChangeDiscipline(rfc::disc::TypeDisc)),
			this, SLOT(slotChangeDiscipline(rfc::disc::TypeDisc)));

	connect(menu, SIGNAL(signalChangeToMandat()),
			this, SLOT(slotChangeToMandat()));

	splitter->addWidget(menu);
	splitter->addWidget(stackWidgetsFields);

	stackWidgetsFields->addWidget(new gui::mandat::Mandat(dispatcher, this));

	stackWidgetsFields->addWidget(new gui::Qualify(dispatcher, this));
	stackWidgetsFields->addWidget(new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeDisc::SPRINT),		this));
	stackWidgetsFields->addWidget(new gui::ride::Ride(*dispatcher, disc::Type(disc::TypeDisc::SLALOM),		this));
	stackWidgetsFields->addWidget(new gui::LongRace(dispatcher, this));
} /* end of 'WindowMain' constructor */

rfc::gui::WindowMain::~WindowMain()
{
} /* end of '~WindowMain' function */

/* change right-side window state */
void rfc::gui::WindowMain::slotChangeDiscipline(const rfc::disc::TypeDisc type)
{
	switch (type) {
		case disc::TypeDisc::QUALIFY:
			stackWidgetsFields->setCurrentIndex(ENUM_CAST(FieldType::QUALIFY));
			break;
		case disc::TypeDisc::SPRINT:
			stackWidgetsFields->setCurrentIndex(ENUM_CAST(FieldType::SPRINT));
			break;
		case disc::TypeDisc::SLALOM:
			stackWidgetsFields->setCurrentIndex(ENUM_CAST(FieldType::SLALOM));
			break;
		case disc::TypeDisc::LONG_RACE:
			stackWidgetsFields->setCurrentIndex(ENUM_CAST(FieldType::LONG_RACE));
			break;
		default:
			break;
	}
} /* end of 'gui::WindowMain::slotChangeDiscipline' function */

/* change right-side window state */
void rfc::gui::WindowMain::slotChangeToMandat()
{
	stackWidgetsFields->setCurrentIndex(ENUM_CAST(FieldType::MANDAT));
} /* end of 'gui::WindowMain::slotChangeToMandat' function */

/* saving dispatcher state slot */
void rfc::gui::WindowMain::slotSavePushed()
{
	dispatcher->save();
} /* end of 'slotSavePushed' function */
