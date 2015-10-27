/*
 * Rafting competition dispatcher program.
 *
 * All translations file.
 * See 'lang_translate.h' to full information.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "lang_translate.h"

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

rfc::String rfc::lang::greetText =
		"welcome to rafting competition dispatcher application.\n"
		"&Choose action:";

#endif /* end of 'default' */
