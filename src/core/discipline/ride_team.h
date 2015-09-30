/*
 * Rafting competition dispatcher program.
 *
 * Single template discipline lap declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_RIDE_TEAM_H_
#define RFC_RIDE_TEAM_H_

#include <vector>
#include "../def.h"

#include "disciplines.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* Single template discipline lap class */
	class RideTeam {
		disc::Type type;					/* discipline lap type */

		Time
			timeStart,						/* start lap time */
			timeEnd,						/* end lap time */
			timePenalty;                    /* penalty time */

		bool isWinner;                      /* winner flag for parallel sprints */
		std::vector<long> pinsPenalty;		/* pins penalties */

		ulong penaltyOther = 0;             /* other penalties value.
											 * for example : foulstart, etc.
											 */
	public:
		/* default constructor */
		RideTeam(const disc::Type type);

		/* set start lap time */
		void setTimeStart(const Time &timeStartNew);
		/* set end lap time */
		void setTimeEnd(const Time &timeEndNew);

		/* set new winner state flag */
		void setWinnerFlag(const bool newState = true);

		/* set pushpin by id penalty */
		void setPinPenalty(long id, long valueNew);

		/* set pushpin by id penalty */
		void setPenaltyOther(ulong valueNew);

		/* set pushpin by id penalty */
		ulong getPenaltyOther();

		/* set pushpins count */
		void setPinsCount(int cnt);


		/* get pushpins count */
		ulong getPinsCount() const;

		/* get start lap time */
		const Time getTimeStart() const;
		/* get end lap time */
		const Time getTimeEnd() const;

		/* get 'end-start' lap time */
		const Time getTimeDistance() const;

		/* get penalty lap time */
		const Time getTimePenalty() const;

		/* get result lap time with penalty statistics */
		Time getTimeResult() const;

		/* get pins stats array */
		const std::vector<long>& getPins() const;
	}; /* end of 'RideTeam' class */
} /* end of 'rfc' namespace */

#endif /* RFC_RIDE_TEAM_H_ */
