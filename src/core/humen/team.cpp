/*
 * Rafting competition dispatcher program.
 *
 * Team people info class implementation.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <cstdio>
#include <cstring>

#include "team.h"
#include "../dispatcher.h"

/*
 * Team functions.
 */

/* defualt constructor */
rfc::men::Team::Team(const uint32_t teamId) :
	id(teamId)
{
} /* end of 'Team' constructor */

/* constructor to load team from
 * file 'kbsx32.raftcomp.db' type
 */
rfc::men::Team::Team(Dispatcher &dispatcher, FILE *fileIn, const uint32_t version)
{
	load(dispatcher, fileIn, version);
} /* end of 'Team' constructor */

/* get surnames string function */
rfc::String rfc::men::Team::getSurnames() const
{
	String str;

	for (auto &human : men)
		str += human->lastName + ", ";

	return str;
} /* end of 'rfc::Team::getSurnames' function */

/* get surnames string function */
rfc::String rfc::men::Team::getIdString() const
{
	return String::number(id);
} /* end of 'rfc::Team::getSurnames' function */

/* save human to 'kbsx32.raftcomp.db' type file. */
const rfc::men::Team & rfc::men::Team::save(FILE *fileOut, const uint32_t version) const
{
	/* version 0 implement */
	std::fwrite(&id, sizeof(id), 1, fileOut);

	const uint32_t humanCnt = men.size();
	std::fwrite(&humanCnt, sizeof(humanCnt), 1, fileOut);

	/* save vector of stupid men */
	for (const auto &human : men)
		human->save(fileOut);

	return *this;
} /* end of 'Team::save' function */

/* load human from 'kbsx32.raftcomp.db' type file.
 * file formats:
 *   version 0:
 *     teamId   : 4 bytes (uint32_t).
 *     humanCnt : 4 bytes (uint32_t).
 *     humans[humanCnt] : ???
 */
rfc::men::Team & rfc::men::Team::load(rfc::Dispatcher &dispatcher, FILE *fileIn, const uint32_t version)
{
	/* version 0 implement */

	/* loading team id */
	std::fread(&id, sizeof(id), 1, fileIn);

	/* loading stupid humen */
	uint32_t humanCnt;
	std::fread(&humanCnt, sizeof(humanCnt), 1, fileIn);

	for (uint32_t i = 0; i < humanCnt; ++i)
		men.push_back(dispatcher.manAdd()->load(fileIn, version));

	return *this;
} /* end of 'Team::load' function */
