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

#include "discipline/disciplines.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* single man class declaration */
	class Man {
	public:
		String
			lastName,       		/* man family name  */
			firstName;				/*   and first name */

	public:
		/* default constructor */
		Man();

		/* load human from file 'kbsx32.raftcomp.db' */
		Man(FILE *fileIn, const uint32_t version = 0);

		/* constructor by names */
		Man(const String &lastName,
			const String &firstName);

		/* save human to 'kbsx32.raftcomp.db' type file. */
		const Man& save(FILE *fileOut, const uint32_t version = 0) const;

		/* load human from 'kbsx32.raftcomp.db' type file.
		 *   version 0:
		 *     lastName  : char * : string.
		 *     firstName : char * : string;
		 */
		Man& load(FILE *fileIn, const uint32_t version = 0);

	}; /* end of 'Man' class */

	/* team class declaration */
	class Team {
	public:
		uint32_t id;                   /* team number */
		std::vector<Man> men;  		/* team men list */

		/* defualt constructor */
		Team(const uint32_t teamId = 0);

		/* constructor to load team from
		 * file 'kbsx32.raftcomp.db' type.
		 * Type struct see on 'load' function.
		 */
		Team(FILE *fileIn, const uint32_t version = 0);

		/* get surnames string function */
		String getSurnames() const;

		/* get team identification string function */
		String getIdString() const;

		/* save human to 'kbsx32.raftcomp.db' type file. */
		const Team& save(FILE *fileOut, const uint32_t version = 0) const;

		/* load from file.
		 * file formats : (kbsx32.raftcomp.db').
		 *   version 0:
		 *     teamId   : 4 bytes (uint32_t).
		 *     humanCnt : 4 bytes (uint32_t).
		 *     humans[humanCnt] : ???
		 *
		 * returns: self-reference.
		 */
		Team& load(FILE *fileIn, const uint32_t version = 0);
	}; /* end of 'team' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_TEAM_H_ */
