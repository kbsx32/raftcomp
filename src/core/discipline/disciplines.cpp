/*
 * Rafting competition dispatcher program.
 *
 * Disciplines classes functions implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "disciplines.h"
#include "ride_team.h"

/* default constructor */
rfc::disc::Type::Type(const TypeDisc disc) :
	typeDisc(disc)
{
} /* end of 'disc::Type' constructor */

/* constructor for sprint */
rfc::disc::Type::Type(const TypeSprint sprint) :
	typeDisc(disc::TypeDisc::SPRINT),
	typeSprint(sprint)
{
} /* end of 'disc::Type' constructor */

/* class default constructor */
rfc::disc::Rides::Rides() {
	;
} /* end of 'disc::RidesRides' constructor */

/* removes from memory ride.
 * need be called for any ride before
 * class destroys.
 */
void rfc::disc::Rides::clearRide(Ride &ride)
{
	for (auto & item : ride)
		delete item.second;
} /* end of 'disc::Rides::clearRide' function */

/* class destructor */
rfc::disc::Rides::~Rides() {
	clearRide(qualify);
	clearRide(slalom0);
	clearRide(slalom1);

	for (auto & sprintLap : sprint)
		clearRide(sprintLap);

	clearRide(longRace);
} /* end of '~disc::RidesRides' constructor */

/* create or get lap function.
 * automatically creates new RideTeam lap if
 * current wasn't create before.
 * arguments:
 *     container : 'Ride' map container.
 *     teamId : team identificator.
 *     type : 'Ride' type. Needs to init new RideTeam.
 * returns:
 *     pointer to RideTeam.
 */
rfc::RideTeam * rfc::disc::Rides::lapCreateOrGet(Ride &container, const ulong teamId, const Type type) {
	RideTeam *ret = container[teamId];

	/* creating new Ride if such not exists */
	if (ret == nullptr) {

		ret = new RideTeam(type);
		container[teamId] = ret;
	}

	return ret;
} /* end of 'lapCreateOrGet' function */

/* get lap function */
rfc::RideTeam * rfc::disc::Rides::getLap(const ulong teamId, const Type type) {
	switch (type.typeDisc) {
		case TypeDisc::QUALIFY:
			return lapCreateOrGet(qualify, teamId, type.typeDisc);
		case TypeDisc::LONG_RACE:
			return lapCreateOrGet(longRace, teamId, type.typeDisc);
		case TypeDisc::SLALOM_0:
			return lapCreateOrGet(slalom0, teamId, type.typeDisc);
		case TypeDisc::SLALOM_1:
			return lapCreateOrGet(slalom1, teamId, type.typeDisc);
		case TypeDisc::SPRINT:
			return lapCreateOrGet(sprint[ENUM_CAST(type.typeSprint)], teamId, type.typeDisc);
	}

	return nullptr;
} /* end of 'Rides::getLap' function */

/* set lap function */
void rfc::disc::Rides::setLap(const ulong teamId, const Type type, const RideTeam &lapNew) {
	RideTeam *ret = getLap(teamId, type);
	*ret = lapNew;
} /* end of 'Rides::setLap' function */
