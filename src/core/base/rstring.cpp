/*
 * Rafting competition dispatcher program.
 *
 * Project string type implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <cstdio>
#include "rstring.h"

/* default constructor */
rfc::String::String() {
} /* end of 'String' class constructor */

/* QString wrap constructor */
rfc::String::String(const QString &str) :
	QString(str)
{
} /* end of 'String' class constructor */

/* String wrap constructor */
rfc::String::String(const std::string &str) :
	QString(str.c_str())
{
} /* end of 'String' class constructor */

/* C-style string wrap constructor */
rfc::String::String(const char * const &str) :
	QString(str)
{
} /* end of 'String' class constructor */

/* get const char * array function */
const char * rfc::String::data() const {
	return toLatin1().data();
} /* end of 'String::data' function */

/* QString get function */
const QString &rfc::String::getQString() const {
	return *this;
} /* end of 'getQString' function */

/* conversation number to String.
 * Adds the leading zeros in empty slots of string.
 * for example:
 *   to_string(123, 5) --> "00123";
 */
rfc::String rfc::String::toString(long number, long signsCnt)
{
	char str[16];
	std::sprintf(str, "%0*ld", (int)signsCnt, number);

	return String(str);
} /* end of 'String::toString' function */
