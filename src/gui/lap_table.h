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

/* 'raftcomp' support namespace */
namespace rfc {
	/* graphical user interface elements namespace */
	namespace gui {
		/* 'Lap' table gui representation */
		class LapTable : public QTableWidget
		{
			Q_OBJECT

		public:
			/* default constructor */
			explicit LapTable(QWidget *widgParent = nullptr);


			/* set table item function */
			void setTableItem(const ulong row,
							  const ulong column,
							  const std::string &string);

			/* erase all data from table */
			void eraseTable();

			/* add new info to table */
			void addLapInfo(const Team *team, const Lap &Lap);

		signals:
		public slots:

		}; /* end of 'LapTable' class */
	} /* end of 'gui' namespace */
}  /* end of 'rfc' namespace */

#endif /* RFC_LAP_TABLE_H */
