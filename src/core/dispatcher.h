/*
 * Rafting competition dispatcher program.
 *
 * 'raftcomp' teams dispatcher header.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_DISPATCHER_H_
#define RFC_DISPATCHER_H_

#include "team.h"
#include "discipline/lap.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* global class support */
	class CompDispatcher {
	public:
		/* declared teams */
		std::vector<Team *> teams;

		disc::Races races; /* all races info */
	public:
		/* add new team to list */
		void addTeam(Team *teamNew);
		/* get team pointer from list */
		Team * getTeam(ulong teamId);

		/* class destructor */
		~CompDispatcher();
	}; /* end of 'CompDispatcher' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_DISPATCHER_H_ */
