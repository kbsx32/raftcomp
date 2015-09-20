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
	}; /* end of 'String' class */
} /* end of 'rfc' namespace */

#endif /* RFC_RSTRING_H_ */
