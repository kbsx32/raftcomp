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
rfc::String rfc::lang::slalom0 = "слалом. 1.";
rfc::String rfc::lang::slalom1 = "слалом. 2.";
rfc::String rfc::lang::longRace = "длинная гонка";


#else /* default */

rfc::String rfc::lang::mandat = "mandat comission";
rfc::String rfc::lang::qualify = "qualification";
rfc::String rfc::lang::sprint = "sprint";
rfc::String rfc::lang::slalom0 = "slalom. 1.";
rfc::String rfc::lang::slalom1 = "slalom. 2.";
rfc::String rfc::lang::longRace = "long race";

#endif /* end of 'default' */