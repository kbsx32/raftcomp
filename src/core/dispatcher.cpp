/*
 * Rafting competition dispatcher program.
 *
 * 'raftcomp' teams dispatcher implementation.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <algorithm>

#include "dispatcher.h"

/* class destructor */
rfc::CompDispatcher::~CompDispatcher() {
	/* remove all team pointers */
	for (auto item : teams)
		delete item;
} /* end of '~CompDispatcher' destructor */

/* add new team to list */
void rfc::CompDispatcher::addTeam(Team *teamNew) {
	teams.push_back(teamNew);
} /* end of 'CompDispatcher::addTeam' function */

/* get team pointer list */
rfc::Team* rfc::CompDispatcher::getTeam(const ulong teamId) {
	auto item = std::find_if(teams.begin(), teams.end(),
							 [&](Team *team) {
								return team->id == teamId;
							 });

	return *item;
} /* end of 'CompDispatcher::addTeam' function */

/* set current stage to competition */
void rfc::CompDispatcher::setStage(const Stage newStage) {
	stage = newStage;
} /* end of 'CompDispatcher::setStage' function */

/* prepare teams info to first parallel sprint. */
void rfc::CompDispatcher::setSprintStartLap(const ulong teamsCnt) {
	;
} /* end of 'rfc::CompDispatcher::prepareSprintLapFirst' function */

/* prepare count of sprints function */
void rfc::CompDispatcher::setSprintStartLap(const disc::Sprint::LapType lapType) {
	assert(stage == Stage::SPRINT);

	sprintLapStart = lapType;
} /* end of 'CompDispatcher::setSprintStartLap' function */

/* prepare teams info to parallel sprint and
 * release all not active teams.
 * arguments:
 *   lapOldType : previous lap, which is used to set start order to new.
 *   teamsCnt : count of teams in current lap;
 *   startTeamId : shift from array start for teams (needs in final 'b');
 */
void rfc::CompDispatcher::prepareSprintLap(const disc::Sprint::LapType lapOldType, const ulong teamsCnt, const ulong startTeamId) {
	if (lapOldType != disc::Sprint::LapType::LAP_UNKNOWN)
		std::sort(teamsCurrentStage.begin(), teamsCurrentStage.end(),
					[&lapOldType](Team *team0, Team *team1) {
						return team0->discSprint.getLapInfo(lapOldType).getTimeResult() < team1->discSprint.getLapInfo(lapOldType).getTimeResult();
					});

	teamsCurrentStage.resize(teamsCnt);

	// teamsCurrentStage.erase(teamsCurrentStage.begin());
	teamsCurrentStage.erase(teamsCurrentStage.begin(), teamsCurrentStage.begin() += startTeamId - 1);
} /* end of 'CompDispatcher::prepareSprintLap' function */

/* prepare teams info to parallel sprint */
void rfc::CompDispatcher::prepareSprintLap(const disc::Sprint::LapType lapType) {
	assert(stage == Stage::SPRINT);

	typedef disc::Sprint::LapType LapType;

	/* reset current stage array */
	teamsCurrentStage = teams;

	if (lapType == sprintLapStart || lapType == LapType::LAP_1_32) {

		std::sort(teamsCurrentStage.begin(), teamsCurrentStage.end(),
					[](Team *team0, Team *team1)
					{
						return team0->discQualif.getTimeResult() > team1->discQualif.getTimeResult();
					});
	}
	else
		switch (lapType) {
			case LapType::LAP_1_16:
				prepareSprintLap(LapType::LAP_1_32, 32);
				break;
			case LapType::LAP_1_8:
				prepareSprintLap(LapType::LAP_1_16, 16);
				break;
			case LapType::LAP_1_4:
				prepareSprintLap(LapType::LAP_1_8, 8);
				break;
			case LapType::LAP_1_2:
				prepareSprintLap(LapType::LAP_1_4, 4);
				break;
			case LapType::FINAL_B:
				prepareSprintLap(LapType::LAP_1_2, 2);
				break;
			case LapType::FINAL_A:
				break;
			default:
				break;
			}
} /* end of 'CompDispatcher::prepareSprintLap' function */
