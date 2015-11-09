/*
 * Rafting competition dispatcher program.
 *
 * Time class declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */


#pragma once
#ifndef RFC_TIME_H
#define RFC_TIME_H

#include "rstring.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* time class */
	class Time {
	private:
		long milliSeconds;   /* current timer state value in seconds */

	public:
		bool isInfinity = false;     /* is infinity flag time */

		/* default constructor.
		 * by defualt sets infinity time.
		 */
		Time();

		/* constructor by hour, minute, seconds and milliseconds */
		Time(long hour, long min, long sec = 0, long millisec = 0);

		/* constructor by time in milliseconds.
		 * argument:
		 *   milliseconds - new time in milliseconds.
		 *   isInfinity - new state of time ( is infinity time ).
		 */
		Time(long milliseconds, bool isInfinity = false);

		/* constructor by time in string.
		 * string format:
		 * "hh:MM:ss::mm".
		 */
		Time(const String &string);

		/* set time IN seconds.
		 * note:
		 *   time will be set in seconds.
		 *   last value will be lost.
		 */
		Time &setInSeconds(long seconds);

		/* set time function.
		 * returns: self-reference.
		 */
		Time& set(long hour, long min, long sec, long millisec);

		/* set time by string.
		 * string format:
		 * "hh:MM:ss::mm".
		 * returns: self-reference.
		 */
		Time& set(const String &string);

		/* sum two times operator */
		Time operator+(const Time &timeAdd) const;

		/* substract two times operator */
		Time operator-(const Time &timeSub) const;

		/* sum two times operator */
		Time& operator+=(const Time &timeAdd);
		/* substract two times operator */
		Time& operator-=(const Time &timeSub);

		/* compare times operator */
		bool operator>(const Time &time1) const;
		/* compare times operator */
		bool operator<(const Time &time1) const;

		/*
		 * get values functions
		 */

	private:
		/* get current time IN seconds function.
		 * This function returns all time only in seconds.
		 * For example - 2 minutes returns 120 seconds.
		 */
		long getTimeInSeconds() const;

		/* get current time IN minutes function.
		 * This function returns all time only in seconds.
		 * For example - 2 hours returns 120 minutes.
		 */
		long getTimeInMinutes() const;

	public:
		/* get current time mulliseconds function */
		long getMilliSec() const;

		/* get current time seconds function */
		long getSeconds() const;

		/* get current time minute function */
		long getMinutes() const;

		/* get current time hour function */
		long getHours() const;

		/* get time in string format
		 * default format is:
		 *		"hh:mm::ss'ddd",
		 * where:
		 *		hh - hour,
		 *		mm - minures,
		 *		ss - seconds,
		 *		ddd - miliseconds.
		 */
		String getTimeString() const;

		/* get minimal from two times */
		static Time getMin(const Time &time0, const Time &time1);
	}; /* end of 'time' class */
} /* end of 'rfc' namespace */

#endif /* RFC_TIME_H */
