/*
 * Rafting competition dispatcher program.
 *
 * Discipline result protocol.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_PROTOCOL_H
#define RFC_PROTOCOL_H

#include <map>

#include "../humen/team.h"
#include "disc_type.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* disciplines namespace */
	namespace disc
	{
		/* result protocol */
		class Protocol
		{
		public:
			/* struct to save all in vector */
			class TeamScore
			{
			public:
				TeamId teamId;
				uint32_t score;

			public:
				/* constructor */
				explicit TeamScore(const TeamId teamId, const uint32_t score);

				/* explicitted constructor */
				explicit TeamScore(const TeamId id);

				/* comparator */
				bool operator<(const TeamScore &scoreSecond) const;
			}; /* end of 'TeamScore' class */

			typedef std::vector<TeamScore> TeamsArray;

			/* all result for discipline.
			 * sets by discipline, who answered for this protocol.
			 */
			TeamsArray score;

		public:
			/* default constructor */
			Protocol();

			/* constructor by rides array */
			Protocol(const std::vector<RideTeam *> &vec);

			/* copying constructor */
			Protocol(const Protocol &src);

			/* sum all results from protocols.
			 * returns self-reference.
			 */
			Protocol& operator+=(const Protocol &prot1);

			/* return sorted array of
			 * all teams.
			 */
			void sort();
		}; /* end of 'Protocol' class */

		/* full competition score class */
		class CompScore
		{
		private:
			std::vector<Protocol> scores;
			Protocol resultProt;			 /* result protocol values */

		public:
			typedef std::vector<Protocol> ProtGroup;

			/* constructor.
			 * inits 'scores' vector.
			 */
			CompScore();

		public:
			/* return protocol.
			 * if protocol doesn't exists - throws exception.
			 */
			Protocol getProtocol(const TypeDisc type);

			/* return all protocols */
			const ProtGroup & getProtocols();

			/* add info to map */
			void addProtocol(const TypeDisc type, const Protocol &prot);

			/* return full competition result */
			Protocol &getResultProtocol();

			/* get score of team in protocol */
			uint32_t findTeamResult(const disc::Type &type);
		}; /* end of 'CompScore' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_PROTOCOL_H */
