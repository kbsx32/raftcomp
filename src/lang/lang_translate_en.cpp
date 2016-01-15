/*
 * Rafting competition dispatcher program.
 *
 * All translations file.
 * See 'lang_translate.h' to full information.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "lang_translate.h"

/* english language */
#ifdef RFC_LANG_ENGLISH

using namespace rfc;

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

rfc::String rfc::lang::activate = "activate";

rfc::String rfc::lang::id = "id";
rfc::String rfc::lang::team  ="team";
rfc::String rfc::lang::timeStart = "time start";
rfc::String rfc::lang::penaltyOther = "other penalties";
rfc::String rfc::lang::penaltySummary = "penalties summary";
rfc::String rfc::lang::place = "place";
rfc::String rfc::lang::timeEnd = "finish";
rfc::String rfc::lang::timeOnDistance = "time";
rfc::String rfc::lang::score = "result";
rfc::String rfc::lang::pins = "pins ";
rfc::String rfc::lang::timeResult = "time result";

rfc::String rfc::lang::finalize = "finalize";

rfc::String rfc::lang::cantActivateDiscipline =
		"You can't change discipline because previous wasn't finished. \n"
		"Please, finalize other discipline to start such";

rfc::String rfc::lang::mandatComissionAlreadyFinished =
		"You can't change disciplines order because mandat comission already finished.";

rfc::String rfc::lang::sureToFinalizeStage =
		"Are you sure you wan't to finalize current stage.\n"
		"You won't be able to return this stage if you push 'Yes'";

rfc::String rfc::lang::menuFile = "&File";
rfc::String rfc::lang::save = "&Save";

rfc::String rfc::lang::rfcError = "&rfc : error";

rfc::String rfc::lang::competitionDatabase = "competition database";

rfc::String rfc::lang::errorLogical
					= "i don't understand, what the fucking hell "
					  "is going there.";

rfc::String rfc::lang::sprint_1_32 = "1 / 32";
rfc::String rfc::lang::sprint_1_16 = "1 / 16";
rfc::String rfc::lang::sprint_1_8 = "1 / 8";
rfc::String rfc::lang::sprint_1_4 = "1 / 4";
rfc::String rfc::lang::sprint_1_2 = "1 / 2";
rfc::String rfc::lang::sprint_final_b = "final b";

rfc::String rfc::lang::nextStage = "next stage";

rfc::String rfc::lang::sprint_final_a = "final a";
rfc::String rfc::lang::sprintLap = "sprint lap";

rfc::String rfc::lang::impossible = "it is impossible";

rfc::String rfc::lang::protocol = "protocol";

#endif /* end of 'default' */
