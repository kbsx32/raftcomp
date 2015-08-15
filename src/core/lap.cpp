/*
 * Rafting competition dispatcher program.
 *
 * Single template discipline lap implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "lap.h"

/* default constructor */
rfc::Lap::Lap() {
} /* end of 'Lap' constructor */

/* set start time */
void rfc::Lap::setTimeStart(const Time &timeStartNew) {
	timeStart = timeStartNew;
} /* end of 'Lap::setTimeStart' function */

/* set start time */
void rfc::Lap::setTimeEnd(const Time &timeEndNew) {
	timeEnd = timeEndNew;
} /* end of 'Lap::setTimeEnd' function */

/* set pushpin by id penalty */
void rfc::Lap::setPinPenalty(long id, long valueNew) {
	timePenalty -= pinsPenalty[id];
	timePenalty += valueNew;
	pinsPenalty[id] = valueNew;
} /* end of 'Lap::setPinPenalty' function */

/* set pushpin by id penalty */
void rfc::Lap::setPinsCount(int cnt) {
	pinsPenalty.resize(cnt);
} /* end of 'Lap::setPinsCount' function */

/* get start lap time */
const rfc::Time& rfc::Lap::getTimeStart() const {
	return timeStart;
} /* end of 'Lap::getTimeStart' function */

/* get end lap time */
const rfc::Time& rfc::Lap::getTimeEnd() const {
	return timeEnd;
} /* end of 'Lap::getTimeEnd' function */

/* get penalty lap time */
const rfc::Time& rfc::Lap::getTimePenalty() const {
	return timePenalty;
} /* end of 'rfc::Lap::getTimePenalty' function */

/* get pins stats array */
const std::vector<long>& rfc::Lap::getPins() const {
	return pinsPenalty;
} /* end of 'rfc::Lap::getPins' function */
