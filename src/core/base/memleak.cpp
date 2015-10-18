/*
 * Rafting competition dispatcher program.
 *
 * memory leaks catching type implement.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

// #include <execinfo.h>

#include <QDebug>

#include "exception.h"
#include "memleak.h"

/* static constant declare */
rfc::MemLeak rfc::memLeakInstance;

/* leak-node conastructor.
 * arguments:
 *   file : allocation file.
 *   func : allocation function.
 *   stringNum : number of string where called allocation.
 */
rfc::MemLeak::Node::Node(const char *file, const char *func, const ulong stringNum) :
	file(file), func(func), stringNum(stringNum)
{
	// void **arr;
	// backtrace(arr, 100);
} /* end of 'MemLeak::Node' constructor. */

/* leak-node copying constructor */
rfc::MemLeak::Node::Node(const Node &nodeSrc) :
	file(nodeSrc.file), func(nodeSrc.func), stringNum(nodeSrc.stringNum)
{
} /* end of 'MemLeak::Node' constructor. */

/***
 * MemLeak class functions
 ***/

/* default constructor */
rfc::MemLeak::MemLeak()
{
} /* end of 'MemLeak' constructor */

/* add leak-note */
void rfc::MemLeak::add(const Node &node, Pointer allocPtr)
{
	_nodes.insert(std::pair<Pointer, Node>(allocPtr, node));
} /* end of 'MemLeak::add' function */

/* remove node for pointer */
void rfc::MemLeak::remove(void *allocPtr)
{
	auto node = _nodes.find(allocPtr);

	/* check is object connected to nodes */
	if (node != _nodes.end())
		_nodes.erase(node);
} /* end of 'MemLeak::remove' function */

/* class destructor */
rfc::MemLeak::~MemLeak()
{
	int cnt = _nodes.size(),
		current = 0;

	qDebug().resetFormat();
	qDebug().setAutoInsertSpaces(false);

	qDebug() << QString("Memory leaks found : %1").arg(cnt);

	for (const auto &i : _nodes) {
		qDebug()  << QString("[%1 / %2] memory leak : \n").arg(current).arg(cnt)
				  + "    file            : " + "\'" + i.second.file.c_str() + "' \n"
				  + "    string number   : " + QString::number(i.second.stringNum) + "\n"
				  + "    function caller : " + i.second.func.c_str() + "\n";

		++current;
	}
} /* end of '~MemLeak' function */


