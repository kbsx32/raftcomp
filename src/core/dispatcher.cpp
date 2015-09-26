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
rfc::Dispatcher::~Dispatcher() {
	/* remove all team pointers */
	for (auto item : teams)
		delete item;
} /* end of '~Dispatcher' destructor */

/* add new team to list */
void rfc::Dispatcher::addTeam(Team *teamNew) {
	teams.push_back(teamNew);
} /* end of 'Dispatcher::addTeam' function */

/* get team pointer list */
rfc::Team* rfc::Dispatcher::getTeam(const ulong teamId) {
	auto item = std::find_if(teams.begin(), teams.end(),
							 [&](Team *team) {
								return team->id == teamId;
							 });

	return *item;
} /* end of 'Dispatcher::addTeam' function */
