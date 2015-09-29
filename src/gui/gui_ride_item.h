/*
 * Rafting competition dispatcher program.
 *
 * Gui table widget items declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_RIDE_ITEM_H
#define RFC_GUI_RIDE_ITEM_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>

#include "../core/dispatcher.h"

/* 'raftcomp' support namespace */
namespace rfc {
	namespace gui {
		class RideItem : public QLineEdit
		{
			Q_OBJECT

			RideTeam *lap;      /* connected to this widget lap */
			Team *team;         /* connected team */
		public:
			enum class Type {
				TEAM_ID,		/* team number */
				TEAM_HUMEN,     /* team humen */
				PINS,			/* pushpins */
				PENALTY_OTHER,	/* other penalties slot
								 * for example : bad team start, etc.
								 */
				PENALTY_SUM,	/* result penalty */
				TIME_START,		/* start lap time slot */
				TIME_END,		/* end lap time slot */
				TIME_DISTANCE,  /* distance time */
				TIME_RESULT,    /* summary time */
				PLACE,			/* place in lap */
				SCORE,			/* score given for that plaguice */
				END,            /* Last table slot */
			}; /* end of 'Type' enum class */

			Type type;					/* global semantics */

			/* class constructor.
			 * arguments:
			 *   team : connected team.
			 *   lapConnected : Lap connected with current element.
			 *   controlType : Lap subitem to control.
			 */
			RideItem(Team *team, RideTeam *lapConnected, Type controlType);

			/* update info function */
			void update();
		signals:
			/* signal editing of text finished */
			void signalTextEdited();
		public slots:

			/* capture changed text slot */
			void slotTextChanged();
		};
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_RIDE_ITEM_H */
