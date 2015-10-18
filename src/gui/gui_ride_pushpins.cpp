/*
 * Rafting competition dispatcher program.
 *
 * Gui table pushpins widget implement.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QHeaderView>

#include "gui_ride_item.h"

/*
 * single pin global table class functions.
 */

/* construcotr by pin identificator */
rfc::gui::Pin::Pin(rfc::RideTeam *rideTeam, const int pinNumber, gui::PushPins *parent) :
	pinId(pinNumber),
	rideTeam(rideTeam),
	QLineEdit(parent)
{
	setText(String::number(rideTeam->getPins()[pinNumber]));

	/* link signal of finish editing */
	connect(this, SIGNAL(editingFinished()),
			this, SLOT(slotTextChanged()));
} /* end of 'Pin' constructor */

/* 'onFinishEdit' catcher slot */
void rfc::gui::Pin::slotTextChanged()
{
	rideTeam->setPinPenalty(pinId, text().toInt());

	emit signalPinChanged();
} /* end of 'Pin::slotTextChanged' function */

/*
 * PushPins global table class functions.
 */

/* default constructor */
rfc::gui::PushPins::PushPins(rfc::RideTeam *rideTeam, QWidget *parent) :
	QTableWidget(parent)
{
	/* hide headers */
	this->verticalHeader()->hide();
	this->horizontalHeader()->hide();

	/* set autostretch */
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	/* create new pins fields */
	ulong pinsCnt = rideTeam->getPinsCount();

	setRowCount(1);
	setColumnCount(pinsCnt);

	for (ulong i = 0; i < pinsCnt; ++i) {

		Pin *pinNew = new Pin(rideTeam, i, this);

		/* connecting pins changing signal */
		connect(pinNew, SIGNAL(signalPinChanged()),
				this, SLOT(slotPinsChanged()));

		/* set new widget */
		setCellWidget(0, i, pinNew);
	}
} /* end of 'gui::PushPins' constructor */

/* pins changed slot */
void rfc::gui::PushPins::slotPinsChanged() {
	emit signalPinsChanged();
} /* end of 'gui::PushPins::slotPinsChanged' function */

