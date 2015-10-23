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
		extern rfc::String slalom0;
		extern rfc::String slalom1;
		extern rfc::String longRace;

		extern rfc::String createNewDatabase;
		extern rfc::String openExistingDatabase;
		extern rfc::String exit;
	} /* end of 'lang' namespace */
}
#endif /* RFC_LANG_TRANSLATE_H */
