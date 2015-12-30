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

		/* rides for one discipline */
		typedef std::vector<RideTeam *> RideGroup;

		/* Abstract discipline class */
		class DisciplineAbstract
		{
		protected:
			TypeDisc type;
			Dispatcher *dispatcher;

			/* constructor with type.*/
			DisciplineAbstract(Dispatcher *dispatcher, const TypeDisc typeDisc);

		public:
			/* sort teams by default.
			 * takes info about teams from
			 * current result protocol and
			 * sorts them.
			 *
			 * arguments:
			 *   ridesDest : destination array. (as return value).
			 *   dispatcher : source dispatcher.
			 */
			static void sortStartTeamsDefault(std::vector<RideTeam *> &ridesDest,
											  Dispatcher *dispatcher);

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
			/* sort teams function */
			virtual void sortStartTeams();

			/* get result protocol function */
			virtual const Protocol getProtocol();

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
			const Protocol getProtocol();

			/* sort teams function */
			void sortStartTeams();

			/* destructor */
			~Qualify();
		}; /* end of 'Qualify' class */

		/* Qualification controller class */
		class Slalom : public DisciplineAbstract
		{
		protected:
			std::vector<RideGroup> rides;

		public:
			/* default constructor */
			Slalom(Dispatcher *dispatcher);

			/* get result table protocol.
			 * note :
			 *   gives sorted protocol for current competition only !
			 */
			const Protocol getProtocol();

			/* sort teams function */
			void sortStartTeams();

			/* destructor */
			~Slalom();
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
			const Protocol getProtocol();

			/* sort teams function */
			void sortStartTeams();

			/* destructor */
			~LongRace();
		}; /* end of 'LongRace' class */

		/* Qualification controller class */
		class Sprint : public DisciplineAbstract
		{
		protected:
			/* single lap between two teams */
			struct Duel {
				/* by default first team is
				 * team who starts first
				 * in duel race.
				 */
				RideTeam *teams[2];
			}; /* end of 'Duel' class */

			/* duel vector subscript */
			typedef std::vector<Duel> DuelGroup;

			/* rides for current discipline */
			std::map<TypeSprint, DuelGroup> rides;

			TypeSprint
				currentStage;	/* sets on constructor by count of teams */

			/* team who shift and miss
			 * duels if count of teams is odd.
			 * By default : -1.
			 */
			TeamId teamShifter = men::NoTeam;

			/* result protocol (builds dynamically.
			 * ( inversed ).
			 * In inversed protocol it is better
			 * to add all result winners.
			 */
			Protocol protocolInversed;

		public:
			/* default constructor */
			Sprint(Dispatcher *dispatcher);

			/* destructor */
			~Sprint();

			/* switching to next stage sprint.
			 * returns false if there no more
			 * chanses to next stages
			 * ( all stages passed ).
			 */
			bool switchNextStage();

			/* get result table protocol.
			 * note :
			 *   gives sorted protocol for current competition only !
			 */
			const Protocol getProtocol();

			/* sort teams function */
			void sortStartTeams();

		private:
			/* sorting by time result */
			static bool sortRideTeams(const RideTeam *rd0, const RideTeam *rd1);

			/* comparing duel results and
			 * commiting it to protocol
			 */
			void addToProtocolTwoTeams(RideTeam *team0, RideTeam *team1);
		}; /* end of 'Qualify' class */

	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCIPLINES_H */
