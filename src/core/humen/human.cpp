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
