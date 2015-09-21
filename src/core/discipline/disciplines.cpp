/*
 * Rafting competition dispatcher program.
 *
 * Disciplines classes functions implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "disciplines.h"
#include "lap.h"

/* default constructor */
rfc::disc::Type::Type(const TypeDisc disc) :
	typeDisc(disc)
{
} /* end of 'disc::Type' constructor */

/* constructor for sprint */
rfc::disc::Type::Type(const TypeSprint sprint) :
	typeDisc(disc::TypeDisc::SPRINT),
	typeSprint(sprint)
{
} /* end of 'disc::Type' constructor */

/* get lap function */
rfc::Lap *rfc::disc::Races::getLap(const ulong teamId, const Type type) {
	switch (type.typeDisc) {
		case TypeDisc::QUALIFY:
			return qualify[teamId];
		case TypeDisc::LONG_RACE:
			return longRace[teamId];
		case TypeDisc::SLALOM_0:
			return slalom0[teamId];
		case TypeDisc::SLALOM_1:
			return slalom1[teamId];
		case TypeDisc::SPRINT:
			return sprint[ENUM_CAST(type.typeSprint)][teamId];
	}

	return nullptr;
} /* end of 'Races::getLap' function */
