/*
 * Rafting competition dispatcher program.
 *
 * All disciplines polymorfable structs.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_DISCIPLINES_H
#define RFC_DISCIPLINES_H

#include "../def.h"

#include "disc_type.h"
#include "protocol.h"

/* 'raftcomp' support namespace */
namespace rfc
{
	/* disciplines namespace */
	namespace disc
	{

		/* Abstract discipline class */
		class DisciplineAbstract
		{
		protected:
			TypeDisc type;

			/* constructor with type.*/
			DisciplineAbstract(const TypeDisc typeDisc);

			/* get result table protocol.
			 * note :
			 *   gives sorted protocol for current competition only !
			 */
			virtual const Protocol getResultProtocol();

			/* sort teams function */
			virtual void sortStartTeams();

			/* virtual destructor */
			virtual ~DisciplineAbstract();
		}; /* end of 'Discipline' class */

		/* forward declaration */
		class RideTeam;

		/* Qualification controller class */
		class Qualify : public DisciplineAbstract
		{
			/* rides for current discipline */
			std::vector<RideTeam *> rides;

		public:
			/* default constructor */
			Qualify();

			/* ger result table protocol.
			 * note :
			 *   gives sorted protocol for current competition only !
			 */
			const Protocol getResultProtocol();

			/* sort teams function */
			void sortStartTeams();

			/* destructor */
			~Qualify();
		}; /* end of 'Qualify' class */
	} /* end of 'disc' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_DISCIPLINES_H */
