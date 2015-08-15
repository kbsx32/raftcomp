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

/* 'raftcomp' support namespace */
namespace rfc {

	/* time class */
	class Time {
	private:
		double seconds;   /* current timer state value in seconds */

		/* constructor by time in seconds.
		 * argument:
		 *   double sec - new time in seconds.
		 */
		Time(double sec);

	public:
		/* defualt constructor */
		Time();

		/* set time function.
		 * returns: self-reference.
		 */
		Time& set(long hour, long min, long sec, long millisec);

		/* substract two times operator */
		Time operator-(Time &timeSub) const;

		/* sum two times operator */
		Time& operator+=(double seconds);
		/* substract two times operator */
		Time& operator-=(double seconds);

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
	}; /* end of 'time' class */
} /* end of 'rfc' namespace */

#endif /* RFC_TIME_H */
