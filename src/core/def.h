/*
 * Rafting competition dispatcher program.
 *
 * Global project definitions file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_DEF_H
#define RFC_DEF_H

#include <cstdio>
#include <assert.h>
#include <string>
#include <vector>
#include <set>
#include <map>

/* Classes which must be included before memleak.
 * See 'base/memleak.h' file to understand why it
 * is important to include these files before memleak.
 */

#include <qsharedpointer.h>
#include <QString>
#include <QLayout>
#include <QVector>
#include <QMap>
#include <QVariant>

/* define global application sets */
#define RFC_APP_CREATOR "kbsx32"
#define RFC_APP_NAME "raftcomp"

/* base project classes */
#include "base/memleak.h"
#include "base/rstring.h"
#include "base/laptime.h"
#include "base/exception.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* redifinition of types */
	typedef uint32_t TeamId;

	static const uint32_t STR_MAX = 128;
} /* end of 'rfc' namespace */

/* static cast redefinition.
 * argument:
 *		VALUE - type from enum class.
 */
#define ENUM_CAST(VALUE) (static_cast<uint32_t>(VALUE))

/* static cast and shifting enum value.
 * argument:
 *		VALUE - type from enum class.
 *      SHIFT - shifting result.
 */
#define ENUM_SHIFTED(VALUE, SHIFT) \
	decltype(VALUE)(ENUM_CAST(VALUE) + SHIFT)

/* include language translations */
#include "../lang/lang_translate.h"

#endif /* RFC_DEF_H */

