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

/* default constructor */
rfc::Man::Man() {

} /* end of 'Man' constructor */

/* constructor by names */
rfc::Man::Man(const String &lastName,
			  const String &firstName ) :
	lastName(lastName), firstName(firstName)
{
} /* end of 'Man' constructor */

/* load human from file 'kbsx32.raftcomp.db' type */
rfc::Man::Man(FILE *fileIn, const uint32_t version)
{
	load(fileIn, version);
} /* end of 'Man' constructor */

/* save human to 'kbsx32.raftcomp.db' type file */
const rfc::Man& rfc::Man::save(FILE *fileOut, const uint32_t version) const
{
	const char *str;

	/* saving info */
	str = lastName.data();
	String::fputs(str, fileOut);

	str = firstName.data();
	String::fputs(str, fileOut);

	return *this;
} /* end of 'Man::save' function */

/* load human from 'kbsx32.raftcomp.db' type file.
 * file formats : (kbsx32.raftcomp.db).
 *   version 0:
 *     lastName  : char * : string.
 *     firstName : char * : string;
 */
rfc::Man& rfc::Man::load(FILE *fileIn, const uint32_t version)
{
	// if (version >= 0) {

	/* loading info */
	char str[STR_MAX];  /* prepared buffer */

	String::fgets(str, STR_MAX, fileIn);
	lastName = str;

	String::fgets(str, STR_MAX, fileIn);
	firstName = str;

	return *this;
} /* end of 'Man::load' function */

/*
 * Team functions.
 */

/* defualt constructor */
rfc::Team::Team(const uint32_t teamId) :
	id(teamId)
{
} /* end of 'Team' constructor */

/* constructor to load team from
 * file 'kbsx32.raftcomp.db' type
 */
rfc::Team::Team(FILE *fileIn, const uint32_t version)
{
	load(fileIn, version);
} /* end of 'Team' constructor */

/* get surnames string function */
rfc::String rfc::Team::getSurnames() const
{
	String str;

	for (auto &human : men)
		str += human.lastName + ", ";

	return str;
} /* end of 'rfc::Team::getSurnames' function */

/* get surnames string function */
rfc::String rfc::Team::getIdString() const
{
	return String::number(id);
} /* end of 'rfc::Team::getSurnames' function */

/* save human to 'kbsx32.raftcomp.db' type file. */
const rfc::Team & rfc::Team::save(FILE *fileOut, const uint32_t version) const
{
	/* version 0 implement */
	std::fwrite(&id, sizeof(id), 1, fileOut);

	const uint32_t humanCnt = men.size();
	std::fwrite(&humanCnt, sizeof(humanCnt), 1, fileOut);

	/* save vector of stupid men */
	for (const auto &human : men)
		human.save(fileOut);

	return *this;
} /* end of 'Team::save' function */

/* load human from 'kbsx32.raftcomp.db' type file.
 * file formats:
 *   version 0:
 *     teamId   : 4 bytes (uint32_t).
 *     humanCnt : 4 bytes (uint32_t).
 *     humans[humanCnt] : ???
 */
rfc::Team & rfc::Team::load(FILE *fileIn, const uint32_t version)
{
	/* version 0 implement */

	/* loading team id */
	std::fread(&id, sizeof(id), 1, fileIn);

	/* loading stupid humen */
	uint32_t humanCnt;
	std::fread(&humanCnt, sizeof(humanCnt), 1, fileIn);

	for (uint32_t i = 0; i < humanCnt; ++i)
		men.push_back(Man(fileIn, version));

	return *this;
} /* end of 'Team::load' function */
