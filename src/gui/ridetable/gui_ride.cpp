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
rfc::gui::ride::Ride::Ride(
		Dispatcher &dispatcher,
		const disc::Type type, QWidget *widgParent) :
	lapType(type),
	QTableWidget(widgParent),
	dispatcher(dispatcher)
{
	updateTable();
} /* end of 'gui::Ride' constructor */

/* add teams from dispatcher */
void rfc::gui::ride::Ride::addTeamsFromDispatcher()
{
	reset();
	for (const auto &team : dispatcher.teams)
		addTeamInfo(team);
} /* end of 'addTeamsFromDispatcher' function */

/* add teams from dispatcher */
void rfc::gui::ride::Ride::addTeams(const std::vector<disc::RideTeam *> &rides)
{
	resetTable();

	/* add all teams */
	for (disc::RideTeam *ride : rides)
		addTeamInfo(dispatcher.getTeam(ride->getTeamId()));

	updateTable();
} /* end of 'addTeamsFromDispatcher' function */

/* erase all data from table */
void rfc::gui::ride::Ride::resetTable() {
	clear();

} /* end of 'gui::Ride::eraseTable' function */

/* set table item function */
void rfc::gui::ride::Ride::setItemText(const uint32_t row,
									 const uint32_t column,
									 const String &string) {
	QTableWidgetItem *item = new QTableWidgetItem((QString)string);
	setItem(row, column, item);
} /* end of 'gui::Ride::setItemText' function */

/* set table item function */
void rfc::gui::ride::Ride::setItemTime(const uint32_t row,
									   const uint32_t column,
									   const Time &time) {
	QTableWidgetItem *item = new QTableWidgetItem(time.getTimeString());

	setItem(row, column, item);
} /* end of 'gui::Ride::setItemTime' function */

/* create and put to table ride item widget */
void rfc::gui::ride::Ride::createRideItem(int row, men::Team *team, RideItem::Type type)
{
	RideItem *it = new RideItem(team, dispatcher.getLap(lapType.getTeamed(team->id)), type, this);
	setCellWidget(row, ENUM_CAST(type), it);
	connect(it, SIGNAL(signalTextEdited()), this, SLOT(updateTable()));
} /* end of 'Ride::createRideItem' function */

/* add new info to table */
void rfc::gui::ride::Ride::addTeamInfo(men::Team *team) {
	int row = rowCount();
	setRowCount(row + 1);

	/* import column types */
	typedef RideItem::Type Type;

	for (uint32_t i = 0; i < ENUM_CAST(Type::END); ++i)
		createRideItem(row, team, static_cast<Type>(i));
} /* end of 'gui::Ride::addLapInfo' function */

/* update table data info */
void rfc::gui::ride::Ride::updateTable() {
	/* import column types */
	typedef RideItem::Type ColumnType;

	setColumnCount(ENUM_CAST(ColumnType::END));

	/* set headers */
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TEAM_ID),			new QTableWidgetItem(lang::id));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TEAM_HUMEN),		new QTableWidgetItem(lang::team));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PENALTY_OTHER),	new QTableWidgetItem(lang::penaltyOther));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PENALTY_SUM),		new QTableWidgetItem(lang::penaltySummary));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_START),		new QTableWidgetItem(lang::timeStart));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_END),		new QTableWidgetItem(lang::timeEnd));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_RESULT),		new QTableWidgetItem(lang::timeResult));

	setHorizontalHeaderItem(ENUM_CAST(ColumnType::TIME_DISTANCE),	new QTableWidgetItem(lang::timeOnDistance));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PLACE),			new QTableWidgetItem(lang::place));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::SCORE),			new QTableWidgetItem(lang::score));
	setHorizontalHeaderItem(ENUM_CAST(ColumnType::PINS),			new QTableWidgetItem(lang::pins));

	/* pins table init */
	/* ... */

	long
		colCnt = columnCount(),
		rowCnt = rowCount();

	for (long y = colCnt - 1; y >= 0; --y)
		for (long x = rowCnt - 1; x >= 0; --x)
			((RideItem *)cellWidget(x, y))->update();
} /* end of 'gui::Ride::updateTable' function */

/* class destructor */
rfc::gui::ride::Ride::~Ride() {
} /* End of '~Ride' class destructor */
