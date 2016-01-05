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
void rfc::disc::Qualify::init()
{
	/* get result from mandat comission */
	for (const men::Team *team : dispatcher->teams)
		rides.push_back(dispatcher->getLap(Type(TypeDisc::QUALIFY, team->id)));
} /* end of 'sortTeams' function */

/* ger result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::Qualify::getProtocol()
{
	std::sort(rides.begin(), rides.end(), DisciplineAbstract::sortTeamsResultComparator);

	return DisciplineAbstract::setScores(rides, 100, 5);
} /* end of 'getResultProtocol' function */
