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

		/* constructor by names */
		Man(const String &lastName,
			const String &firstName);
	}; /* end of 'Man' class */

	/* team class declaration */
	class Team {
	public:
		ulong id;                   /* team number */
		std::vector<Man> men;  		/* team men list */

		/* disciplines include to team info */
		disc::Qualify discQualif;
		disc::Slalom discSlalom;
		disc::Sprint discSprint;
		disc::LongRace discLongRace;

		/* defualt constructor */
		Team(const ulong teamId = 0);

		/* saving to file full progress */
		void saveToFile(const String &fileName);
	}; /* end of 'team' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_TEAM_H_ */
