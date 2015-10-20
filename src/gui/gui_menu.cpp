/*
 * Rafting competition dispatcher program.
 *
 * Gui left-menu window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QPushButton>
#include <QVBoxLayout>
#include "gui_menu.h"

/* default constructor */
rfc::gui::Menu::Menu(QWidget *parent) :
	QWidget(parent)
{
	QVBoxLayout *lay = new QVBoxLayout(this);

	setLayout(lay);

	/* mandat connection button */
	QPushButton *butMandat = new QPushButton(lang::mandat, this);
	connect(butMandat, SIGNAL(clicked(bool)),
			this, SLOT(slotChangeToMandat()));
	lay->addWidget(butMandat);

	/* other buttons */
	lay->addWidget(new MenuDisciplineItem(lang::qualify,	disc::TypeDisc::QUALIFY,   this));
	lay->addWidget(new MenuDisciplineItem(lang::sprint,		disc::TypeDisc::SPRINT,	   this));
	lay->addWidget(new MenuDisciplineItem(lang::slalom0,	disc::TypeDisc::SLALOM_0,  this));
	lay->addWidget(new MenuDisciplineItem(lang::slalom1,	disc::TypeDisc::SLALOM_1,  this));
	lay->addWidget(new MenuDisciplineItem(lang::longRace,	disc::TypeDisc::LONG_RACE, this));
} /* End of 'gui::Menu' constructor */

/* recapturer of discipline changing slot */
void rfc::gui::Menu::slotChangeDisipline(const rfc::disc::TypeDisc typeNew)
{
	emit signalChangeDiscipline(typeNew);
} /* end of 'rfc::gui::Menu::slotChangeDisipline' function */

/* recapturer of changing slot */
void rfc::gui::Menu::slotChangeToMandat()
{
	emit signalChangeToMandat();
} /* end of 'rfc::gui::Menu::slotChangeDisipline' function */

/*
 * single item functions.
 */

/* default constructor.
 * arguments:
 *   title : text in button.
 *   type : type of 'back-signal', sending where button is clicked.
 *   connector : menu widget : binds signal 'signalChangeDiscipline'
 *               to 'menu' slot 'slotChangeDiscipline'.
 */
rfc::gui::MenuDisciplineItem::MenuDisciplineItem(
			const rfc::String &title,
			const rfc::disc::TypeDisc type, gui::Menu *connector) :
	discipline(type),
	QPushButton(title, connector)
{
	/* capture clicked() signal */
	connect(this, SIGNAL(clicked(bool)),
			this, SLOT(slotClicked()));

	/* connecting signal to parent widget */
	connect(this,		SIGNAL(signalChangeDiscipline(rfc::disc::TypeDisc)),
			connector,	SLOT(slotChangeDisipline(rfc::disc::TypeDisc)));
} /* end of 'gui::MenuDisciplineItem' constructor */

/* capturer of automatical clicked slot */
void rfc::gui::MenuDisciplineItem::slotClicked()
{
	emit signalChangeDiscipline(discipline);
} /* end of 'gui::MenuDisciplineItem::slotClicked' function */
