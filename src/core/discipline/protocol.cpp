/*
 * Rafting competition dispatcher program.
 *
 * Discipline result protocol widget.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "protocol.h"

/* default constructor */
rfc::disc::Protocol::Protocol()
{
} /* end of 'Protocol' constructor */

/* copying constructor */
rfc::disc::Protocol::Protocol(const Protocol &src) :
	score(src.score)
{
} /* end of 'Protocol' constructor */
