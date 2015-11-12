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

	QHBoxLayout *butsLay = new QHBoxLayout;

	activator = new QPushButton(lang::activate, this);
	connect(activator, SIGNAL(clicked(bool)),
			this, SLOT(slotActivateDiscipline()));

	butsLay->addWidget(activator);

	/* finalizer button */
	finalizer = new QPushButton(lang::finalize, this);
	finalizer->setEnabled(false);
	connect(finalizer, SIGNAL(clicked(bool)),
			this, SLOT(slotFinalize()));

	butsLay->addWidget(finalizer);

	lay->addLayout(butsLay);
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
void rfc::gui::DiscAbstract::setActivated()
{
	activator->setEnabled(false);
	finalizer->setEnabled(true);
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

/* show confirm question message
 * that user wants to finalize.
 * returns result of confirmation.
 * (true if user answered to finish).
 */
bool rfc::gui::DiscAbstract::showMessageSureToFinalize()
{
	QMessageBox qmbox;

	qmbox.setText(lang::sureToFinalizeStage);
	qmbox.addButton(QMessageBox::Yes);
	qmbox.addButton(QMessageBox::No);

	/* return result */
	return qmbox.exec() == QMessageBox::Yes;
} /* end of 'showMessageNotReady' function */

void rfc::gui::DiscAbstract::finalizeDiscipline()
{
	/* it's just virtual function =) */
} /* end of 'finalize' function */

/* activate distance */
void rfc::gui::DiscAbstract::slotFinalize()
{
	/* it is better to don't use virtual slots
	 * somebody talks.
	 */

	/* check users brain */
	if (showMessageSureToFinalize())
		finalizeDiscipline();
} /* end of 'slotFinalize' function */

/* hide finalizer button.
 * it can give manual disable
 * for some disciplines.
 */
void rfc::gui::DiscAbstract::hideFinalizer()
{
	finalizer->hide();
} /* end of 'hideFinalizer' function */
