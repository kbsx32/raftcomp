/*
 * Rafting competition dispatcher program.
 *
 * Gui lap table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "lap_table.h"

/* default constructor */
rfc::gui::LapTable::LapTable(QWidget *widgParent) :
	QTableWidget(widgParent)
{
	setColumnCount(4);
	QTableWidgetItem *qwit;

	qwit = new QTableWidgetItem("id");
	setHorizontalHeaderItem(0, qwit);
	qwit = new QTableWidgetItem("team");
	setHorizontalHeaderItem(1, qwit);
	qwit = new QTableWidgetItem("time start");
	setHorizontalHeaderItem(2, qwit);

} /* end of 'gui::LapTable' constructor */

/* erase all data from table */
void rfc::gui::LapTable::eraseTable() {
	clear();
} /* end of 'gui::LapTable::eraseTable' function */

/* set table item function */
void rfc::gui::LapTable::setTableItem(const ulong row,
									  const ulong column,
									  const String &string) {
	QTableWidgetItem *item = new QTableWidgetItem(string.data());
	setItem(row, column, item);
} /* end of 'gui::LapTable::addTableItem' function */

/* add new info to table */
void rfc::gui::LapTable::addLapInfo(const Team *team, const Lap &lap) {
	setRowCount(rowCount() + 1);

	/* write team id */
	setTableItem(rowCount() - 1, 0, QString::number(team->id));

	/* set team men names */
	String names;
	for (const auto &man : team->men)
		names += man.lastName + ", ";
	setTableItem(rowCount() - 1, 1, names);
} /* end of 'gui::LapTable::addLapInfo' function */



