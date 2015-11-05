/*
 * Rafting competition dispatcher program.
 *
 * Abstract discipline declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "../disciplines.h"
#include "../ride_team.h"
#include "../../dispatcher.h"

/* default destructor */
rfc::disc::Qualify::Qualify(Dispatcher *dispatcher) :
	DisciplineAbstract(dispatcher, TypeDisc::QUALIFY)
{
} /* end of 'Discipline' destructor */

/* default destructor */
rfc::disc::Qualify::~Qualify()
{
} /* end of 'DisciplineAbstract' destructor */

/* sort teams function */
void rfc::disc::Qualify::sortStartTeams()
{
	/* get result from mandat comission */
	for (const men::Team *team : dispatcher->teams)
		rides.push_back(dispatcher->getLap(Type(TypeDisc::QUALIFY, team->id)));
} /* end of 'sortTeams' function */

/* ger result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::Qualify::getResultProtocol()
{
	Protocol prot;

	std::sort(rides.begin(), rides.end(),
			  [&](const RideTeam *ride0, const RideTeam *ride1)
			  {
					return ride0->getTimeResult() > ride1->getTimeResult();
			  });

	/* coefficients for discipline */
	uint32_t score = 100;
	const uint32_t scoreShift = 5;

	for (auto const &ride : rides) {
		prot.score[ride->getTeamId()] = score;

		score -= scoreShift;
	}

	return prot;
} /* end of 'getResultProtocol' function */
