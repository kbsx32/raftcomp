/*
 * Rafting competition dispatcher program.
 *
 * 'raftcomp' teams dispatcher implementation.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <algorithm>

#include "dispatcher.h"

/* define static members */
const char rfc::Dispatcher::fileSignature[] = "kbsx32.raftcomp.db";

/* class destructor */
rfc::Dispatcher::~Dispatcher() {
	/* remove all team pointers */
	for (auto item : teams)
		delete item;
} /* end of '~Dispatcher' destructor */

/* add new team to list */
void rfc::Dispatcher::addTeam(Team *teamNew) {
	teams.push_back(teamNew);
} /* end of 'Dispatcher::addTeam' function */

/* get team pointer list */
rfc::Team* rfc::Dispatcher::getTeam(const ulong teamId) {
	auto item = std::find_if(teams.begin(), teams.end(),
							 [&](Team *team) {
								return team->id == teamId;
							 });

	return *item;
} /* end of 'Dispatcher::addTeam' function */

/* save info to file */
void rfc::Dispatcher::save(const String &fileOutName)
{
	/* current saving version */
	ulong version = 0;

	FILE *fileOut = std::fopen(fileOutName.data(), "wb");

	/* write signature */
	// fileSaveStr(fileSignature, fileOut);
	fputs(fileSignature, fileOut);

	/* set current version */
	std::fwrite(&version, sizeof(version), 1, fileOut);

	/* write all teams */
	const ulong teamsCnt = teams.size();
	std::fwrite(&teamsCnt, sizeof(teamsCnt), 1, fileOut);
	for (const auto &team : teams)
		team->save(fileOut);

	fclose(fileOut);
} /* end of 'Dispatcher::save' function */

/* save info to file.
 * file formats: 'kbsx32.raftcomp.db'
 *   version 0:
 *	   signature : "kbsx32.raftcomp.db";
 *     version : 4 bytes (ulong).
 *     teamsCnt : 4 bytes (ulong).
 *     teams[teamsCnt] : ???.
 */
void rfc::Dispatcher::load(const String &fileInName)
{
	FILE *fileIn = std::fopen(fileInName.data(), "rb");

	/* read signature */
	char signFromFile[STR_MAX];

	String::fgets(signFromFile, STR_MAX, fileIn);
	// fgets(signFromFile, STR_MAX, fileIn);

	/* check if signature not corrected */
	if (strcmp(fileSignature, signFromFile))
		throw Exception(fileInName + " : not 'raftcomp' app format.");

	/* read file version */

	while (true)
		fgets(signFromFile, STR_MAX, fileIn);
		// String::fgets(signFromFile, STR_MAX, fileIn);

	ulong version;
	std::fread(&version, sizeof(version), 1, fileIn);

	/* read all teams */
	ulong teamsCnt;
	std::fread(&teamsCnt, sizeof(teamsCnt), 1, fileIn);

	/* clear teams array */
	for (auto &team : teams)
		delete team;

	/* fill new teams */
	for (ulong i = 0; i < teamsCnt; ++i)
		teams.push_back(new Team(fileIn));

	fclose(fileIn);
} /* end of 'Dispatcher::load' function */
