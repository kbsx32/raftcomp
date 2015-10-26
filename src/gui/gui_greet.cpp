/*
 * Rafting competition dispatcher program.
 *
 * Gui greeting window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>

#include "gui_greet.h"
#include "gui_window_main.h"

/* window greeting constructor */
rfc::gui::WindowGreet::WindowGreet(QWidget *parent) :
	QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	setLayout(layout);

	QPushButton *but;

	/* create new database */
	but = new QPushButton(lang::createNewDatabase, this);
	connect(but, SIGNAL(clicked(bool)),
			this, SLOT(createDatabase()));

	layout->addWidget(but);

	/* load old database */
	but = new QPushButton(lang::openExistingDatabase, this);
	connect(but, SIGNAL(clicked(bool)),
			this, SLOT(loadDatabase()));

	layout->addWidget(but);
} /* end of 'gui::WindowGreet' constructor */

/* window greeting constructor */
rfc::gui::WindowGreet::~WindowGreet()
{
	// delete windowMain;
} /* end of 'gui::WindowGreet' destructor */

/* start window main.
 * hides current window.
 * becomes visible after Window Main closes.
 */
void rfc::gui::WindowGreet::runWindowMain()
{
	windowMain = new WindowMain(&dispatcher);

	this->setVisible(false);

	/* creating dialog with main-window */
	QDialog qdial;
	qdial.setLayout(new QHBoxLayout);
	qdial.layout()->addWidget(windowMain);
	qdial.exec();

	this->setVisible(true);
} /* end of 'gui::WindowGreet::runWindowMain' function */

/* creating database slot */
void rfc::gui::WindowGreet::createDatabase()
{
	dispatcher.reset();
	runWindowMain();
} /* end of 'WindowGreet::createDatabase' function */

/* loading database slot */
void rfc::gui::WindowGreet::loadDatabase()
{
	QString fileName = QFileDialog::getOpenFileName(this, "competition databse", QString(), "*.dbc");

	/* there are no choose */
	if (fileName.isEmpty())
		return ;

	dispatcher.load(fileName);
	runWindowMain();
} /* end of 'WindowGreet::loadDatabase' function */
