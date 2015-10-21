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
 * See 'base/memleak.h' file to undarstand why it
 * is important to include these files before memleak.
 */

#include <qsharedpointer.h>
#include <QString>
#include <QLayout>
#include <QVector>
#include <QMap>
#include <QVariant>

/* base project classes */
#include "base/memleak.h"
#include "base/rstring.h"
#include "base/laptime.h"
#include "base/exception.h"

typedef unsigned long ulong;

/* 'raftcomp' support namespace */
namespace rfc {
	/* redifinition of types */
	typedef ulong TeamId;

	static const ulong STR_MAX = 128;
} /* end of 'rfc' namespace */

/* Column static cast redefinition
 * argument:
 *		VALUE - column type from enum class.
 */
#define ENUM_CAST(VALUE) static_cast<ulong>(VALUE)

/* include language translations */
#include "../lang_translate.h"

#endif /* RFC_DEF_H */

