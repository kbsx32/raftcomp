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

#include "disc_type.h"
#include "disciplines.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* disciplines namespace */
	namespace disc
	{
		/* Single template discipline lap class */
		class RideTeam {
			TeamId teamId;

			disc::Type type;					/* discipline lap type */

			Time
				timeStart,						/* start lap time */
				timeEnd,						/* end lap time */
				timePenalty;                    /* penalty time */

			std::vector<uint32_t> pinsPenalty;		/* pins penalties */

			uint32_t penaltyOther = 0;          /* other penalties value.
												 * for example : foulstart, etc.
												 */
		public:
			/* void-constructor */
			RideTeam(uint32_t teamId = 0);

			/* copying constructor */
			RideTeam(const RideTeam &rideTeam);

			/* constructor */
			RideTeam(const disc::Type type, const uint32_t pinsCount = 0);

			/* set start lap time */
			void setTimeStart(const Time &timeStartNew);
			/* set end lap time */
			void setTimeEnd(const Time &timeEndNew);

			/* set pushpin by id penalty */
			void setPinPenalty(long id, long valueNew);

			/* set pushpin by id penalty */
			void setPenaltyOther(uint32_t valueNew);

			/* set pushpin by id penalty */
			uint32_t getPenaltyOther();

			/* set pushpins count */
			void setPinsCount(int cnt);


			/* get pushpins count */
			uint32_t getPinsCount() const;

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

			/* get team identificator */
			TeamId getTeamId();

			/* get pins stats array */
			const std::vector<uint32_t>& getPins() const;
		}; /* end of 'RideTeam' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_RIDE_TEAM_H_ */
