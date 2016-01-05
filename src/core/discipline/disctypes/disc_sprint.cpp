/*
 * Rafting competition dispatcher program.
 *
 * Sprint discipline declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "../disciplines.h"
#include "../ride_team.h"
#include "../../dispatcher.h"

/* default destructor */
rfc::disc::Sprint::Sprint(Dispatcher *dispatcher) :
	DisciplineAbstract(dispatcher, TypeDisc::SPRINT)
{
} /* end of 'Discipline' destructor */

/* default destructor */
rfc::disc::Sprint::~Sprint()
{
} /* end of 'DisciplineAbstract' destructor */

/* sort teams function */
void rfc::disc::Sprint::init()
{
	/* set start stage */
	uint32_t teamCnt = dispatcher->teams.size();

	if (teamCnt > 16)
		currentStage = TypeSprint::SPRINT_1_16;
	else if (teamCnt > 8)
		currentStage = TypeSprint::SPRINT_1_8;
	else if (teamCnt > 4)
		currentStage = TypeSprint::SPRINT_1_4;
	else if (teamCnt > 2)
		currentStage = TypeSprint::SPRINT_1_2;
	else
		/* wtf ??? */
		throw Exception(lang::errorLogical);

	/* init first rides */

	/* sorting teams by sprint rules */
	const Protocol::TeamsArray arrScores = dispatcher->getResultProtocol().score;

	DuelGroup &currentDuels = rides[currentStage];

	/* if count of teams is odd -
	 * it shift all start positions for 1.
	 */
	bool isOddCount = teamCnt % 2;

	/* init shifter */
	if (isOddCount)
		teamShifter = arrScores[0].teamId;

	uint32_t teamHalf = teamCnt / 2;

	for (int32_t i = teamHalf - 1; i >= 0; --i) {
		Duel duel;
		duel.teams[0] = dispatcher->getLap(Type(currentStage, arrScores[i + isOddCount].teamId));
		duel.teams[1] = dispatcher->getLap(Type(currentStage, arrScores[teamHalf + i + isOddCount].teamId));

		currentDuels.push_back(duel);
	}
} /* end of 'sortTeams' function */

/* get result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::Sprint::getProtocol()
{
	/* making uninversing */
	uint32_t size = protocolInversed.score.size();
	for (uint32_t i = 0; i < size; ++i)
		std::swap(protocolInversed.score[i], protocolInversed.score[size - i - 1]);

	return protocolInversed;
} /* end of 'getResultProtocol' function */

/* comparing duel results and
 * commiting it to protocol
 */
void rfc::disc::Sprint::addToProtocolTwoTeams(RideTeam *team0, RideTeam *team1)
{
	/* we must commit results of FINAL_B before */
	TeamId teamWinner, teamLooser;

	Duel finalB = rides[TypeSprint::FINAL_B][0];
	if (finalB.teams[0]->getTimeResult() < finalB.teams[1]->getTimeResult()) {
		teamWinner = team0->getTeamId();
		teamLooser = team1->getTeamId();
	} else {
		teamWinner = team1->getTeamId();
		teamLooser = team0->getTeamId();
	}

	protocolInversed.score.push_back(teamLooser);
	protocolInversed.score.push_back(teamWinner);
} /* end of 'addToProtocolTwoTeams' function */

/* switching to next stage sprint.
 * returns false if there no more
 * chanses to next stages
 * ( all stages passed ).
 */
bool rfc::disc::Sprint::switchNextStage()
{
	TypeSprint prevStage = currentStage;

	/* change current stage */
	currentStage = static_cast<TypeSprint>(ENUM_CAST(currentStage) + 1);

	/* FINAL_B is between SPRINT_1_2 and FINAL A */
	if (currentStage == TypeSprint::FINAL_A) {
		prevStage = TypeSprint::SPRINT_1_2;

		/* we must commit results of FINAL_B before */
		Duel finalB = rides[TypeSprint::FINAL_B][0];
		addToProtocolTwoTeams(finalB.teams[0], finalB.teams[1]);
	}

	/* check if any more stages exist */
	if (currentStage == TypeSprint::END) {
		/* we must commit results of FINAL_A */
		Duel finalA = rides[TypeSprint::FINAL_A][0];
		addToProtocolTwoTeams(finalA.teams[0], finalA.teams[1]);

		return false;
	}

	/* pre-save constants */
	std::vector<Duel> duelsWas = rides[prevStage];
	uint32_t duelsWasCnt = duelsWas.size();

	std::vector<RideTeam *> winners, loosers;

	/* separating duel information for winners and loosers */
	for (uint32_t i = 0; i < duelsWasCnt; ++i) {
		RideTeam *winner, *looser;
		if (duelsWas[i].teams[0]->getTimeResult() > duelsWas[i].teams[1]->getTimeResult()) {
			winner = duelsWas[i].teams[1];
			looser = duelsWas[i].teams[0];
		} else {
			winner = duelsWas[i].teams[0];
			looser = duelsWas[i].teams[1];
		}

		winners.push_back(winner);
		loosers.push_back(looser);
	}

	/* sorting results */
	std::sort(winners.begin(), winners.end(), sortRideTeams);
	std::sort(loosers.begin(), loosers.end(), sortRideTeams);

	/* include to vector 'shifter' team */
	if (teamShifter != men::NoTeam) {
		winners.push_back(dispatcher->getLap(Type(prevStage, teamShifter)));
		teamShifter = men::NoTeam;
		++duelsWasCnt;
	}

	/* if count of winners isn't odd, we must add
	 * one team from loosers
	 */
	if (duelsWasCnt % 2) {
		winners.insert(winners.begin(), loosers[0]);
		loosers.erase(loosers.begin());
		++duelsWasCnt;
	}

	/* loosers including to protocol */
	uint32_t loosersCnt = loosers.size();
	for (uint32_t i = 0; i < loosersCnt; ++i)
		protocolInversed.score.push_back(loosers[i]->getTeamId());

	/* partial situations : finals handling */
	if (ENUM_CAST(currentStage) >= ENUM_CAST(TypeSprint::FINAL_B))
	{
		/* only one duel in these stages */
		DuelGroup &currentDuel = rides[currentStage];

		Duel duel;
		switch (currentStage) {
			case TypeSprint::FINAL_B:
				duel.teams[0] = loosers[0];
				duel.teams[1] = loosers[1];
				break;
			case TypeSprint::FINAL_A:
				duel.teams[0] = winners[0];
				duel.teams[1] = winners[1];
				break;
			default:
				throw Exception("wtf ???");
		}
		currentDuel.push_back(duel);

	} else { /* not finals */
		/* half is always dividable by 2 :
		 * we handled it before by
		 * adding participiants from
		 * previous stages.
		 */
		uint32_t half = duelsWasCnt / 2;
		DuelGroup &currentDuels = rides[currentStage];

		for (uint32_t i = 0; i < half; ++i) {
			Duel duel;

			/* array was sorted by result growing,
			 * so first starts who is bette.
			 */
			duel.teams[0] = winners[i * 2 + 1];
			duel.teams[1] = winners[i * 2];

			currentDuels.push_back(duel);
		}
	}

	return true;
} /* end of 'switchNextStage' function */

/* sorting by time result */
bool rfc::disc::Sprint::sortRideTeams(const RideTeam *rd0, const RideTeam *rd1)
{
	return rd0->getTimeResult() < rd1->getTimeResult();
} /* end of 'sortRideTeams' functions */
