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
rfc::disc::LongRace::LongRace(Dispatcher *dispatcher) :
	DisciplineAbstract(dispatcher, TypeDisc::LONG_RACE)
{
} /* end of 'Discipline' destructor */

/* default destructor */
rfc::disc::LongRace::~LongRace()
{
} /* end of 'DisciplineAbstract' destructor */

/* sort teams function */
void rfc::disc::LongRace::init()
{
	DisciplineAbstract::sortStartTeamsDefault(rides, dispatcher);
} /* end of 'sortTeams' function */

/* get result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::LongRace::getProtocol()
{
	std::sort(rides.begin(), rides.end(), DisciplineAbstract::sortTeamsResultComparator);

	return DisciplineAbstract::setScores(rides, 400, 20);
} /* end of 'getResultProtocol' function */
