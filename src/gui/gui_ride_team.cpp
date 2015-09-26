/*
 * Rafting competition dispatcher program.
 *
 * Gui lap single team table implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QLabel>
#include <QHeaderView>
#include <QScrollBar>
#include <QTableWidgetItem>

#include "gui_ride_team.h"
#include "gui_ride.h"

/* default constructor.
 * arguments:
 *   dispatcher : competition dispatcher;
 *   team : connected source team
 *   table : connected table to get TableItem Widgets
 *   row : team row in table.
 */
rfc::gui::RideTeam::RideTeam(Dispatcher &dispatcher, Team *team, Ride *rideTable, ulong row) :
	team(team),
	tableRow(row),
	rideTable(rideTable),
	QObject(rideTable),
	teamLap(dispatcher.getLap(team->id, rideTable->lapType))
{
	/* write team id */
	rideTable->setItemText(tableRow, ENUM_CAST(ColumnType::TEAM_ID), QString::number(team->id));

	/* set team men names */
	String names;
	for (const auto &man : team->men)
		names += man.lastName + ", ";

	// QTableWidgetItem *qtwd = new QTableWidgetItem(names);
	// ((QWidget *)qtwd)->setEnabled(false);
	// qtwd->set

	/* set other values to table */
	rideTable->setItemText(tableRow, ENUM_CAST(ColumnType::TEAM_HUMEN), names);

	rideTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_START), teamLap->getTimeStart());
	rideTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_END), teamLap->getTimeEnd());
	rideTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_DISTANCE),
						  teamLap->getTimeEnd() - teamLap->getTimeStart());
	rideTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_RESULT), teamLap->getTimeResult());

	// lapTable->timerEvent();
	/*
	PINS
	PENALTY_OTHER
	PENALTY_SUM
	PLACE
	SCORE
	*/

	/* pins table init */
	/*
	QTableWidget *tablePins = new QTableWidget(1, lapTable->lap->getPinsCount());
	tablePins->setColumnCount(4);
	tablePins->horizontalHeader()->hide();
	tablePins->verticalHeader()->hide();

	// tablePins->horizontalScrollBar() // ->hide();
	// tablePins->verticalScrollBar()->resize(0, 0);

	tablePins->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tablePins->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	lapTable->setCellWidget(tableRow, ENUM_CAST(ColumnType::PINS), tablePins);
	*/
} /* end of 'gui::LapTableTeam' class constructor */

