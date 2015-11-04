/*
 * Rafting competition dispatcher program.
 *
 * Discipline result protocol widget.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_PROTOCOL_H
#define RFC_PROTOCOL_H

#include <map>

#include "../humen/team.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* disciplines namespace */
	namespace disc
	{
		/* result protocol */
		class Protocol
		{
		public:
			/* type define */
			typedef std::pair<TeamId, uint32_t> TeamScore;

			/* all result for discipline.
			 * sets by discipline, who answered for this protocol.
			 */
			std::vector<TeamScore> score;

		public:
			/* default constructor */
			Protocol();

			/* copying constructor */
			Protocol(const Protocol &src);
		}; /* end of 'Protocol' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_PROTOCOL_H */
