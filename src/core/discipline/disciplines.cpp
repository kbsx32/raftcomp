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
rfc::disc::Type::Type(const TypeDisc disc, const TeamId team) :
	typeDisc(disc),
	teamId(team)
{
} /* end of 'disc::Type' constructor */

/* constructor for sprint */
rfc::disc::Type::Type(const TypeSprint sprint, const TeamId team) :
	typeDisc(disc::TypeDisc::SPRINT),
	typeSprint(sprint),
	teamId(team)
{
} /* end of 'disc::Type' constructor */

/* constructor for slalom */
rfc::disc::Type::Type(const TypeSlalom disc, const TeamId team) :
	typeDisc(disc::TypeDisc::SLALOM),
	typeSlalom(disc),
	teamId(team)
{
} /* end of 'disc::Type' constructor */


/* get COPY of this Type with inserted team id */
rfc::disc::Type rfc::disc::Type::getTeamed(TeamId team)
{
	Type typeNew = *this;
	typeNew.teamId = team;

	return typeNew;
} /* end of 'disc::Type::getTeamed' function */

/* comparator */
bool rfc::disc::Type::operator<(const Type &second) const
{
	if (teamId != second.teamId)
		return teamId < second.teamId;

	if (typeDisc != second.typeDisc)
		return typeDisc < second.typeDisc;

	if (typeDisc == disc::TypeDisc::SPRINT)
		return typeSprint < second.typeSprint;

	if (typeDisc == disc::TypeDisc::SLALOM)
		return typeSlalom < second.typeSlalom;

	return false;
} /* end of 'operator<' function */

/* class default constructor */
rfc::disc::Rides::Rides()
{
} /* end of 'disc::Rides::Rides' constructor */

/* class destructor */
rfc::disc::Rides::~Rides()
{
	for (auto & ride : rides)
		delete ride.second;
} /* end of '~disc::RidesRides' constructor */

/* get lap function */
rfc::disc::RideTeam * rfc::disc::Rides::getLap(const Type type)
{
	auto &item = rides[type];
	if (item == nullptr)
		item = new RideTeam(type);

	return item;
} /* end of 'Rides::getLap' function */

/* set lap function */
void rfc::disc::Rides::setLap(const Type type, const RideTeam &lapNew)
{
	rides[type] = new RideTeam(lapNew);
} /* end of 'Rides::setLap' function */
