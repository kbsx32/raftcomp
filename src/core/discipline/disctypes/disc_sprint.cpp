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
void rfc::disc::Sprint::sortStartTeams()
{
	/* set start stage */
	uint32_t teamCnt = dispatcher->teams.size();

	if (teamCnt >= 16)
		currentStage = TypeSprint::SPRINT_1_16;
	else if (teamCnt >= 8)
		currentStage = TypeSprint::SPRINT_1_8;
	else if (teamCnt >= 4)
		currentStage = TypeSprint::SPRINT_1_4;
	else if (teamCnt >= 2)
		currentStage = TypeSprint::SPRINT_1_2;
	else
		/* wtf ??? */
		throw Exception(lang::errorLogical);

	/* init first ride */
	for (const men::Team *team : dispatcher->teams)
		rides[currentStage].push_back(dispatcher->getLap(Type(currentStage, team->id)));
} /* end of 'sortTeams' function */

/* ger result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::Sprint::getProtocol()
{
	/*
	std::sort(rides.begin(), rides.end(), DisciplineAbstract::sortTeamsResultComparator);

	return DisciplineAbstract::setScores(rides, 100, 5);
	*/
	return Protocol();
} /* end of 'getResultProtocol' function */

/* set order for given stage of sprint */
void rfc::disc::Sprint::setOrder(const TypeSprint sprint)
{
} /* end of 'setOrder' function */

/* switching to next stage sprint.
 * returns false if there no more
 * chanses to next stages
 * ( all stages passed ).
 */
bool rfc::disc::Sprint::switchNextStage()
{
	return true;
} /* end of 'switchNextStage' function */
