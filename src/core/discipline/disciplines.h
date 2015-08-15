/*
 * Rafting competition dispatcher program.
 *
 * Disciplines declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_DISCIPLINES_H
#define RFC_DISCIPLINES_H

#include "lap.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* redifinition of disciplines */
	typedef lap DiscQualify;
	typedef lap DiscSlalom;
	typedef lap DiscLongRace;

	/* parallel sprint discipline declaration */
	class DiscSprint {
		std::vector<Lap> laps;  /* sprint laps */

		// void addNewLap(const Lap &lap);
	};
} /* end of 'rfc' namespace */

#endif /* RFC_DISCIPLINES_H */
