/*
 * Rafting competition dispatcher program.
 *
 * Gui lap table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_RIDE_H
#define RFC_GUI_RIDE_H

#include <QTableWidget>

#include "../../core/dispatcher.h"
#include "gui_ride_item.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* graphical user interface elements namespace */
	namespace gui {
		namespace ride
		{
			/* 'RideTeam' table gui representation */
			class Ride : public QTableWidget
			{
				Q_OBJECT

			private:
				friend class RideTeam;			/* get permissions for RideTeam table team */
				disc::Type lapType;				/* linked to table lap */
				Dispatcher &dispatcher;         /* connected team dispatcher */

			public:
				/*
				 * wraps for QtWidgets in table.
				 */

				/* set table item function.
				 * creates QTableWidgetItem. (editable).
				 */
				void setItemText(const uint32_t row,
								 const uint32_t column,
								 const String &string);

				/* set table item time function.
				 * creates QTableWidgetItem. (editable).
				 * note : later must create QtWidget time-editor.
				 */
				void setItemTime(const uint32_t row,
								 const uint32_t column,
								 const Time &time);

			public:
				/* default constructor.
				 * arguments:
				 *   dispatcher : competiotion dispatcher;
				 *	 lapType : type of lap (QUALIFY, SPRINT, etc.);
				 *   widgParent : parent Qt Widget;
				 */
				explicit Ride(
						Dispatcher &dispatcher,
						const disc::Type lapType,
						QWidget *widgParent = nullptr);

				/* class destructor */
				~Ride();

				/* erase all data from table */
				void resetTable();

				/* add new info to table */
				void addTeamInfo(men::Team *team);
				/* add new info to table */
				void addTeamInfo(disc::RideTeam *team);

				/* add teams from dispatcher */
				void addTeamsFromDispatcher();

				/* add new info about teams to table */
				void addTeams(const std::vector<disc::RideTeam *> &rides);

			private:
				/* create and put to table ride item widget */
				void createRideItem(int row, men::Team *team, RideItem::Type type);

			public slots:
				/* update table data info */
				void updateTable();
			}; /* end of 'Ride' class */
		} /* end of 'ride' namespace */
	} /* end of 'gui' namespace */
}  /* end of 'rfc' namespace */

#endif /* RFC_GUI_RIDE_H */
