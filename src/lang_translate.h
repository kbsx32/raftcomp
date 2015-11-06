/*
 * Rafting competition dispatcher program.
 *
 * All translations file.
 *
 * Current localization : Russian / English :
 *   define RFC_LANG_ENGLISH to use english.
 *   define RFC_LANG_RUSSIAN to use russian.
 *
 * by default uses english.
 *
 * This is header, which contains externs to lang_translate.cpp file strings declarations.
 * Such system will help to replace linked-libraries to replace languages.
 *
 * But now it is just header.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#ifndef RFC_LANG_TRANSLATE_H
#define RFC_LANG_TRANSLATE_H

#include "core/base/rstring.h"

/* 'raftcomp' namespace */
namespace rfc
{
	/* language namespace */
	namespace lang
	{
		extern rfc::String mandat;
		extern rfc::String qualify;
		extern rfc::String sprint;
		extern rfc::String slalom;
		extern rfc::String slalom1;
		extern rfc::String slalom2;
		extern rfc::String longRace;

		extern rfc::String createNewDatabase;
		extern rfc::String openExistingDatabase;
		extern rfc::String exit;
		extern rfc::String edit;
		extern rfc::String apply;
		extern rfc::String decline;

		extern rfc::String addNewTeam;

		extern rfc::String greetText;

		extern rfc::String teamId;
		extern rfc::String teamAddress;
		extern rfc::String teamName;

		extern rfc::String teamAddress;
		extern rfc::String teamName;

		extern rfc::String lastName;
		extern rfc::String firstName;
		extern rfc::String secondName;
		extern rfc::String age;
		extern rfc::String birthYear;

		extern rfc::String rank;
		extern rfc::String rankAbout;

		extern rfc::String rankMS;
		extern rfc::String rankKMS;
		extern rfc::String rankAdult1;
		extern rfc::String rankAdult2;
		extern rfc::String rankAdult3;
		extern rfc::String rankJunior1;
		extern rfc::String rankJunior2;
		extern rfc::String rankJunior3;
		extern rfc::String rank0;

		extern rfc::String familyNameSecName;

		extern rfc::String participants;
		extern rfc::String name;
		extern rfc::String addNewHuman;
		
		extern rfc::String tries;
		extern rfc::String activate;

		extern rfc::String id;
		extern rfc::String team;
		extern rfc::String timeStart;
		extern rfc::String penaltyOther;
		extern rfc::String penaltySummary;
		extern rfc::String place;
		extern rfc::String timeStart;
		extern rfc::String timeEnd;
		extern rfc::String timeOnDistance;
		extern rfc::String score;
		extern rfc::String pins;
		extern rfc::String timeResult;

		extern rfc::String finalize;

		extern rfc::String cantActivateDiscipline;
	} /* end of 'lang' namespace */
}
#endif /* RFC_LANG_TRANSLATE_H */
