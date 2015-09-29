/*
 * Rafting competition dispatcher program.
 *
 * Gui table widget items implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QTableWidgetItem>

#include "gui_ride_item.h"

/* class constructor.
 * arguments:
 *   team : connected team.
 *   lapConnected : lap connected with current element.
 *   controlType : lap subitem to control.
 */
rfc::gui::RideItem::RideItem(Team *team, RideTeam *lapConnected, Type type) :
	lap(lapConnected), type(type), team(team)
{
	connect(this, SIGNAL(editingFinished()), this, SLOT(slotTextChanged()));
	update();
} /* end of 'gui::RideItem::RideItem' constructor */

/* update info function */
void rfc::gui::RideItem::update()
{
	// QTextEdit *qTextEdit;

	switch (type) {
		case Type::TEAM_ID:		/* team number */
			setEnabled(false);
			setText(team->getIdString());
			break;
		case Type::TEAM_HUMEN:    /* team humen */
			setEnabled(false);
			setText(team->getSurnames());
			break;
		case Type::TIME_START:   /* summary time */
			setText(lap->getTimeStart().getTimeString());
			break;
		case Type::TIME_END:   /* summary time */
			setText(lap->getTimeEnd().getTimeString());
			break;
		case Type::TIME_DISTANCE: /* distance time */
			setEnabled(false);
			setText(lap->getTimeDistance().getTimeString());
			break;
		case Type::TIME_RESULT:   /* summary time */
			setEnabled(false);
			setText(lap->getTimeResult().getTimeString());
			break;
		case Type::PENALTY_OTHER:	/* result penalty */
			setEnabled(false);
			setText("not ready");
			break;
		case Type::PENALTY_SUM:	/* result penalty */
			setEnabled(false);
			setText(lap->getTimePenalty().getTimeString());
			break;
		case Type::SCORE:			/* score given for that plaguice */
			setText("unknown");
			setEnabled(false);
			break;
		case Type::PLACE:			/* place in lap */
			setText("unknown");
			setEnabled(false);
			break;
		case Type::PINS:			/* pushpins */
			setText("not ready");
			break;
		case Type::END:             /* last table slot */
			throw Exception("wrong type");
			break;
	}
} /* end of 'gui::RideItem::update' function */

/* capture changed text slot */
void rfc::gui::RideItem::slotTextChanged()
{
	switch(type) {
		case Type::TIME_START:   /* summary time */
			lap->setTimeStart(Time(text()));
			break;
		case Type::TIME_END:   /* summary time */
			lap->setTimeEnd(Time(text()));
			break;
		case Type::PENALTY_OTHER:	/* result penalty */
			// setEnabled(false);
			// setText("not ready");
			break;
		case Type::PINS:			/* pushpins */
			// setText("not ready");
			break;
		case Type::END:             /* last table slot */
			throw Exception("wrong type");
			break;
		default:
			break;
	}

	emit signalTextEdited();
} /* end of 'gui::RideItem::textChanged' function */
