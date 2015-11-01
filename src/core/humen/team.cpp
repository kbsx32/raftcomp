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
	id(teamId),
	instructorId(nullptr)
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

/* save human to 'kbsx32.raftcomp.dbc' type file. */
const rfc::men::Team & rfc::men::Team::save(FILE *fileOut, const uint32_t version) const
{
	/* version 0 / 1 implement */
	std::fwrite(&id, sizeof(id), 1, fileOut);

	if (version > 0) {
		String::putToFile(teamName, fileOut);
		String::putToFile(address, fileOut);
	}

	const uint32_t humanCnt = men.size();
	std::fwrite(&humanCnt, sizeof(humanCnt), 1, fileOut);

	for (const auto &human : men) {
		if (version == 0)
			human->save(fileOut, version);
		else { /* if version > 0 */
			/* save vector of stupid men */
			uint32_t id = human->getIndexInDatabase();
			fwrite(&id, sizeof(id), 1, fileOut);
		}
	}

	return *this;
} /* end of 'Team::save' function */

/* load human from 'kbsx32.raftcomp.dbc' type file. */
rfc::men::Team & rfc::men::Team::load(rfc::Dispatcher &dispatcher, FILE *fileIn, const uint32_t version)
{
	/* version 0..+INF implement */

	/* loading team id */
	std::fread(&id, sizeof(id), 1, fileIn);

	if (version > 0) {
		teamName = String::getFromFile(fileIn);
		address = String::getFromFile(fileIn);
	}

	/* loading stupid humen */
	uint32_t humanCnt;
	std::fread(&humanCnt, sizeof(humanCnt), 1, fileIn);

	/* save vector of stupid men */
	for (uint32_t ind = 0; ind < humanCnt; ++ind) {
		if (version == 0)
			men.push_back(dispatcher.manAdd()->load(fileIn, version));
		else { /* version > 0 */
			uint32_t id;
			fread(&id, sizeof(id), 1, fileIn);
			men.push_back(dispatcher.men[id]);
		}
	}

	return *this;
} /* end of 'Team::load' function */
