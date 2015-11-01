/*
 * Rafting competition dispatcher program.
 *
 * Team support declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_TEAM_H_
#define RFC_TEAM_H_

#include <cstdio>
#include <vector>
#include <string>

#include "human.h"

/* 'raftcomp' support namespace */
namespace rfc {
	class Dispatcher;

	/* 'all about humans' namespace */
	namespace men
	{
		/* team class declaration */
		class Team {
		public:
			uint32_t id;                   /* team number */
			String teamName;			   /* name of team */
			String address;                /* team adress */

			std::vector<Man *> men;		   /* team men list */

			Man *instructorId;			   /* trainer id for team.*/

			/* defualt constructor */
			Team(const uint32_t teamId = 0);

			/* constructor to load team from
			 * file 'kbsx32.raftcomp.dbc' type.
			 * Type struct see on 'load' function.
			 */
			Team(Dispatcher &dispatcher, FILE *fileIn, const uint32_t version);

			/* get surnames string function */
			String getSurnames() const;

			/* get team identification string function */
			String getIdString() const;

			/* save human to 'kbsx32.raftcomp.dbc' type file. */
			const Team& save(FILE *fileOut, const uint32_t version) const;

			/* load from file.
			 * file format : (kbsx32.raftcomp.dbc').
			 */
			Team& load(rfc::Dispatcher &dispatcher, FILE *fileIn, const uint32_t version);
		}; /* end of 'team' class */
	} /* end of 'men' namespace */
} /* end of 'rfc' namespace' */

#endif /* RFC_TEAM_H_ */
