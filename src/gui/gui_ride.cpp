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

#include "gui_ride.h"

/* default constructor.
 * arguments:
 *   dispatcher : competiotion dispatcher;
 *	 lapType : type of lap (QUALIFY, SPRINT, etc.);
 *   widgParent : parent Qt Widget;
 */
rfc::gui::Ride::Ride(
		Dispatcher &dispatcher,
		const disc::Type type, QWidget *widgParent) :
	lapType(type),
	QTableWidget(widgParent),
	dispatcher(dispatcher)
{
	/* import column types */
	typedef RideTeam::ColumnType ColumnType;

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
} /* end of 'gui::Ride' constructor */

/* erase all data from table */
void rfc::gui::Ride::eraseTable() {
	clear();
} /* end of 'gui::Ride::eraseTable' function */

/* set table item function */
void rfc::gui::Ride::setItemText(const ulong row,
									 const ulong column,
									 const String &string) {
	QTableWidgetItem *item = new QTableWidgetItem((QString)string);
	setItem(row, column, item);
} /* end of 'gui::Ride::setItemText' function */

/* set table item function */
void rfc::gui::Ride::setItemTime(const ulong row,
									 const ulong column,
									 const Time &time) {
	QTableWidgetItem *item = new QTableWidgetItem(time.getTimeString());

	setItem(row, column, item);
} /* end of 'gui::Ride::setItemTime' function */

/* add new info to table */
void rfc::gui::Ride::addTeamInfo(Team *team) {
	setRowCount(rowCount() + 1);

	new RideTeam(dispatcher, team, this, rowCount() - 1);
} /* end of 'gui::Ride::addLapInfo' function */

/* class destructor */
rfc::gui::Ride::~Ride() {
} /* End of '~Ride' class destructor */


