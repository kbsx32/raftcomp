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
			COUNT = END,
			NO_DISCIPLINE	/* type to show that there are no
							 * active disciplines
							 */
		}; /* end of 'LapType' enum class */

		/* sprint lap types */
		enum class TypeSprint {
			/* it is important an order of enums
			 * in this category.
			 * The last must be finals
			 */
			SPRINT_1_32,
			SPRINT_1_16,
			SPRINT_1_8,
			SPRINT_1_4,
			SPRINT_1_2,
			FINAL_B,
			FINAL_A,

			END,	/* fixator */
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
			Type getTeamed(TeamId team) const;

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

			TypeDisc _disciplineCurrent;				    /* current working discipline */

			bool mandatFinished = false;					/* mandat comission done flag */

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

			/* discipline state return value class.	*/
			enum class DiscState
			{
				WAS_NOT,	/* discipline wasn't been activated */
				CURRENT,	/* at this time this discipline */
				FINISHED	/* already done */
			}; /* end of 'DiscState' class */

			/* set new active discipline.
			 * returns false, if reacher
			 * end of the list or it is not
			 * time reached.
			 */
			DiscState setDiscipline(const disc::TypeDisc type);

			/* close discipline. */
			void finishDiscipline();

			/* returns discipline status.
			 * returns true if discipline is already started and
			 * finished.
			 */
			bool checkIsDisciplineFinished(const disc::TypeDisc type);

			/* returns current discipline */
			disc::TypeDisc getCurrentDiscipline();

			/* finish mandat comission */
			void setMandatComissionFinished();

			/* finish flag mandat comission get */
			bool isMandatFinished();

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

			/* reset info */
			void reset();
		}; /* end of 'Rides' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCTYPE_H */
