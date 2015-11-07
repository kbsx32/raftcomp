/*
 * Rafting competition dispatcher program.
 *
 * All disciplines polymorfable structs.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_DISCIPLINES_H
#define RFC_DISCIPLINES_H

#include "../def.h"

#include "disc_type.h"
#include "protocol.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* forward declaration */
	class Dispatcher;

	/* disciplines namespace */
	namespace disc
	{
		/* forward declaration */
		class RideTeam;

		/* Abstract discipline class */
		class DisciplineAbstract
		{
		protected:
			TypeDisc type;
			Dispatcher *dispatcher;

			/* constructor with type.*/
			DisciplineAbstract(Dispatcher *dispatcher, const TypeDisc typeDisc);

		public:
			/* comparator for teams results */
			static bool sortTeamsResultComparator(const RideTeam *team0, const RideTeam *team1);

			/* set scores function.
			 * arguments:
			 *   rides : source rides. (must be sorted !).
			 *   startScore : score to first team.
			 *   scoreShift : delta in scores.
			 * returns:
			 *   result protocol
			 */
			static Protocol setScores(const std::vector<RideTeam *> &rides,
									  const uint32_t startScore,
									  const uint32_t scoreShift);
		protected:
			/* get result table protocol.
			 * note :
			 *   gives sorted protocol for current competition only !
			 */
			virtual const Protocol getResultProtocol();

			/* sort teams function */
			virtual void sortStartTeams();

			/* virtual destructor */
			virtual ~DisciplineAbstract();
		}; /* end of 'Discipline' class */

		/* Qualification controller class */
		class Qualify : public DisciplineAbstract
		{
		protected:
			/* rides for current discipline */
			std::vector<RideTeam *> rides;

		public:
			/* default constructor */
			Qualify(Dispatcher *dispatcher);

			/* ger result table protocol.
			 * note :
			 *   gives sorted protocol for current competition only !
			 */
			const Protocol getResultProtocol();

			/* sort teams function */
			void sortStartTeams();

			/* destructor */
			~Qualify();
		}; /* end of 'Qualify' class */

		/* Qualification controller class */
		class LongRace : public DisciplineAbstract
		{
		protected:
			/* rides for current discipline */
			std::vector<RideTeam *> rides;

		public:
			/* default constructor */
			LongRace(Dispatcher *dispatcher);

			/* ger result table protocol.
			 * note :
			 *   gives sorted protocol for current competition only !
			 */
			const Protocol getResultProtocol();

			/* sort teams function */
			void sortStartTeams();

			/* destructor */
			~LongRace();
		}; /* end of 'Qualify' class */

	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCIPLINES_H */
