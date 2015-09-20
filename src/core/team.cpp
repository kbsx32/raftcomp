/*
 * Rafting competition dispatcher program.
 *
 * Team people info class implementation.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <cstdio>

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

/* defualt constructor */
rfc::Team::Team(const ulong teamId) :
	id(teamId)
{
} /* end of 'Team' constructor */

/* saving to file full progress */
void rfc::Team::saveToFile(const String &fileName) {
	FILE *fOut;

	if (!(fOut = fopen(fileName.toLatin1().data(), "wb")))
		Exception("error open saving file");

	fwrite(&men[0], sizeof(Man), 1, fOut);

	fclose(fOut);
} /* end of 'Team::saveToFile' function */

