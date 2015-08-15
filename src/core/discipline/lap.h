/*
 * Rafting competition dispatcher program.
 *
 * Single template discipline lap declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_LAP_H_
#define RFC_LAP_H_

#include <vector>
#include "time.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* Single template discipline lap class */
	class Lap {
		Time
			timeStart,						/* start lap time */
			timeEnd,						/* end lap time */
			timePenalty;                    /* penalty time */

		std::vector<long> pinsPenalty;		/* pins penalties */

	public:
		/* default constructor */
		Lap();

		/* set start lap time */
		void setTimeStart(const Time &timeStartNew);
		/* set end lap time */
		void setTimeEnd(const Time &timeEndNew);

		/* set pushpin by id penalty */
		void setPinPenalty(long id, long valueNew);
		/* set pushpin by id penalty */
		void setPinsCount(int cnt);

		/* get start lap time */
		const Time& getTimeStart() const;
		/* get end lap time */
		const Time& getTimeEnd() const;

		/* get penalty lap time */
		const Time& getTimePenalty() const;

		/* get pins stats array */
		const std::vector<long>& getPins() const;
	}; /* end of 'lap' class */
} /* end of 'rfc' namespace */

#endif /* RFC_LAP_H_ */
