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

/* sum all results from protocols
 * returns self-reference.
 */
rfc::disc::Protocol & rfc::disc::Protocol::operator+=(const Protocol &prot1)
{
	for (const auto &val : prot1.score)
		score[val.first] += val.second; /* val.first is team identificator */

	return *this;
} /* end of 'operator+=' function */

/* add info to map */
rfc::disc::CompScore::CompScore() :
	scores(ENUM_CAST(disc::TypeDisc::COUNT))
{
} /* end of 'addProtocol' function */

/* add info to map */
void rfc::disc::CompScore::addProtocol(const TypeDisc type, const Protocol &prot)
{
	scores[ENUM_CAST(type)] = prot;

	resultProt += prot;
} /* end of 'addProtocol' function */

/* return protocol.
 * if protocol doesn't exists - throws exception.
 */
const rfc::disc::Protocol rfc::disc::CompScore::getProtocol(const TypeDisc type)
{
	return scores[ENUM_CAST(type)];
} /* end of 'getProtocol' function */

/* return full competition result */
const rfc::disc::Protocol rfc::disc::CompScore::getResultProtocol()
{
	return resultProt;
} /* end of 'getResultProtocol' function */
