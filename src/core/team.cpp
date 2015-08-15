/*
 * Rafting competition dispatcher program.
 *
 * Team people info class implementation.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "team.h"

/* default constructor */
rfc::Man::Man() {

} /* end of 'Man' constructor */

/* constructor by names */
rfc::Man::Man(const std::string &lastName,
			  const std::string &firstName ) :
	lastName(lastName), firstName(firstName)
{
} /* end of 'Man' constructor */

/* defualt constructor */
rfc::Team::Team(const ulong teamId) :
	id(teamId)
{
} /* end of 'Team' constructor */
