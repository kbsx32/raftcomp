/*
 * Rafting competition dispatcher program.
 *
 * Project exception types declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_EXCEPTION_H_
#define RFC_EXCEPTION_H_

#include <exception>
#include "rstring.h"

/* 'raftcomp' support namespace */
namespace rfc {
	class Exception : public std::exception {
	private:
		String text;  /* exception text */
	public:
		/* class constructor */
		Exception(const String &text);

		/* get exception text info */
		const String getText() const;
	}; /* end of 'Exception' class */
} /* end of 'rfc' namespace */

#endif /* RFC_EXCEPTION_H_ */
