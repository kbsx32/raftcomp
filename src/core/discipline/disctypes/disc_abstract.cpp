/*
 * Rafting competition dispatcher program.
 *
 * Abstract discipline declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "../disciplines.h"
#include "../protocol.h"

/* default destructor */
rfc::disc::DisciplineAbstract::DisciplineAbstract(Dispatcher *dispatcher, const TypeDisc typeDisc) :
	type(typeDisc),
	dispatcher(dispatcher)
{
} /* end of 'DisciplineAbstract' destructor */

/* default destructor */
rfc::disc::DisciplineAbstract::~DisciplineAbstract()
{
} /* end of 'DisciplineAbstract' destructor */

/* ger result table protocol.
 * note :
 *   gives sorted protocol for current competition only !
 */
const rfc::disc::Protocol rfc::disc::DisciplineAbstract::getResultProtocol()
{
	const Protocol prot;

	return prot;
} /* end of 'getResultProtocol' function */

/* sort teams function */
void rfc::disc::DisciplineAbstract::sortStartTeams()
{
} /* end of 'sortTeams' function */
