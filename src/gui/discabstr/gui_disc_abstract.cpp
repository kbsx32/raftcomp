/*
 * Rafting competition dispatcher program.
 *
 * Gui abstract discipline widget class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QLayout>
#include <QPushButton>
#include <QMessageBox>

#include "gui_disc_abstract.h"

/* default constructor */
rfc::gui::DiscAbstract::DiscAbstract(QWidget *parent) :
	QWidget(parent)
{
	QVBoxLayout *lay = new QVBoxLayout(this);

	activator = new QPushButton(lang::activate);
	connect(activator, SIGNAL(clicked(bool)),
			this, SLOT(slotActivateDiscipline()));

	lay->addWidget(activator);
} /* end of 'Qualify' constructor */

/* activate distance */
void rfc::gui::DiscAbstract::activateDiscipline()
{
	/* it is just virtual function =) */
} /* end of 'slotActivateDiscipline' function */

/* activate distance */
void rfc::gui::DiscAbstract::slotActivateDiscipline()
{
	activateDiscipline();
} /* end of 'slotActivateDiscipline' function */

/* virtualized destructor */
rfc::gui::DiscAbstract::~DiscAbstract()
{
} /* end of 'DiscAbstract' destructor */

/* hide 'accept' and other buttons */
void rfc::gui::DiscAbstract::hideButtons()
{
	activator->hide();
} /* end of 'hideButton' function */

/* show message that there is no
 * possibilities to change discipline.
 */
void rfc::gui::DiscAbstract::showMessageNotReady()
{
	QMessageBox qmbox;

	qmbox.setText(lang::cantActivateDiscipline);
	qmbox.exec();
} /* end of 'showMessageNotReady' function */
