#include "human.h"

/* default constructor */
rfc::men::Man::Man() {

} /* end of 'Man' constructor */

/* constructor by names */
rfc::men::Man::Man(const String &lastName,
				   const String &firstName,
				   const String &secondName) :
	lastName(lastName), firstName(firstName),
	secondName(secondName)
{
} /* end of 'Man' constructor */

/* load human from file 'kbsx32.raftcomp.db' type */
rfc::men::Man::Man(FILE *fileIn, const uint32_t version)
{
	load(fileIn, version);
} /* end of 'Man' constructor */

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
rfc::men::Man& rfc::men::Man::load(FILE *fileIn, const uint32_t version)
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
 * Instructor class
 */

/* default constructor.
 * adds to InstructorsTeam `this class instance.
 */
rfc::men::Instructor::Instructor(const String &lastName,
								 const String &firstName,
								 const String &secondName) :
	Man(lastName, firstName, secondName)
{
} /* end of 'Instructor' constructor */

/* comparator */
bool rfc::men::Instructor::operator<(const Instructor &inst1) const
{
	if (lastName != inst1.lastName)
		return lastName < inst1.lastName;

	if (firstName != inst1.firstName)
		return firstName < inst1.firstName;

	return secondName < inst1.secondName;
} /* end of 'operator<' function */

/*
 * Instructors team
 */

/* add instructor.
 * returns self-reference.
 */
rfc::men::InstructorsTeam & rfc::men::InstructorsTeam::add(const Instructor &instr)
{
	Instructor instrNew = instr;

	instrNew.instructorsTeam = this;
	_instructors.insert(instrNew);

	return *this;
} /* end of 'InstructorTeam::add' function */

/* add instructor.
 * returns self-reference.
 */
rfc::men::InstructorsTeam & rfc::men::InstructorsTeam::remove(Instructor &instr)
{
	Instructor instrDel = instr;

	/* remove pointer from instructors team to
	 * he will not try to delete himself from current stor
	 */
	instrDel.instructorsTeam = nullptr;

	_instructors.erase(_instructors.find(instrDel));

	return *this;
} /* end of 'InstructorTeam::add' function */
