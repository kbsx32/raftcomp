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

#include "humen/team.h"
#include "discipline/ride_team.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* global class support */
	class Dispatcher : public disc::Rides,
					   public men::MenDatabase
	{
	private:
		/* signature for saving database-competition files */
		static const char fileSignature[]; /* = "kbsx32.rafrcomp.dbc" */
	public:
		/* declared teams */
		std::vector<men::Team *> teams;

		/* add new team to list */
		void addTeam(men::Team *teamNew);
		/* get team pointer from list */
		men::Team * getTeam(uint32_t teamId);

		/* save info to file.
		 * current saving version : 1.
		 * see doc/format-dbc/v*.txt files
		 * to full info about saving format.
		 */
		void save(const String &fileOutName);

		/* load info from file. */
		void load(const String &fileInName);

		/* reset all dispatcher info */
		void reset();

		/* class destructor */
		~Dispatcher();
	}; /* end of 'CompDispatcher' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_DISPATCHER_H_ */
