/*
 * Rafting competition dispatcher program.
 *
 * Single template discipline lap implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "ride_team.h"

/* void-constructor */
rfc::disc::RideTeam::RideTeam(uint32_t teamId) :
	type(TypeDisc::QUALIFY),
	teamId(teamId)
{
} /* end of 'RideTeam' constructor */

/* default constructor */
rfc::disc::RideTeam::RideTeam(const disc::Type type, const uint32_t pinsCount) :
	type(type),
	pinsPenalty(pinsCount),
	teamId(0)
{
} /* end of 'RideTeam' constructor */

/* copying constructor */
rfc::disc::RideTeam::RideTeam(const RideTeam &rideTeam) :
	timeStart(rideTeam.timeStart),
	timePenalty(rideTeam.timePenalty),
	timeEnd(rideTeam.timeEnd),
	pinsPenalty(rideTeam.pinsPenalty),
	penaltyOther(rideTeam.penaltyOther),
	type(rideTeam.type),
	teamId(rideTeam.teamId)
{
} /* end of 'RideTeam' constructor */

/* constructor */
void rfc::disc::RideTeam::load(FILE *fIn, const uint32_t version)
{
	if (version < 2)
		return ;

	fread(&teamId, sizeof(teamId), 1, fIn);
	fread(&type, sizeof(type), 1, fIn);
	fread(&timeStart, sizeof(timeStart), 1, fIn);
	fread(&timeEnd, sizeof(timeEnd), 1, fIn);
	fread(&timePenalty, sizeof(timePenalty), 1, fIn);

	uint32_t cntPushPins;
	fread(&cntPushPins, sizeof(cntPushPins), 1, fIn);
	pinsPenalty.resize(cntPushPins);

	fread(&pinsPenalty[0], sizeof(pinsPenalty[0]) * cntPushPins, 1, fIn);
	fread(&penaltyOther, sizeof(penaltyOther), 1, fIn);
} /* end of 'constructor' function */

/* save to file info */
void rfc::disc::RideTeam::save(FILE *fOut, const uint32_t version)
{
	if (version < 2)
		return ;

	fwrite(&teamId, sizeof(teamId), 1, fOut);
	fwrite(&type, sizeof(type), 1, fOut);
	fwrite(&timeStart, sizeof(timeStart), 1, fOut);
	fwrite(&timeEnd, sizeof(timeEnd), 1, fOut);
	fwrite(&timePenalty, sizeof(timePenalty), 1, fOut);

	uint32_t cntPushPins = pinsPenalty.size();
	fwrite(&cntPushPins, sizeof(cntPushPins), 1, fOut);
	fwrite(&pinsPenalty[0], sizeof(pinsPenalty[0]) * cntPushPins, 1, fOut);
	fwrite(&penaltyOther, sizeof(penaltyOther), 1, fOut);
} /* end of 'save' function */

/* set team id */
void rfc::disc::RideTeam::setTeamId(const TeamId teamId)
{
	this->teamId = teamId;
} /* end of 'setTeamId' function */

/* set start time */
void rfc::disc::RideTeam::setTimeStart(const Time &timeStartNew)
{
	timeStart = timeStartNew;
} /* end of 'RideTeam::setTimeStart' function */

/* set start time */
void rfc::disc::RideTeam::setTimeEnd(const Time &timeEndNew)
{
	timeEnd = timeEndNew;
} /* end of 'RideTeam::setTimeEnd' function */

/* set pushpin by id penalty */
void rfc::disc::RideTeam::setPinPenalty(long id, long valueNew)
{
	timePenalty -= Time().setInSeconds(pinsPenalty[id]);
	timePenalty += Time().setInSeconds(valueNew);
	pinsPenalty[id] = valueNew;
} /* end of 'RideTeam::setPinPenalty' function */

/* set pushpin by id penalty */
void rfc::disc::RideTeam::setPinsCount(int cnt)
{
	pinsPenalty.resize(cnt);
} /* end of 'RideTeam::setPinsCount' function */

/* get start lap time */
const rfc::Time rfc::disc::RideTeam::getTimeStart() const
{
	return timeStart;
} /* end of 'RideTeam::getTimeStart' function */

/* get end lap time */
const rfc::Time rfc::disc::RideTeam::getTimeEnd() const
{
	return timeEnd;
} /* end of 'RideTeam::getTimeEnd' function */

/* get 'end-start' lap time */
const rfc::Time rfc::disc::RideTeam::getTimeDistance() const
{
	return timeEnd - timeStart;
} /* end of 'RideTeam::getTimeDistance' function */

/* get penalty lap time */
const rfc::Time rfc::disc::RideTeam::getTimePenalty() const
{
	return timePenalty + Time().setInSeconds(penaltyOther);
} /* end of 'rfc::RideTeam::getTimePenalty' function */

/* get pins stats array */
const std::vector<uint32_t>& rfc::disc::RideTeam::getPins() const
{
	return pinsPenalty;
} /* end of 'rfc::RideTeam::getPins' function */

/* get result lap time with penalty statistics */
rfc::Time rfc::disc::RideTeam::getTimeResult() const
{
	return (timeEnd - timeStart) + getTimePenalty();
} /* end of 'RideTeam::getTimeResult' function */

/* get pushpins count */
uint32_t rfc::disc::RideTeam::getPinsCount() const {
	return pinsPenalty.size();
} /* end of 'RideTeam::getPinsCount' function */

/* set pushpin by id penalty */
void rfc::disc::RideTeam::setPenaltyOther(uint32_t valueNew)
{
	penaltyOther = valueNew;
} /* end of 'RideTeam::setPenaltyOther' function */

/* set pushpin by id penalty */
uint32_t rfc::disc::RideTeam::getPenaltyOther()
{
	return penaltyOther;
} /* end of 'RideTeam::getPenaltyOther' function */

/* get team identificator */
rfc::TeamId rfc::disc::RideTeam::getTeamId()
{
	return teamId;
} /* end of 'getTeamId' function */
