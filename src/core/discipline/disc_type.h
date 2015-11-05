/*
 * Rafting competition dispatcher program.
 *
 * Disciplines declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_DISCTYPE_H
#define RFC_DISCTYPE_H

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
			LONG_RACE,

			END,			/* fixators to enum */
			COUNT = END
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
			/* default functions */
			Type();

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
		class Rides
		{
			std::map<Type, RideTeam *> rides;

			/* all pushpins default count */
			std::vector<uint32_t> pinsCount;

			/* order of rides */
			std::vector<TypeDisc> ridesOrder;

			TypeDisc _disciplineCurrent;     /* current working discipline */
		public:
			/* const-reference */
			const TypeDisc &disciplineCurrent = _disciplineCurrent;

			/* class default constructor */
			Rides();

			/* class destructor */
			~Rides();

			/* get lap function */
			RideTeam * getLap(const Type type);

			/* add to global tables new lap */
			void setLap(const Type type, const RideTeam &lapNew);

			/* set pins count for all teams.
			 * arguments:
			 *   type : discipline to set pushpins;
			 */
			void setPinsCount(const TypeDisc type, const uint32_t count);

			/* set order of all rides.
			 * note :
			 *   order can not be changed after 'mandat comission' set.
			 */
			void setRidesOrder(const std::vector<TypeDisc> &order);

			/* get previous discipline before current given.
			 * returns last TypeDisc or TypeDisc::QUALIFY if current discipline is first.
			 * note :
			 *   TypeDisc 'current' can be SPRINT, SLALOM or LONG_RACE.
			 *   Other values will throw exception.
			 */
			TypeDisc getPrevDiscipline(const TypeDisc current) const;

			/* set new active discipline.
			 * returns result of switching.
			 */
			bool setActiveDiscipline(const TypeDisc type);

		protected:
			/* save rides info.
			 * minimal version : 1;
			 * maximal version : +INF;
			 */
			void save(FILE *fout, const uint32_t version);

			/* load rides info.
			 * minimal version : 1.
			 * maximal version : +INF.
			 */
			void load(FILE *fin, const uint32_t version);
		}; /* end of 'Rides' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCTYPE_H */
