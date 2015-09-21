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
