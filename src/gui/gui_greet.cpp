/*
 * Rafting competition dispatcher program.
 *
 * Gui greeting window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QApplication>
#include <QDesktopWidget>
#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>

#include "gui_greet.h"
#include "gui_window_main.h"

/* window greeting constructor */
rfc::gui::WindowGreet::WindowGreet(QWidget *parent) :
	QWidget(parent)
{
	/* moving widget to screen center */
	QRect scr = QApplication::desktop()->screenGeometry();
	move(scr.center() - rect().center() / 2);

	/* creating layout for widgets */
	QVBoxLayout *layout = new QVBoxLayout(this);
	setLayout(layout);

	/* greeting text */
	QTextBrowser *welcomeText = new QTextBrowser(this);
	welcomeText->setText(lang::greetText);

	layout->addWidget(welcomeText);


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

	/* exit button */
	but = new QPushButton(lang::exit, this);
	connect(but, SIGNAL(clicked(bool)),
			this, SLOT(close()));
	layout->addWidget(but);

	/* set not changeble size for greeting window */
	setFixedSize(minimumSize());
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
