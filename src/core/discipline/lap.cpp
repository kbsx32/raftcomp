/*
 * Rafting competition dispatcher program.
 *
 * Single template discipline lap implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "ride_team.h"

/* default constructor */
rfc::RideTeam::RideTeam(const disc::Type type) :
	type(type)
{
} /* end of 'RideTeam' constructor */

/* set start time */
void rfc::RideTeam::setTimeStart(const Time &timeStartNew) {
	timeStart = timeStartNew;
} /* end of 'RideTeam::setTimeStart' function */

/* set start time */
void rfc::RideTeam::setTimeEnd(const Time &timeEndNew) {
	timeEnd = timeEndNew;
} /* end of 'RideTeam::setTimeEnd' function */

/* set new winner state flag */
void rfc::RideTeam::setWinnerFlag(const bool newState) {
	isWinner = newState;
} /* end of 'RideTeam::setWinnerFlag' function */

/* set pushpin by id penalty */
void rfc::RideTeam::setPinPenalty(long id, long valueNew) {
	timePenalty -= Time().setInSeconds(pinsPenalty[id]);
	timePenalty += Time().setInSeconds(valueNew);
	pinsPenalty[id] = valueNew;
} /* end of 'RideTeam::setPinPenalty' function */

/* set pushpin by id penalty */
void rfc::RideTeam::setPinsCount(int cnt) {
	pinsPenalty.resize(cnt);
} /* end of 'RideTeam::setPinsCount' function */

/* get start lap time */
const rfc::Time& rfc::RideTeam::getTimeStart() const {
	return timeStart;
} /* end of 'RideTeam::getTimeStart' function */

/* get end lap time */
const rfc::Time& rfc::RideTeam::getTimeEnd() const {
	return timeEnd;
} /* end of 'RideTeam::getTimeEnd' function */

/* get penalty lap time */
const rfc::Time& rfc::RideTeam::getTimePenalty() const {
	return timePenalty;
} /* end of 'rfc::RideTeam::getTimePenalty' function */

/* get pins stats array */
const std::vector<long>& rfc::RideTeam::getPins() const {
	return pinsPenalty;
} /* end of 'rfc::RideTeam::getPins' function */

/* get result lap time with penalty statistics */
rfc::Time rfc::RideTeam::getTimeResult() const {
	return (timeEnd - timeStart) + timePenalty;
} /* end of 'RideTeam::getTimeResult' function */

/* get pushpins count */
ulong rfc::RideTeam::getPinsCount() const {
	return pinsPenalty.size();
} /* end of 'RideTeam::getPinsCount' function */
