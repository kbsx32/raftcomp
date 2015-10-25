/*
 * Rafting competition dispatcher program.
 *
 * Single template discipline lap implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "ride_team.h"

/* default constructor */
rfc::disc::RideTeam::RideTeam(const disc::Type type) :
	type(type)
{
} /* end of 'RideTeam' constructor */

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
const std::vector<long>& rfc::disc::RideTeam::getPins() const
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
