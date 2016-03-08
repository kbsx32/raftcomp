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
                /* default constructor */
                explicit TeamScore();

				/* constructor */
				explicit TeamScore(const TeamId teamId, const uint32_t score);

				/* explicitted constructor */
				explicit TeamScore(const TeamId id);

				/* comparator */
				bool operator<(const TeamScore &scoreSecond) const;

                /* file-constructor.
                 * available from v4.
                 */
                explicit TeamScore(FILE *fileIn, const uint32_t version);

                /* save team score.
                 * available from v4.
                 */
                void save(FILE *fileOut, const uint32_t version);
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

            /* fs-synchro */
            Protocol(FILE *fileIn, const uint32_t version);
            void save(FILE *fileOut, const uint32_t version);

            /* reset protocol info */
            void reset();

            /* check is protocol is empty */
            bool isClear();
		}; /* end of 'Protocol' class */

		/* full competition score class */
		class CompScore
		{
		private:
            typedef std::vector<Protocol> ProtGroup;

            ProtGroup
                scores,
                typeSnapshots;

			Protocol resultProt;			 /* result protocol values */
		public:
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

            /* return full competition result for choosed moment */
            Protocol &getResultProtocol(const TypeDisc type);

			/* get score of team in protocol */
			uint32_t findTeamResult(const disc::Type &type);

            /* save all protocols to file */
            void save(FILE *fileOut, const uint32_t version);
            /* load all protocols from file */
            void load(FILE *fileIn, const uint32_t version);

            /* reset protocol info */
            void reset();
		}; /* end of 'CompScore' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_PROTOCOL_H */
