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
#include "discipline/ride_team.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* global class support */
	class Dispatcher : public disc::Rides {
	public:
		static const char fileSignature[]; /* = "kbsx32.rafrcomp.dbc" */

		/* declared teams */
		std::vector<Team *> teams;

		// disc::Rides races; /* all races info */
	public:
		/* add new team to list */
		void addTeam(Team *teamNew);
		/* get team pointer from list */
		Team * getTeam(uint32_t teamId);

		/* save info to file. */
		void save(const String &fileOutName);

		/* load info from file.
		 * file formats: 'kbsx32.raftcomp.dbc'
		 *   version 0:
		 *	   signature : "kbsx32.raftcomp.dbc";
		 *     version   : 4 bytes (uint32_t).
		 *     teamsCnt  : 4 bytes (uint32_t).
		 *     teams[teamsCnt] : ???.
		 */
		void load(const String &fileInName);

		/* class destructor */
		~Dispatcher();
	}; /* end of 'CompDispatcher' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_DISPATCHER_H_ */
