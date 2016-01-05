/*
 * Rafting competition dispatcher program.
 *
 * All translations file.
 * See 'lang_translate.h' to full information.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 * chas16. <sveta.chuinyshena@gmail.com>
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
rfc::String rfc::lang::apply = "применить";
rfc::String rfc::lang::decline = "отменить";

rfc::String rfc::lang::addNewTeam = "добавить новую команду";

rfc::String rfc::lang::greetText =
		"добро пожаловать в диспетчер соревнований по рафтингу .\n"
		"Выберите действие :";

rfc::String rfc::lang::teamId = "номер команды";

rfc::String rfc::lang::teamAddress = "страна, город, т.д.";
rfc::String rfc::lang::teamName = "имя команды";

rfc::String rfc::lang::lastName = "фамилия";
rfc::String rfc::lang::firstName = "имя";
rfc::String rfc::lang::secondName = "отчество";
rfc::String rfc::lang::age = "возраст";
rfc::String rfc::lang::birthYear = "год рождения";

rfc::String rfc::lang::rank = "разряд";

rfc::String rfc::lang::rankMS = "МС";
rfc::String rfc::lang::rankKMS = "КМС";
rfc::String rfc::lang::rankAdult1 = "1";
rfc::String rfc::lang::rankAdult2 = "2";
rfc::String rfc::lang::rankAdult3 = "3";
rfc::String rfc::lang::rankJunior1 = "1Ю";
rfc::String rfc::lang::rankJunior2 = "2Ю";
rfc::String rfc::lang::rankJunior3 = "3Ю";
rfc::String rfc::lang::rank0 = "0";

rfc::String rfc::lang::rankAbout =
		"разряды: \n"
		+ lang::rankMS + " : мастер спорта \n"
		+ lang::rankKMS + " кандидат в МС, \n"
			+ lang::rankAdult1 + ","
			+ lang::rankAdult2 + ","
			+ lang::rankAdult3 + " : взрослые, \n"

			+ lang::rankJunior1 + ","
			+ lang::rankJunior2 + ","
			+ lang::rankJunior3 + " : юношеские, \n"
		+ lang::rank0 + " : без разряда \n";


rfc::String rfc::lang::familyNameSecName = "ФИО";

rfc::String rfc::lang::participants = "участники";
rfc::String rfc::lang::name = "имя";
rfc::String rfc::lang::addNewHuman = "добавить нового человека";
rfc::String rfc::lang::tries = "попытки";

rfc::String rfc::lang::activate = "активировать";

rfc::String rfc::lang::id = "id";
rfc::String rfc::lang::team  ="команда";
rfc::String rfc::lang::timeStart = "старт";
rfc::String rfc::lang::penaltyOther = "другие штрафы";
rfc::String rfc::lang::penaltySummary = "штраф";
rfc::String rfc::lang::place = "место";
rfc::String rfc::lang::timeEnd = "финиш";
rfc::String rfc::lang::timeOnDistance = "время";
rfc::String rfc::lang::score = "реультат";
rfc::String rfc::lang::pins = "вешки ";
rfc::String rfc::lang::timeResult = "время";

rfc::String rfc::lang::finalize = "завершить";

rfc::String rfc::lang::cantActivateDiscipline =
		"Вы не можете изменить дисциплину, так как предыдущая не была завершена. \n"
		"Завершите предыдущую дисциплину, чтобы начать эту";

rfc::String rfc::lang::mandatComissionAlreadyFinished =
		"Вы не можете поменять порядок дисциплин, так как мандатная комиссия уже завершена.";

rfc::String rfc::lang::sureToFinalizeStage =
		"Вы уверены, что хотите завершить данную дисциплину ?\n"
		"У вас не будет больше шансов вернуться сюда, если нажмёте 'Да'";

rfc::String rfc::lang::menuFile = "&File";
rfc::String rfc::lang::save = "&Сохранить";

rfc::String rfc::lang::rfcError = "&rfc : error";

rfc::String rfc::lang::competitionDatabase = "база данных соревнований";

rfc::String rfc::lang::errorLogical
					= "i don't understand, what the fucking hell "
					  "is going there.";

rfc::String rfc::lang::sprint_1_32 = "1 / 32";
rfc::String rfc::lang::sprint_1_16 = "1 / 16";
rfc::String rfc::lang::sprint_1_8 = "1 / 8";
rfc::String rfc::lang::sprint_1_4 = "1 / 4";
rfc::String rfc::lang::sprint_1_2 = "1 / 2";
rfc::String rfc::lang::sprint_final_b = "Финал Б";

rfc::String rfc::lang::nextStage = "следующий этап";

rfc::String rfc::lang::sprint_final_a = "Финал А";
rfc::String rfc::lang::sprintLap = "заезд";

#endif /* end of russian */
