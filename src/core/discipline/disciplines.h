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
	/* disciplines namespace */
	namespace disc {

		/* redifinition of disciplines */
		typedef Lap Qualify;
		typedef Lap LongRace;

		/* parallel sprint discipline declaration */
		class Sprint {
		public:
			/* define laps type */
			enum class LapType {
				LAP_UNKNOWN,
				LAP_1_32,
				LAP_1_16,
				LAP_1_8,
				LAP_1_4,
				LAP_1_2,
				FINAL_A,
				FINAL_B
			}; /* end of 'LapType' enum class */

		private:
			std::map<LapType, Lap> laps;			/* sprint laps */

		public:
			/* add new lap function */
			void addNewLap(const LapType Type, const Lap &lap);

			/* get lap info */
			Lap& getLapInfo(const LapType Type);
		}; /* end of 'DiscSprint' class */

		/* slalom discipline class declaration */
		class Slalom {
		private:
			static constexpr long triesCnt = 2; /* count of slalom tries */
			Lap laps[triesCnt];					/* two slalom tries lap */
		}; /* end of 'Slalom' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCIPLINES_H */
