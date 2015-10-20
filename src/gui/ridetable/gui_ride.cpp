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
#include "gui_ride_item.h"

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
	typedef RideItem::Type ColumnType;

	setColumnCount(ENUM_CAST(ColumnType::END));

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
	// setHorizontalHeaderItem(ENUM_CAST(ColumnType::END),				new QTableWidgetItem("other"));

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

/* create and put to table ride item widget */
void rfc::gui::Ride::createRideItem(int row, Team *team, RideItem::Type type)
{
	RideItem *it = new RideItem(team, dispatcher.getLap(lapType.getTeamed(team->id)), type, this);
	setCellWidget(row, ENUM_CAST(type), it);
	connect(it, SIGNAL(signalTextEdited()), this, SLOT(updateTable()));
} /* end of 'Ride::createRideItem' function */

/* add new info to table */
void rfc::gui::Ride::addTeamInfo(Team *team) {
	int row = rowCount();
	setRowCount(row + 1);

	/* import column types */
	typedef RideItem::Type Type;

	for (ulong i = 0; i < ENUM_CAST(Type::END); ++i)
		createRideItem(row, team, static_cast<Type>(i));

} /* end of 'gui::Ride::addLapInfo' function */

/* update table data info */
void rfc::gui::Ride::updateTable() {
	long
		colCnt = columnCount(),
		rowCnt = rowCount();

	for (long y = colCnt - 1; y >= 0; --y)
		for (long x = rowCnt - 1; x >= 0; --x)
			((RideItem *)cellWidget(x, y))->update();
} /* end of 'gui::Ride::updateTable' function */

/* class destructor */
rfc::gui::Ride::~Ride() {
} /* End of '~Ride' class destructor */


