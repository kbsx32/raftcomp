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

/* 'raftcomp' support namespace */
namespace rfc {

	/* global class support */
	class CompDispatcher {
	public:
		/* declared teams */
		std::vector<Team *> teams;

		/* stages of competitions enum */
		enum class Stage {
			QUALIFY,
			SPRINT,
			SLALOM,
			LONGRACE,
			FULL_COMPETITION
		}; /* end of 'Stage' enum class */

		Stage stage;  /* current competition mode stage */
	private:
		/* sorted teams (order by rafting rules) to competition stages */
		std::vector<Team *> teamsCurrentStage;

		disc::Sprint::LapType
			sprintLapStart = disc::Sprint::LapType::LAP_1_8; 		/* start lap for parallel sprint */

	public:
		/* add new team to list */
		void addTeam(Team *teamNew);
		/* get team pointer from list */
		Team* getTeam(ulong teamId);

		/* prepare teams info to qualify stage */
		void prepareQualify();

		/* set current stage to competition */
		void setStage(const Stage newStage);

	private:
		/* prepare teams info to parallel sprint and
		 * release all not active teams.
		 * arguments:
		 *   lapOldType : previous lap, which is used to set start order to new.
		 *   teamsCnt : count of teams in current lap;
		 *   startTeamId : shift from array start for teams (needs in final 'b');
		 */
		void prepareSprintLap(const disc::Sprint::LapType lapOldType, const ulong teamsCnt, const ulong startTeamId = 0);

	public:
		/* prepare count of sprints function */
		void setSprintStartLap(const disc::Sprint::LapType lapType);

		/* prepare count of sprints function */
		void setSprintStartLap(const ulong teamsCnt);

		/* prepare teams info to parallel sprint */
		void prepareSprintLap(const disc::Sprint::LapType lapType);

		/* class destructor */
		~CompDispatcher();
	}; /* end of 'CompDispatcher' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_DISPATCHER_H_ */
