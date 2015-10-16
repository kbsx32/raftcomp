/*
 * Rafting competition dispatcher program.
 *
 * memory leaks catching type declaration file.
 *
 * some notes :
 *   some developers use '::new' instead 'new' or 'operator new'.
 *   so if THIS file (memleak.h) includes before that
 *   there can be problem with compiling.
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_MEMLEAK_H
#define RFC_MEMLEAK_H

#include <cstdlib>

#include <string>
#include <map>

#include <new>

/* define to search memleaks */
#ifdef RFC_DEBUG
	#define RFC_MEMLEAK_CHECK
#endif

typedef unsigned long ulong;

/* rafting competition support namespace */
namespace rfc
{
	/* memory leaks class definition */
	class MemLeak
	{
	public:
		/* single leak node */
		struct Node
		{
			const std::string file, func;	 /* file and function names of allocation place. */
			const ulong stringNum;			 /* string number in file of allocation place. */

			/* leak-node conastructor.
			 * arguments:
			 *   file : allocation file.
			 *   func : allocation function.
			 *   stringNum : number of string where called allocation.
			 */
			Node(const char *file,
				 const char *func,
				 const ulong stringNum);

			/* leak-node copying constructor */
			Node(const Node &nodeSrc);
		}; /* end of 'Node' struct */

	private:
		typedef void * Pointer;				   /* type redefinition */
		std::map<Pointer, Node> _nodes;			   /* nodes to all alive memory objects */
		// std::map<void *, void *> mp;
	public:
		const std::map<Pointer, Node> &nodes = _nodes;   /* public const reference to nodes */

		/* default constructor */
		MemLeak();

		/* add leak-node */
		void add(const Node &node, Pointer allocPtr);

		/* remove node for pointer */
		void remove(Pointer allocPtr);

		/* class destructor */
		~MemLeak();
	}; /* end of 'MemLeak' class */

	/* Memory leaks class instance */
	extern rfc::MemLeak memLeakInstance;
} /* end of 'rfc' namespace */

/* catching operator new.
 * arguments:
 *   nodeNew : node with next data:
 *		allocSize : allocate size count.
 *		file : allocation file.
 *		func : allocation function.
 *		stringNum : number of string where called allocation.
 */
inline void * operator new(size_t allocSize, const rfc::MemLeak::Node &nodeNew)
{
	void *ptr = ::operator new(allocSize);

	rfc::memLeakInstance.add(nodeNew, ptr);
	return ptr;
} /* end of 'new' function */

/* catching operator new[].
 * arguments:
 *   nodeNew : node with next data:
 *		allocSize : allocate size count.
 *		file : allocation file.
 *		func : allocation function.
 *		stringNum : number of string where called allocation.
 */
inline void * operator new[](size_t allocSize, const rfc::MemLeak::Node &nodeNew)
{
	void *ptr = ::operator new[](allocSize);

	rfc::memLeakInstance.add(nodeNew, ptr);
	return ptr;
} /* end of 'new[]' function */

/* catching operator delete.
 * arguments:
 *   nodeNew : node with next data:
 *		allocSize : allocate size count.
 *		file : allocation file.
 *		func : allocation function.
 *		stringNum : number of string where called allocation.
 */
inline void operator delete(void *ptr)
{
	rfc::memLeakInstance.remove(ptr);

	::operator delete(ptr, std::nothrow);
} /* end of 'delete' function */

/* catching operator delete[].
 * arguments:
 *   nodeNew : node with next data:
 *		allocSize : allocate size count.
 *		file : allocation file.
 *		func : allocation function.
 *		stringNum : number of string where called allocation.
 */
inline void operator delete[](void *ptr)
{
	rfc::memLeakInstance.remove(ptr);

	::operator delete[](ptr, std::nothrow);
} /* end of 'delete' function */

#ifdef RFC_MEMLEAK_CHECK
	/* redefine 'new' operator.
	 * arguments:
	 *     __FILE__ : current file.
	 *     __FUNCTION__ : current function.
	 *     __LINE__ : current line in file.
	 */
	#define new new(rfc::MemLeak::Node(__FILE__, __FUNCTION__, __LINE__))

#endif /* RFC_MEMLEAK_CHECK */

#endif /* RFC_MEMLEAK_H */
