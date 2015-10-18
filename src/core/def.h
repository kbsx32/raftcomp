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

#include <assert.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <QString>
#include <QLayout>

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
} /* end of 'rfc' namespace */

/* Column static cast redefinition
 * argument:
 *		VALUE - column type from enum class.
 */
#define ENUM_CAST(VALUE) static_cast<ulong>(VALUE)

#endif /* RFC_DEF_H */

