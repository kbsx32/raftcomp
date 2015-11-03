/*
 * Rafting competition dispatcher program.
 *
 * All translations file.
 * See 'lang_translate.h' to full information.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "lang_translate.h"

using namespace rfc;

#ifdef RFC_LANG_RUSSIAN

rfc::String rfc::lang::mandat = "мандатная комиссия";
rfc::String rfc::lang::qualify = "квалификация";
rfc::String rfc::lang::sprint = "спринт";
rfc::String rfc::lang::slalom = "слалом";
rfc::String rfc::lang::slalom1 = "слалом. 1.";
rfc::String rfc::lang::slalom2 = "слалом. 2.";
rfc::String rfc::lang::longRace = "длинная гонка";

rfc::String rfc::lang::createNewDatabase = "создать новую базу данных";
rfc::String rfc::lang::openExistingDatabase = "открыть существующую базу данных";
rfc::String rfc::lang::exit = "выход";
rfc::String rfc::lang::edit = "изменить";

rfc::String rfc::lang::greetText =
		"Добро пожаловать в диспетчер соревнований по рафтингу.\n"
		"Долбанитесь об стенку, ибо всё находится в процессе разработки и \n";

#else /* default */

rfc::String rfc::lang::mandat = "mandat comission";
rfc::String rfc::lang::qualify = "qualification";
rfc::String rfc::lang::sprint = "sprint";
rfc::String rfc::lang::slalom = "slalom";
rfc::String rfc::lang::slalom1 = "slalom. 1.";
rfc::String rfc::lang::slalom2 = "slalom. 2.";
rfc::String rfc::lang::longRace = "long race";

rfc::String rfc::lang::createNewDatabase = "create new database";
rfc::String rfc::lang::openExistingDatabase = "open existing database";

rfc::String rfc::lang::exit = "exit";
rfc::String rfc::lang::edit = "edit";
rfc::String rfc::lang::apply = "apply";
rfc::String rfc::lang::decline = "decline";

rfc::String rfc::lang::addNewTeam = "add new team";

rfc::String rfc::lang::greetText =
		"welcome to rafting competition dispatcher application.\n"
		"Choose action:";

rfc::String rfc::lang::teamId = "team identificator";

rfc::String rfc::lang::teamAddress = "team's county, city, etc.";
rfc::String rfc::lang::teamName = "name of the team";

rfc::String rfc::lang::lastName = "last name";
rfc::String rfc::lang::firstName = "first name";
rfc::String rfc::lang::secondName = "second name";
rfc::String rfc::lang::age = "age";
rfc::String rfc::lang::birthYear = "year of birth";

rfc::String rfc::lang::rank = "rank";

rfc::String rfc::lang::rankMS = "MS";
rfc::String rfc::lang::rankKMS = "KMS";
rfc::String rfc::lang::rankAdult1 = "1";
rfc::String rfc::lang::rankAdult2 = "2";
rfc::String rfc::lang::rankAdult3 = "3";
rfc::String rfc::lang::rankJunior1 = "1J";
rfc::String rfc::lang::rankJunior2 = "2J";
rfc::String rfc::lang::rankJunior3 = "3J";
rfc::String rfc::lang::rank0 = "0";

rfc::String rfc::lang::rankAbout =
		"Rank values: \n"
		+ lang::rankMS + " : sport's master \n"
		+ lang::rankKMS + " sports master candidate, \n"
			+ lang::rankAdult1 + ","
			+ lang::rankAdult2 + ","
			+ lang::rankAdult3 + " : adult rank, \n"

			+ lang::rankJunior1 + ","
			+ lang::rankJunior2 + ","
			+ lang::rankJunior3 + " : junior rank, \n"
		+ lang::rank0 + " : no rank \n";


rfc::String rfc::lang::familyNameSecName = "NFS";

rfc::String rfc::lang::participants = "participants";
rfc::String rfc::lang::name = "name";
rfc::String rfc::lang::addNewHuman = "add new human";
rfc::String rfc::lang::tries = "tries";

#endif /* end of 'default' */
