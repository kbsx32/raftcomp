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

/* default destructor */
rfc::disc::DisciplineAbstract::DisciplineAbstract(Dispatcher *dispatcher, const TypeDisc typeDisc) :
	type(typeDisc),
	dispatcher(dispatcher)
{
} /* end of 'DisciplineAbstract' destructor */

/* default destructor */
rfc::disc::DisciplineAbstract::~DisciplineAbstract()
{
} /* end of 'DisciplineAbstract' destructor */

/* ger result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::DisciplineAbstract::getResultProtocol()
{
	const Protocol prot;

	return prot;
} /* end of 'getResultProtocol' function */

/* sort teams function */
void rfc::disc::DisciplineAbstract::sortStartTeams()
{
} /* end of 'sortTeams' function */

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
		prot.score[ride->getTeamId()] =  score;

		score -= scoreShift;
	}

	return prot;
} /* end of 'setScores' function */
