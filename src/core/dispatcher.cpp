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
const char rfc::Dispatcher::fileSignature[] = "kbsx32.raftcomp.dbc";
const rfc::String rfc::Dispatcher::fileExt(".dbc");

/* class destructor */
rfc::Dispatcher::~Dispatcher()
{
	reset();
} /* end of '~Dispatcher' destructor */

/* add new team to list */
void rfc::Dispatcher::addTeam(men::Team *teamNew)
{
	teams.push_back(teamNew);
} /* end of 'Dispatcher::addTeam' function */

/* get team pointer list */
rfc::men::Team* rfc::Dispatcher::getTeam(const uint32_t teamId)
{
	auto item = std::find_if(teams.begin(), teams.end(),
							 [&](men::Team *team) {
								return team->id == teamId;
							 });

	return *item;
} /* end of 'Dispatcher::addTeam' function */

/* save by Dispatcher's current saving file */
void rfc::Dispatcher::save()
{
	save(fileSaving);
} /* end of 'save' function */

/* set default file to save */
void rfc::Dispatcher::setSavingFile(const String &file)
{
	fileSaving = file;
} /* end of 'setSavingFile' function */

/* get exists default saving file flag */
bool rfc::Dispatcher::isSavingFileSet()
{
	return fileSaving != String();
} /* end of 'isSavingFileExists' function */

/* get default saving file name */
const rfc::String rfc::Dispatcher::getSavingFile()
{
	return fileSaving;
} /* end of 'getSavingFile' function */

/* save info to file.
 * current saving version : 1.
 * see doc/format-dbc/v*.txt files
 * to full info about saving format.
 */
void rfc::Dispatcher::save(const String &fileOutName)
{
	/* current saving version */
	uint32_t version = 3;

	FILE *fileOut = std::fopen(fileOutName.data(), "wb");

	/* write signature */
	String::putToFile(fileSignature, fileOut);

	/* set current version */
	std::fwrite(&version, sizeof(version), 1, fileOut);

	/* save men database */
	men::MenDatabase::save(fileOut, version);

	/* write all teams */
	const uint32_t teamsCnt = teams.size();
	std::fwrite(&teamsCnt, sizeof(teamsCnt), 1, fileOut);

	for (const auto &team : teams)
		team->save(fileOut, version);

	/* save rides */
	disc::Rides::save(fileOut, version);

	fclose(fileOut);
} /* end of 'Dispatcher::save' function */

/* load info from file. */
void rfc::Dispatcher::load(const String &fileInName)
{
	/* prepare dispatcher to new actions */
	reset();

	/* set new default file */
	fileSaving = fileInName;

	FILE *fileIn = std::fopen(fileInName.data(), "rb");

	if (fileIn == nullptr)
		return ;

	/* read signature */
	char signFromFile[STR_MAX];

	String::getFromFile(signFromFile, STR_MAX, fileIn);

	/* check if signature not corrected */
	if (strcmp(fileSignature, signFromFile))
		throw Exception(fileInName + " : not 'raftcomp' app format.");

	/* read file version */

	uint32_t version;
	std::fread(&version, sizeof(version), 1, fileIn);

	if (version == 0) {
		/* read all teams */
		uint32_t teamsCnt;
		std::fread(&teamsCnt, sizeof(teamsCnt), 1, fileIn);

		/* fill new teams */
		for (uint32_t i = 0; i < teamsCnt; ++i)
			teams.push_back(new men::Team(*this, fileIn, version));
	} else if (version > 1) {

		men::MenDatabase::load(fileIn, version);

		/* read all teams */
		uint32_t teamsCnt;
		std::fread(&teamsCnt, sizeof(teamsCnt), 1, fileIn);

		/* fill new teams */
		for (uint32_t i = 0; i < teamsCnt; ++i)
			teams.push_back(new men::Team(*this, fileIn, version));

		disc::Rides::load(fileIn, version);
	}

	fclose(fileIn);
} /* end of 'Dispatcher::load' function */

/* reset function */
void rfc::Dispatcher::reset()
{
	/* remove all team pointers */
	for (auto item : teams)
		delete item;

	teams.clear();
	fileSaving = String();

	Rides::reset();
} /* end of 'reset' function */
