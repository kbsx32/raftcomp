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

#include <vector>
#include <string>

#include "lap.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* single man class declaration */
	class Man {
	private:
		std::string
			lastName,       		/* man family name  */
			firstName;				/*   and first name */

	public:
		/* default constructor */
		Man();

		/* constructor by names */
		Man(const std::string &lastName,
			const std::string &firstName );
	}; /* end of 'man' class */

	/* team class declaration */
	class Team {
	public:
		std::vector<Man> men;  		/* team men list */

		Lap
			lapQualif,
			// lapSprint,
			lapSlalom,
			lapLongRace;

	}; /* end of 'team' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_TEAM_H_ */
