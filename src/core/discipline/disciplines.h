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
	/* disciplines namespace */
	namespace disc {
		/* forward declaration of lap class */
		class RideTeam;

		/* all disciplines types */
		enum class TypeDisc {
			QUALIFY,
			SPRINT,
			SLALOM,
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

		/* sprint lap types */
		enum class TypeSlalom {
			SLALOM_1,
			SLALOM_2
		}; /* end of 'TypeSlalom' enum class */

		/* class collector for types */
		class Type {
		public:
			TypeDisc typeDisc;

			TypeSprint typeSprint;  /* needs if typeDisc == SPRINT; */
			TypeSlalom typeSlalom;  /* needs if typeDisc == SLALOM; */

			TeamId teamId;
		public:
			/* constructor for usual discipline */
			Type(const TypeDisc disc, const TeamId team = 0);

			/* constructor for sprint */
			Type(const TypeSprint sprint, const TeamId team = 0);

			/* constructor for slalom */
			Type(const TypeSlalom disc, const TeamId team = 0);

			/* get COPY of this Type with inserted team id */
			Type getTeamed(TeamId team);

			/* comparator */
			bool operator<(const Type &second) const;
		}; /* end of 'Type' class */

		/* full competition race info class */
		class Rides {
			std::map<Type, RideTeam *> rides;
		public:
			/* class default constructor */
			Rides();

			/* class destructor */
			~Rides();

			/* get lap function */
			RideTeam * getLap(const Type type);

			/* add to global tables new lap */
			void setLap(const Type type, const RideTeam &lapNew);
		}; /* end of 'Races' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCIPLINES_H */
