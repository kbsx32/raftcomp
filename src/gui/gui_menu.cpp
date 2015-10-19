/*
 * Rafting competition dispatcher program.
 *
 * Gui left-menu window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QPushButton>
#include <QVBoxLayout>
#include "gui_window_main.h"

/* default constructor */
rfc::gui::Menu::Menu(QWidget *parent) :
	QWidget(parent)
{
	QVBoxLayout *lay = new QVBoxLayout(this);

	setLayout(lay);

	lay->addWidget(new QPushButton("mandat", this));
	lay->addWidget(new QPushButton("qualification", this));
	lay->addWidget(new QPushButton("sprint", this));
	lay->addWidget(new QPushButton("slalom", this));
	lay->addWidget(new QPushButton("long race", this));
} /* End of 'gui::Menu' constructor */
