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
rfc::Man::Man(FILE *fileIn, const ulong version)
{
	load(fileIn, version);
} /* end of 'Man' constructor */

/* save human to 'kbsx32.raftcomp.db' type file */
const rfc::Man& rfc::Man::save(FILE *fileOut, const ulong version) const
{
	const char *str;

	/* saving info */
	str = lastName.data();
	std::fputs(str, fileOut);

	str = firstName.data();
	std::fputs(str, fileOut);

	return *this;
} /* end of 'Man::save' function */

/* load human from 'kbsx32.raftcomp.db' type file.
 * file formats : (kbsx32.raftcomp.db).
 *   version 0:
 *     lastName  : char * : string.
 *     firstName : char * : string;
 */
rfc::Man& rfc::Man::load(FILE *fileIn, const ulong version)
{
	// if (version >= 0) {

	/* loading info */
	char str[STR_MAX];  /* prepared buffer */

	std::fgets(str, STR_MAX, fileIn);
	lastName = str;

	std::fgets(str, STR_MAX, fileIn);
	firstName = str;

	return *this;
} /* end of 'Man::load' function */

/*
 * Team functions.
 */

/* defualt constructor */
rfc::Team::Team(const ulong teamId) :
	id(teamId)
{
} /* end of 'Team' constructor */

/* constructor to load team from
 * file 'kbsx32.raftcomp.db' type
 */
rfc::Team::Team(FILE *fileIn, const ulong version)
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
const rfc::Team & rfc::Team::save(FILE *fileOut, const ulong version) const
{
	/* version 0 implement */
	std::fwrite(&id, sizeof(id), 1, fileOut);

	const ulong humanCnt = men.size();
	std::fwrite(&humanCnt, sizeof(humanCnt), 1, fileOut);

	/* save vector of stupid men */
	for (const auto &human : men)
		human.save(fileOut);

	return *this;
} /* end of 'Team::save' function */

/* load human from 'kbsx32.raftcomp.db' type file.
 * file formats:
 *   version 0:
 *     teamId   : 4 bytes (ulong).
 *     humanCnt : 4 bytes (ulong).
 *     humans[humanCnt] : ???
 */
rfc::Team & rfc::Team::load(FILE *fileIn, const ulong version)
{
	/* version 0 implement */

	/* loading team id */
	std::fread(&id, sizeof(id), 1, fileIn);

	/* loading stupid humen */
	ulong humanCnt;
	std::fread(&humanCnt, sizeof(humanCnt), 1, fileIn);

	for (ulong i = 0; i < humanCnt; ++i)
		men.push_back(Man(fileIn, version));

	return *this;
} /* end of 'Team::load' function */
