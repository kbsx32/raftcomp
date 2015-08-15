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

/* time class support */
#include "base/laptime.h"

typedef unsigned long ulong;

/* 'raftcomp' support namespace */
namespace rfc {
	/* redifinition of types */
	typedef ulong TeamId;
} /* end of 'rfc' namespace */

#endif /* RFC_DEF_H */

