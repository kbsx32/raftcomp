/*
 * Rafting competition dispatcher program.
 *
 * Slalom discipline implement.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "../disciplines.h"
#include "../ride_team.h"
#include "../../dispatcher.h"

/* default destructor */
rfc::disc::Slalom::Slalom(Dispatcher *dispatcher) :
	DisciplineAbstract(dispatcher, TypeDisc::QUALIFY),
	rides(2)  /* init array by two tries */
{
} /* end of 'Discipline' destructor */

/* default destructor */
rfc::disc::Slalom::~Slalom()
{
} /* end of 'DisciplineAbstract' destructor */

/* sort teams function */
void rfc::disc::Slalom::init()
{
	sortStartTeamsDefault(rides[0], dispatcher, Type(TypeSlalom::SLALOM_1));
	sortStartTeamsDefault(rides[1], dispatcher, Type(TypeSlalom::SLALOM_2));
} /* end of 'sortTeams' function */

/* ger result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::Slalom::getProtocol()
{
	uint32_t cntTeams = rides[0].size();
	RideGroup rideResult;

	/* caount minimal time */
	for (uint32_t i = 0; i < cntTeams; ++i)
		if (rides[0][i]->getTimeResult() < rides[1][i]->getTimeResult())
			rideResult.push_back(rides[0][i]);
		else
			rideResult.push_back(rides[1][i]);

	/* sorting result */
	std::sort(rideResult.begin(), rideResult.end(), DisciplineAbstract::sortTeamsResultComparator);

	return DisciplineAbstract::setScores(rideResult, 300, 15);
} /* end of 'getResultProtocol' function */
