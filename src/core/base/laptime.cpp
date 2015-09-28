#include "laptime.h"

/* defualt constructor */
rfc::Time::Time() :
	isInfinity(true),
	milliSeconds(0)
{
} /* end of 'Time' constructor */

/* constructor by time in milliseconds.
 * argument:
 *   seconds - new time in milliseconds.
 *   isInfinity - new state of time ( is infinity time ).
 */
rfc::Time::Time(long milliSeconds, bool isInfinity) :
	milliSeconds(milliSeconds),
	isInfinity(isInfinity)
{
} /* end of 'Time' constructor */

/* constructor by hour, minute, seconds and milliseconds */
rfc::Time::Time(long hour, long min, long sec, long millisec) {
	set(hour, min, sec, millisec);
} /* end of 'Time' constructor */

/* set time function.
 * returns: self-reference.
 */
rfc::Time& rfc::Time::set(long hour, long min, long sec, long millisec) {
	/* set value (in seconds) */
	milliSeconds = ((hour * 60 + min) * 60 + sec) * 1000 + millisec;

	return *this;
} /* end of 'Time::set' function */

/* sum two times operator */
rfc::Time rfc::Time::operator+(const Time &timeAdd) const {
	return Time(milliSeconds + timeAdd.milliSeconds);
} /* end of 'Time::operator-' function */

/* substract two times operator */
rfc::Time rfc::Time::operator-(const Time &timeSub) const {
	return Time(milliSeconds - timeSub.milliSeconds);
} /* end of 'Time::operator-' function */

/* get current time mulliseconds function */
long rfc::Time::getMilliSec() const {
	return milliSeconds % 1000;
} /* end of 'rfc::Time::getMilliSec' function */

/* get current time IN seconds function.
 * This function returns all time only in seconds.
 * For example - 2 minutes returns 120 seconds.
 */
long rfc::Time::getTimeInSeconds() const {
	return (milliSeconds / 1000);
} /* end of 'rfc::Time::getSeconds' function */

/* get current time seconds function */
long rfc::Time::getSeconds() const {
	return getTimeInSeconds() % 60;
} /* end of 'rfc::Time::getSeconds' function */

/* get current time IN minutes function.
 * This function returns all time only in seconds.
 * For example - 2 hours returns 120 minutes.
 */
long rfc::Time::getTimeInMinutes() const {
	return getTimeInSeconds() / 60;
} /* end of 'rfc::Time::getMinutes' function */

/* get current time minute function */
long rfc::Time::getMinutes() const {
	return getTimeInMinutes() % 60;
} /* end of 'rfc::Time::getMinutes' function */

/* get current time hour function */
long rfc::Time::getHours() const {
	return getTimeInMinutes() / 60;
} /* end of 'rfc::Time::getHours' function */

/* sum two times operator */
rfc::Time& rfc::Time::operator+=(const Time &timeAdd) {
	milliSeconds += timeAdd.milliSeconds;
	return *this;
} /* end of 'operator+=' function */

/* substract two times operator */
rfc::Time& rfc::Time::operator-=(const Time &timeSub) {
	milliSeconds -= timeSub.milliSeconds;
	return *this;
} /* end of 'operator-=' function */

/* compare times operator */
bool rfc::Time::operator>(const Time &time1) {
	return milliSeconds > time1.milliSeconds;
} /* end of 'Time::operator>' function */

/* compare times operator */
bool rfc::Time::operator<(const Time &time1) {
	return milliSeconds < time1.milliSeconds;
} /* end of 'Time::operator<' function */

/* get time in string format
 * default format is:
 *		"hh:mm::ss'ddd",
 * where:
 *		hh - hour,
 *		mm - minures,
 *		ss - seconds,
 *		ddd - miliseconds.
 */
rfc::String rfc::Time::getTimeString() const {
	if (isInfinity)
		return QString("infinity");

	return
		QString::number(getHours())	+ QString(":")
	+	QString::number(getMinutes())	+ QString(":")
	+	QString::number(getSeconds())	+ QString("'")
	+	QString::number(getMilliSec());
} /* end of 'Time::getTimeString' function */

/* set time IN seconds.
 * note:
 *   time will be set in seconds.
 *   last value will be lost.
 */
rfc::Time &rfc::Time::setInSeconds(long seconds) {
	set(0, 0, seconds, 0);

	return *this;
} /* end of 'rfc::Time::setInSeconds' function */
