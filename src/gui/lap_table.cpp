/*
 * Rafting competition dispatcher program.
 *
 * Gui lap table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QLabel>
#include <QPushButton>
#include <QHeaderView>
#include <QScrollBar>

#include "lap_table.h"

/* default constructor */
rfc::gui::LapTable::LapTable(Lap *lap, QWidget *widgParent) :
	lap(lap),
	QTableWidget(widgParent)
{
	/* import column types */
	typedef LapTableTeam::ColumnType ColumnType;

	setColumnCount(ENUM_CAST(ColumnType::END) - 1);

	/* set headers */
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TEAM_ID),			new QTableWidgetItem("id"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TEAM_HUMEN),		new QTableWidgetItem("team"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_START),		new QTableWidgetItem("time start"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PENALTY_OTHER),	new QTableWidgetItem("other penalties"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PENALTY_SUM),		new QTableWidgetItem("penalties summary"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PLACE),			new QTableWidgetItem("place"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_START),		new QTableWidgetItem("lap time start"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_END),		new QTableWidgetItem("lap time end"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_DISTANCE),	new QTableWidgetItem("lap time on distance"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_RESULT),		new QTableWidgetItem("result"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PINS),			new QTableWidgetItem("pins"));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::END),				new QTableWidgetItem("other"));

	/* pins table init */
	/* ... */
} /* end of 'gui::LapTable' constructor */

/* erase all data from table */
void rfc::gui::LapTable::eraseTable() {
	clear();
} /* end of 'gui::LapTable::eraseTable' function */

/* set table item function */
void rfc::gui::LapTable::setItemText(const ulong row,
									 const ulong column,
									 const String &string) {
	QTableWidgetItem *item = new QTableWidgetItem((QString)string);
	setItem(row, column, item);
} /* end of 'gui::LapTable::setItemText' function */

/* set table item function */
void rfc::gui::LapTable::setItemTime(const ulong row,
									 const ulong column,
									 const Time &time) {
	QTableWidgetItem *item = new QTableWidgetItem(time.getTimeString());

	setItem(row, column, item);
} /* end of 'gui::LapTable::setItemTime' function */

/* add new info to table */
void rfc::gui::LapTable::addTeamInfo(Team *team, Lap *teamLap) {
	setRowCount(rowCount() + 1);

	new LapTableTeam(team, this, teamLap, rowCount() - 1);
} /* end of 'gui::LapTable::addLapInfo' function */

/* class destructor */
rfc::gui::LapTable::~LapTable() {
} /* End of '~LapTable' class destructor */


