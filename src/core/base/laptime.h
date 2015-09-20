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
		double seconds;   /* current timer state value in seconds */

	public:
		/* infinity constant time */
		static constexpr double infinity = -1;

		/* default constructor.
		 * by defualt sets infinity time.
		 */
		Time();

		/* constructor by hour, minute, seconds and milliseconds */
		Time(long hour, long min, long sec, long millisec);

		/* constructor by time in seconds.
		 * argument:
		 *   double sec - new time in seconds.
		 */
		Time(double sec);

		/* set time function.
		 * returns: self-reference.
		 */
		Time& set(long hour, long min, long sec, long millisec);

		/* sum two times operator */
		Time operator+(const Time &timeAdd) const;

		/* substract two times operator */
		Time operator-(const Time &timeSub) const;

		/* sum two times operator */
		Time& operator+=(const Time &timeAdd);
		/* substract two times operator */
		Time& operator-=(const Time &timeSub);

		/* compare times operator */
		bool operator>(const Time &time1);
		/* compare times operator */
		bool operator<(const Time &time1);

		/*
		 * get values functions
		 */

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
	}; /* end of 'time' class */
} /* end of 'rfc' namespace */

#endif /* RFC_TIME_H */
