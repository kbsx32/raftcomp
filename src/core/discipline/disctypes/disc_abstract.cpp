/*
 * Rafting competition dispatcher program.
 *
 * Abstract discipline declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "../disciplines.h"
#include "../protocol.h"
#include "../ride_team.h"
#include "../../dispatcher.h"

/* default destructor */
rfc::disc::DisciplineAbstract::DisciplineAbstract(Dispatcher *dispatcher, const TypeDisc typeDisc) :
	type(typeDisc),
	dispatcher(dispatcher)
{
} /* end of 'DisciplineAbstract' destructor */

/* default destructor */
rfc::disc::DisciplineAbstract::~DisciplineAbstract()
{
	/* it is just virtual function */
} /* end of 'DisciplineAbstract' destructor */

/* sort teams function */
void rfc::disc::DisciplineAbstract::init()
{
	/* it is just virtual function */
} /* end of 'sortTeams' function */

/* sort teams function */
const rfc::disc::Protocol rfc::disc::DisciplineAbstract::getProtocol()
{
	/* it is just virtual function */

	return Protocol();
} /* end of 'get protocol' function */

/* comparator for teams results */
bool rfc::disc::DisciplineAbstract::sortTeamsResultComparator(const RideTeam *ride0, const RideTeam *ride1)
{
	return ride0->getTimeResult() > ride1->getTimeResult();
} /* end of 'sortTeamsResultComparator' function */

/* set scores function.
 * arguments:
 *   rides : source rides. (must be sorted !).
 *   startScore : score to first team.
 *   scoreShift : delta in scores.
 * returns:
 *   result protocol
 */
rfc::disc::Protocol rfc::disc::DisciplineAbstract::setScores
			(const std::vector<RideTeam *> &rides,
			 const uint32_t startScore,
			 const uint32_t scoreShift)
{
	Protocol prot;

	/* coefficients for discipline */
	uint32_t score = startScore;

	for (auto const &ride : rides) {
		prot.score.push_back(Protocol::TeamScore(ride->getTeamId(), score));

		score -= scoreShift;
	}

	return prot;
} /* end of 'setScores' function */

/* sort teams by default.
 * takes info about teams from
 * current result protocol and
 * sorts them.
 *
 * arguments:
 *   ridesDest : destination array. (as return value).
 *   dispatcher : source dispatcher.
 */
void rfc::disc::DisciplineAbstract::sortStartTeamsDefault(
			std::vector<RideTeam *> &ridesDest,
			Dispatcher *dispatcher,
			const disc::Type &type)
{
    const Protocol::TeamsArray arr = dispatcher->getResultProtocolSnapshot(type.typeDisc).score;

	for (const Protocol::TeamScore &score : arr)
		ridesDest.push_back(dispatcher->getLap(type.getTeamed(score.teamId)));
} /* end of 'sortStartTeamsDefault' function */
