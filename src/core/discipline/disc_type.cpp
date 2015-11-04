/*
 * Rafting competition dispatcher program.
 *
 * Disciplines classes functions implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "disc_type.h"
#include "ride_team.h"

/* no parametres type */
rfc::disc::Type::Type() :
	typeDisc(TypeDisc::QUALIFY),
	teamId(0)
{
} /* end of 'disc::Type' constructor */

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
rfc::disc::Rides::Rides() :
	pinsCount(ENUM_CAST(TypeDisc::COUNT))
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
		item = new RideTeam(type, pinsCount[ENUM_CAST(type.typeDisc)]);

	return item;
} /* end of 'Rides::getLap' function */

/* set lap function */
void rfc::disc::Rides::setLap(const Type type, const RideTeam &lapNew)
{
	rides[type] = new RideTeam(lapNew);
} /* end of 'Rides::setLap' function */

/* set pins count for all teams.
 * arguments:
 *   type : discipline to set pushpins;
 */
void rfc::disc::Rides::setPinsCount(const TypeDisc type, const uint32_t count)
{
	pinsCount[ENUM_CAST(type)] = count;

	// for (auto &ride : rides)
	for (std::map<Type, RideTeam *>::iterator ride = rides.begin();
		 ride != rides.end(); ++ride) {

		if (ride->first.typeDisc == type)
			ride->second->setPinsCount(pinsCount[ENUM_CAST(type)]);
	}
} /* end of 'setPinsCount' function */

/* save rides info.
 * available from version 1.
 * current saving version : 1;
 */
void rfc::disc::Rides::save(FILE *fout, const uint32_t version)
{
	if (version < 1)
		return ;

	fwrite(&pinsCount[0], sizeof(uint32_t), ENUM_CAST(TypeDisc::COUNT), fout);

	uint32_t ridesCnt = rides.size();
	fwrite(&ridesCnt, sizeof(uint32_t), 1, fout);
	for (auto &ride : rides) {

		const Type *type = &ride.first;
		RideTeam *rideTeam = ride.second;

		fwrite(type, sizeof(disc::Type), 1, fout);
		fwrite(rideTeam, sizeof(disc::Type), 1, fout);
	}
} /* end of 'save' function */

/* load rides info.
 * available from version 1.
 */
void rfc::disc::Rides::load(FILE *fin, const uint32_t version)
{
	if (version < 1)
		return ;

	/* read all pushpins count */
	fread(&pinsCount[0], sizeof(uint32_t), ENUM_CAST(TypeDisc::COUNT), fin);

	uint32_t ridesCnt;
	fread(&ridesCnt, sizeof(uint32_t), 1, fin);

	Type typeNew;
	RideTeam rideTeamNew;

	/* read all laps */
	for (uint32_t i = 0; i < ridesCnt; ++i) {

		fwrite(&typeNew, sizeof(disc::Type), 1, fin);
		fwrite(&rideTeamNew, sizeof(disc::Type), 1, fin);

		rideTeamNew.setPinsCount(pinsCount[ENUM_CAST(typeNew.typeDisc)]);

		rides[typeNew] = new RideTeam(rideTeamNew);
	}
} /* end of 'load' function */
