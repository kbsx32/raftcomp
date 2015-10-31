#include "human.h"

/* default constructor */
rfc::men::Man::Man() {

} /* end of 'Man' constructor */

/* constructor by names */
void rfc::men::Man::setNames(const String &lastName,
							 const String &firstName,
							 const String &secondName)
{
	this->lastName = lastName;
	this->firstName = firstName;
	this->secondName = secondName;
} /* end of 'Man::setNames' function */

/* save human to 'kbsx32.raftcomp.db' type file */
const rfc::men::Man& rfc::men::Man::save(FILE *fileOut, const uint32_t version) const
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
rfc::men::Man* rfc::men::Man::load(FILE *fileIn, const uint32_t version)
{
	// if (version >= 0) {

	/* loading info */
	char str[STR_MAX];  /* prepared buffer */

	String::fgets(str, STR_MAX, fileIn);
	lastName = str;

	String::fgets(str, STR_MAX, fileIn);
	firstName = str;

	return this;
} /* end of 'Man::load' function */

/* parse rank function.
 * argument:
 * one of the next strings:
 *   MS : sports master,
 *   KMS : candidate to sports master.
 *   1, 2, 3 : adult ranks.
 *   1J, 2J, 3J : junior ranks.
 *   0 : no rank.
 */
rfc::men::Man::Rank rfc::men::Man::parseRank(const String &str)
{
	if (str == lang::rankMS)
		return Rank::MS;
	else if (str == lang::rankKMS)
		return Rank::KMS;
	else if (str == lang::rankAdult1)
		return Rank::ADULT_1;
	else if (str == lang::rankAdult2)
		return Rank::ADULT_2;
	else if (str == lang::rankAdult3)
		return Rank::ADULT_3;

	else if (str == lang::rankJunior1)
		return Rank::JUNIOR_1;
	else if (str == lang::rankJunior2)
		return Rank::JUNIOR_2;
	else if (str == lang::rankJunior3)
		return Rank::JUNIOR_3;

	else if (str == lang::rank0)
		return Rank::NO_RANK;

	/* bad string */
	return Rank::NO_RANK;
} /* end of 'parseRank' function */

/* convert rank to string,
 * See string format at function
 * 'parseRank'.
 */
rfc::String rfc::men::Man::stringRank(const Rank rank)
{
	switch (rank)
	{
	case Rank::MS:
		return lang::rankMS;
	case Rank::KMS:
		return lang::rankKMS;
	case Rank::ADULT_1:
		return lang::rankAdult1;
	case Rank::ADULT_2:
		return lang::rankAdult2;
	case Rank::ADULT_3:
		return lang::rankAdult3;
	case Rank::JUNIOR_1:
		return lang::rankJunior1;
	case Rank::JUNIOR_2:
		return lang::rankJunior2;
	case Rank::JUNIOR_3:
		return lang::rankJunior3;
	case Rank::NO_RANK:
		return lang::rank0;
	}

	return "whaaat ?";
} /* end of 'stringRank' function */

/*
 * humans team
 */

/* destroy class */
rfc::men::MenDatabase::~MenDatabase()
{
	/* remove all men from database */
	for (auto &item : _men)
		delete item;
} /* end of '~MenDatabase' function */

/* get man identificator in MenDatabase
 * note :
 *   index can change, if you remove some humans
 *   from database. So, if you want to correctly save
 *   humen index, do not change humans vector
 *   in state between saving database and saving current human.
 */
uint32_t rfc::men::MenDatabase::getManIndex(const Man *man)
{
	const auto &val = std::find(_men.begin(), _men.end(), man);

	/* return shift of pointer */
	return &(*val) - &_men[0];
} /* end of 'MenDatabase::getManIndex' function */

/* add instructor.
 * returns reference to created man.
 */
rfc::men::Man * rfc::men::MenDatabase::manAdd()
{
	Man *manNew = new Man();
	_men.push_back(manNew);

	return manNew;
} /* end of 'InstructorTeam::add' function */

/* remove human. */
void rfc::men::MenDatabase::manRemove(const men::Man *manDel)
{
	_men.erase(std::find(_men.begin(), _men.end(), manDel));
} /* end of 'InstructorTeam::add' function */

/* save men database */
void rfc::men::MenDatabase::save(FILE *fout, const uint32_t version)
{
	uint32_t cntHumen = _men.size();

	fwrite(&cntHumen, sizeof(uint32_t), 1, fout);

	for (auto &man : _men)
		fwrite(man, sizeof(Man), 1, fout);
} /* end of 'save' function */

/* load men database */
void rfc::men::MenDatabase::load(FILE *fin, const uint32_t version)
{
	if (version < 1)
		return ;

	uint32_t cntHumen;

	fread(&cntHumen, sizeof(uint32_t), 1, fin);

	Man man;
	for (uint32_t i = 0; i < cntHumen; ++i) {
		fread(&man, sizeof(Man), 1, fin);
		_men.push_back(new Man(man));
	}
} /* end of 'load' function */
