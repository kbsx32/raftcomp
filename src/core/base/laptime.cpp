#include "laptime.h"

/* defualt constructor */
rfc::Time::Time() :
	seconds(infinity)
{
} /* end of 'Time' constructor */

/* constructor by time in seconds.
 * argument:
 *   double sec - new time in seconds.
 */
rfc::Time::Time(double sec) :
	seconds(sec)
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
	seconds = hour * 3600 + min * 60 + sec + millisec / 1000.;

	return *this;
} /* end of 'Time::set' function */

/* sum two times operator */
rfc::Time rfc::Time::operator+(const Time &timeAdd) const {
	return Time(seconds + timeAdd.seconds);
} /* end of 'Time::operator-' function */

/* substract two times operator */
rfc::Time rfc::Time::operator-(const Time &timeSub) const {
	return Time(seconds - timeSub.seconds);
} /* end of 'Time::operator-' function */

/* get current time seconds function */
long rfc::Time::getSeconds() const {
	return (long)seconds % 60;
} /* end of 'rfc::Time::getSeconds' function */

/* get current time mulliseconds function */
long rfc::Time::getMilliSec() const {
	return (seconds - long(seconds)) * 1000;
} /* end of 'rfc::Time::getMilliSec' function */

/* get current time minute function */
long rfc::Time::getMinutes() const {
	return (long)seconds / 60 % 60;
} /* end of 'rfc::Time::getMinutes' function */

/* get current time hour function */
long rfc::Time::getHours() const {
	return seconds / 3600;
} /* end of 'rfc::Time::getHours' function */

/* sum two times operator */
rfc::Time& rfc::Time::operator+=(const Time &timeAdd) {
	seconds += timeAdd.seconds;
	return *this;
} /* end of 'operator+=' function */

/* substract two times operator */
rfc::Time& rfc::Time::operator-=(const Time &timeSub) {
	seconds -= timeSub.seconds;
	return *this;
} /* end of 'operator-=' function */

/* compare times operator */
bool rfc::Time::operator>(const Time &time1) {
	return seconds > time1.seconds;
} /* end of 'Time::operator>' function */

/* compare times operator */
bool rfc::Time::operator<(const Time &time1) {
	return seconds < time1.seconds;
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
	return
		QString::number(getHours())	+ QString(":")
	+	QString::number(getMinutes())	+ QString(":")
	+	QString::number(getSeconds())	+ QString("'")
	+	QString::number(getMilliSec());
} /* end of 'Time::getTimeString' function */
