/*
 * Rafting competition dispatcher program.
 *
 * Gui lap table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_LAP_TABLE_H
#define RFC_LAP_TABLE_H

#include <QTableWidget>

#include "../core/dispatcher.h"
#include "lap_table_team.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* graphical user interface elements namespace */
	namespace gui {
		/* 'Lap' table gui representation */
		class LapTable : public QTableWidget
		{
			Q_OBJECT

			friend class LapTableTeam;				/* get permissions for Lap table team */
			disc::Type lapType;						/* linked to table lap */

		public:
			/* set table item function */
			void setItemText(const ulong row,
							 const ulong column,
							 const String &string);

			/* set table item time function */
			void setItemTime(const ulong row,
							 const ulong column,
							 const Time &time);

		public:
			/* default constructor */
			explicit LapTable(const disc::Type lapType, QWidget *widgParent = nullptr);

			/* class destructor */
			~LapTable();

			/* erase all data from table */
			void eraseTable();

			/* add new info to table */
			void addTeamInfo(Team *team);

		signals:
		public slots:

		}; /* end of 'LapTable' class */
	} /* end of 'gui' namespace */
}  /* end of 'rfc' namespace */

#endif /* RFC_LAP_TABLE_H */
