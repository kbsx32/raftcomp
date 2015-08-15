#include "time.h"

/* defualt constructor */
rfc::Time::Time() {
} /* end of 'Time' constructor */

/* constructor by time in seconds.
 * argument:
 *   double sec - new time in seconds.
 */
rfc::Time::Time(double sec) :
	seconds(sec)
{
} /* end of 'Time' constructor */

/* set time function.
 * returns: self-reference.
 */
rfc::Time& rfc::Time::set(long hour, long min, long sec, long millisec) {
	/* set value (in seconds) */
	seconds = hour * 3600 + min * 60 + sec + millisec / 1000.;

	return *this;
} /* end of 'Time::set' function */

/* substract two times operator */
rfc::Time rfc::Time::operator-(Time &timeSub) const {
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
rfc::Time& rfc::Time::operator+=(double secondsAdd) {
	seconds += secondsAdd;
	return *this;
} /* end of 'operator+=' function */

/* substract two times operator */
rfc::Time& rfc::Time::operator-=(double secondsSub) {
	seconds -= secondsSub;
	return *this;
}
