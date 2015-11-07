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
			/* all result for discipline.
			 * sets by discipline, who answered for this protocol.
			 */
			typedef std::map<TeamId, uint32_t> TeamScore;
			typedef std::vector<TeamId> TeamsArray;

			TeamScore score;

		public:
			/* default constructor */
			Protocol();

			/* copying constructor */
			Protocol(const Protocol &src);

			/* sum all results from protocols.
			 * returns self-reference.
			 */
			Protocol& operator+=(const Protocol &prot1);

			/* return sorted array of
			 * all teams.
			 */
			const TeamsArray getSortedTeamsVector() const;
		}; /* end of 'Protocol' class */

		/* full competition score class */
		class CompScore
		{
		private:
			std::vector<Protocol> scores;
			Protocol resultProt;			 /* result protocol values */

		public:

			/* constructor.
			 * inits 'scores' vector.
			 */
			CompScore();

		protected:
			/* add info to map */
			void addProtocol(const TypeDisc type, const Protocol &prot);

			/* return protocol.
			 * if protocol doesn't exists - throws exception.
			 */
			const Protocol getProtocol(const TypeDisc type);

		public:
			/* return full competition result */
			const Protocol getResultProtocol();
		}; /* end of 'CompScore' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_PROTOCOL_H */
