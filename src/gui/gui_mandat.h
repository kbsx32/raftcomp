/*
 * Rafting competition dispatcher program.
 *
 * Gui mandat comission table declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_MANDAT_H
#define RFC_MANDAT_H

#include <QTableWidget>

/* 'raftcomp' support namespace */
namespace rfc {
	class Mandat : public QTableWidget
	{
	public:
		/* class default constructor */
		Mandat();
	}; /* end of 'mandat' class */
} /* end of 'rfc' namespace */

#endif /* RFC_MANDAT_H */
