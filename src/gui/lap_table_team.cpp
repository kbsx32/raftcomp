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

#include "lap_table_team.h"
#include "lap_table.h"

/* default constructor.
 * arguments:
 *   team : connected source team
 *   table : connected table to get TableItem Widgets
 *   lap : lap info ( count of pushpins, etc. ) for current team for current ride.
 *   row : team row in table.
 */
rfc::gui::LapTableTeam::LapTableTeam(Team *team, LapTable *table,
									 Lap *lap, ulong row) :
	team(team),
	tableRow(row),
	lapTable(table),
	teamLap(lap),
	QObject(table)
{
	/* write team id */
	lapTable->setItemText(tableRow, ENUM_CAST(ColumnType::TEAM_ID), QString::number(team->id));

	/* set team men names */
	String names;
	for (const auto &man : team->men)
		names += man.lastName + ", ";

	// QTableWidgetItem *qtwd = new QTableWidgetItem(names);
	// ((QWidget *)qtwd)->setEnabled(false);
	// qtwd->set

	lapTable->setItemText(tableRow, ENUM_CAST(ColumnType::TEAM_HUMEN), names);

	lapTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_START), teamLap->getTimeStart());
	lapTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_END), teamLap->getTimeEnd());
	lapTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_DISTANCE),
						  teamLap->getTimeEnd() - teamLap->getTimeStart());
	lapTable->setItemTime(tableRow, ENUM_CAST(ColumnType::TIME_RESULT), teamLap->getTimeResult());
	// lapTable->timerEvent();
	/*
	PINS
	PENALTY_OTHER
	PENALTY_SUM
	TIME_START
	TIME_END
	TIME_DISTANCE
	TIME_RESULT
	PLACE
	SCORE
	*/

	/* pins table init */
	QTableWidget *tablePins = new QTableWidget(1, lapTable->lap->getPinsCount());
	tablePins->setColumnCount(4);
	tablePins->horizontalHeader()->hide();
	tablePins->verticalHeader()->hide();

	// tablePins->horizontalScrollBar() // ->hide();
	// tablePins->verticalScrollBar()->resize(0, 0);

	tablePins->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tablePins->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	lapTable->setCellWidget(tableRow, ENUM_CAST(ColumnType::PINS), tablePins);
} /* end of 'gui::LapTableTeam' class constructor */

