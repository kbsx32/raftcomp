/*
 * Rafting competition dispatcher program.
 *
 * Gui lap single team table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_LAP_TABLE_TEAM_H
#define RFC_LAP_TABLE_TEAM_H

#include <QTableWidget>
#include <QTableWidgetItem>

#include "../core/dispatcher.h"

/* 'raftcomp' support namespace */
namespace rfc {
	namespace gui {
		/* forward declaration */
		class LapTable;

		/* single team in 'LapTable' class */
		class LapTableTeam : QObject
		{
			Q_OBJECT

			Team *team;				/* linked team */
			Lap *teamLap;           /* team current lap info */

			LapTable *lapTable;		/* linked table */
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
				SCORE,			/* score given for that place */
				END,            /* Last table slot */
			}; /* end of 'ColumnType' enum class */

		public:
			/* default constructor.
			 * arguments:
			 *   team : connected source team
			 *   table : connected table to get TableItem Widgets
			 *   lap : lap info ( count of pushpins, etc. ) for current team for current ride.
			 *   row : team row in table.
			 */
			LapTableTeam(Team *team, LapTable *table, Lap *lap, ulong row);
		}; /* end of 'LapTableTeam' class */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_LAP_TABLE_TEAM_H */
