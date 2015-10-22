/*
 * Rafting competition dispatcher program.
 *
 * Project string class wrap type declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_RSTRING_H_
#define RFC_RSTRING_H_

#include <QString>

/* 'raftcomp' support namespace */
namespace rfc {
	/* String wrap class.
	 * Needs because it is not good to convert String every time to
	 * QString with copying.
	 */
	class String : public QString {
	public:
		/* default constructor */
		String();

		/* QString wrap constructor */
		String(const QString &str);

		/* c++ standart string wrap constructor */
		String(const std::string &str);

		/* C-style string wrap constructor */
		String(const char * const &str);

		/* get const char * array function */
		const char * data() const;

		/* QString get function */
		const QString &getQString() const;

		/* conversation number to String.
		 * Adds the leading zeros in empty slots of string.
		 * for example:
		 *   to_string(123, 5) --> "00123";
		 */
		static String toString(long number, long signsCnt = 2);

		/* 'fgets' function.
		 * The problem is fgets doesn't works correctly with
		 * binary opened files. ( WHY ??? ).
		 */
		static void fgets(char *data, const uint32_t maxLen, FILE *&fileOut);

		/* 'fputs' function.
		 * The problem is fputs doesn't inserts '\0' symbol at
		 * the line end.
		 * This functions calls fputs and fputc('\0') in the end.
		 */
		static void fputs(const char *data, FILE *fileOut);

	}; /* end of 'String' class */
} /* end of 'rfc' namespace */

#endif /* RFC_RSTRING_H_ */
