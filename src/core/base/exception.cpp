/*
 * Rafting competition dispatcher program.
 *
 * Project exception types functions implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "exception.h"

/* class constructor */
rfc::Exception::Exception(const String &text) :
	text(text)
{
} /* end of 'Exception' constructor */

/* get exception text info */
const rfc::String rfc::Exception::getText() const {
	return text;
} /* end of 'getText' function */
