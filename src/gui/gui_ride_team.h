/*
 * Rafting competition dispatcher program.
 *
 * Gui lap single team table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_RIDE_TEAM_H
#define RFC_GUI_RIDE_TEAM_H

#include <QTableWidget>
#include <QTableWidgetItem>

#include "../core/dispatcher.h"

/* 'raftcomp' support namespace */
namespace rfc {
	namespace gui {
		/* forward declaration */
		class Ride;

		/* single team in 'LapTable' class */
		class RideTeam : QObject
		{
			Q_OBJECT

			Team *team;				/* linked team */
			rfc::RideTeam *teamLap;	/* team current lap info */

			Ride *rideTable;		/* linked table */
			ulong tableRow;         /* row in table */
		public:
			enum class ColumnType {
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
			}; /* end of 'ColumnType' enum class */

		public:
			/* default constructor.
			 * arguments:
			 *   dispatcher : competition dispatcher;
			 *   team : connected source team;
			 *   rideTable : connected gui table to get TableItem Widgets;
			 *   row : team row in table 'ride';
			 */
			RideTeam(Dispatcher &dispatcher, Team *team, Ride *rideTable, ulong row);
		}; /* end of 'RideTeam' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_RIDE_TEAM_H */
