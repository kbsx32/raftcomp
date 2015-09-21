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

#include "../def.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* forward declaration of lap class */
	class Lap;

	/* disciplines namespace */
	namespace disc {

		/* all disciplines types */
		enum class TypeDisc {
			QUALIFY,
			SPRINT,
			SLALOM_0,
			SLALOM_1,
			LONG_RACE
		}; /* end of 'LapType' enum class */

		/* sprint lap types */
		enum class TypeSprint {
			SPRINT_1_32,
			SPRINT_1_16,
			SPRINT_1_8,
			SPRINT_1_4,
			SPRINT_1_2,
			FINAL_B,
			FINAL_A
		}; /* end of 'TypeSprint' enum class */

		/* class collector for types */
		class Type {
		public:
			TypeDisc typeDisc;
			TypeSprint typeSprint;

		public:
			/* constructor for usual discipline */
			Type(const TypeDisc disc);

			/* constructor for sprint */
			Type(const TypeSprint sprint);
		}; /* end of 'Type' class */

		/* full competition race info class */
		class Races {
			/* define one 'ride' class */
			typedef std::map<ulong, Lap *> Ride;	/* (ulong) - team id,
													 * (Lap *) - team lap info
													 */

			/* all disciplines info */
			Ride qualify;
			std::vector<Ride> sprint;
			Ride slalom0, slalom1;
			Ride longRace;

			/* get lap function */
			Lap * getLap(const ulong teamId, const Type type);
		}; /* end of 'Races' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCIPLINES_H */
