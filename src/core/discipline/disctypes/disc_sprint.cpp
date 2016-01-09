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
	else if (teamCnt >= 4)
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

	for (uint32_t i = 0; i < teamHalf; ++i) {
		Duel duel;
		/* zero player has priority */
		duel.teams[0] = dispatcher->getLap(Type(currentStage, arrScores[teamHalf + i + isOddCount].teamId));
		duel.teams[1] = dispatcher->getLap(Type(currentStage, arrScores[i + isOddCount].teamId));

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

	/* give scores */

	for (int32_t i = size - 1; i >= 0; --i)
		protocolInversed.score[i] = 200 - (size - i) * 10;

	// DisciplineAbstract::setScores(200, 10)
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

/* get stage maximal teams count */
uint32_t rfc::disc::Sprint::stageTeamsMax(const TypeSprint stage)
{
	switch (stage) {
		case TypeSprint::FINAL_B:
		case TypeSprint::FINAL_A:
			return 2;
		case TypeSprint::SPRINT_1_2:
			return 4;
		case TypeSprint::SPRINT_1_4:
			return 8;
		case TypeSprint::SPRINT_1_8:
			return 16;
		case TypeSprint::SPRINT_1_16:
			return 32;
		default:
			Exception(lang::errorLogical);
	}

	return 0;
} /* end of 'stageTeamsMax */

/* get current stage results */
rfc::disc::RideGroup rfc::disc::Sprint::stageResult(const TypeSprint stage)
{
	DuelGroup duels = rides[stage];
	uint32_t duelsCnt = duels.size();

	RideGroup winners, loosers;

	/* separating duel information for winners and loosers */
	for (uint32_t i = 0; i < duelsCnt; ++i) {
		RideTeam *winner, *looser;
		if (duels[i].teams[0]->getTimeResult() > duels[i].teams[1]->getTimeResult()) {
			winner = duels[i].teams[1];
			looser = duels[i].teams[0];
		} else {
			winner = duels[i].teams[0];
			looser = duels[i].teams[1];
		}

		winners.push_back(winner);
		loosers.push_back(looser);
	}

	/* sorting results */
	std::sort(winners.begin(), winners.end(), sortRideTeams);
	std::sort(loosers.begin(), loosers.end(), sortRideTeams);

	/* include to vector 'shifter' team */
	if (teamShifter != men::NoTeam) {
		winners.insert(winners.begin(), dispatcher->getLap(Type(stage, teamShifter)));
		teamShifter = men::NoTeam;
	}

	RideGroup result = winners;
	result.insert(result.end(), loosers.begin(), loosers.end());
	return result;	/* it is cat-vector */
} /* end of 'stageResult' function */

/* drop all results from choosed
 * index to inversed protocol
 */
void rfc::disc::Sprint::dropToProtocolInversed(const RideGroup &prot, uint32_t startPosition)
{
	uint32_t loosersCnt = prot.size();
	for (uint32_t i = startPosition; i < loosersCnt; ++i)
		protocolInversed.score.push_back(prot[i]->getTeamId());
} /* end of 'dropToProtocol' function */

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

	RideGroup stageProt = stageResult(prevStage);

	/* partial situations : finals handling */
	if (ENUM_CAST(currentStage) >= ENUM_CAST(TypeSprint::FINAL_B))
	{
		/* only one duel in these stages */
		DuelGroup &currentDuel = rides[currentStage];

		Duel duel;
		switch (currentStage) {
			case TypeSprint::FINAL_B:
				duel.teams[0] = stageProt[2];
				duel.teams[1] = stageProt[3];
				break;
			case TypeSprint::FINAL_A:
				duel.teams[0] = stageProt[0];
				duel.teams[1] = stageProt[1];
				break;
			default:
				throw Exception(lang::impossible);
		}
		currentDuel.push_back(duel);
	} else { /* not finals */
		DuelGroup &currentDuels = rides[currentStage];

		/* count of maximal team count is always dividible
		 * by 2.
		 */
		uint32_t duelsCnt = stageTeamsMax(currentStage) / 2;

		for (int32_t i = duelsCnt - 1; i >= 0; --i) {
			Duel duel;

			/* array was sorted by result growing,
			 * so first starts who is bette.
			 */
			duel.teams[0] = dispatcher->getLap(Type(currentStage, stageProt[i]->getTeamId()));
			duel.teams[1] = dispatcher->getLap(Type(currentStage, stageProt[duelsCnt + i]->getTeamId()));

			currentDuels.push_back(duel);
		}

		dropToProtocolInversed(stageProt, duelsCnt * 2);
	}

	return true;
} /* end of 'switchNextStage' function */

/* sorting by time result */
bool rfc::disc::Sprint::sortRideTeams(const RideTeam *rd0, const RideTeam *rd1)
{
	return rd0->getTimeResult() < rd1->getTimeResult();
} /* end of 'sortRideTeams' functions */
