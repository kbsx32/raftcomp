/*
 * Rafting competition dispatcher program.
 *
 * Team single human declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_HUMAN_H
#define RFC_HUMAN_H

#include "../def.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* 'all about humans' namespace */
	namespace men
	{
		/* single man class declaration */
		class Man {
		public:
			String
				lastName,       		/* man family name  */
				firstName,				/*   and first name */
				secondName;             /*     and second name */

			ulong birthYear;            /* year of mans birth */

			/* human ranks variant */
			enum class Rank
			{
				NO_RANK,
				JUNIOR_3,
				JUNIOR_2,
				JUNIOR_1,
				ADULT_3,
				ADULT_2,
				ADULT_1,
				KMS,
				MS
			} rank = Rank::NO_RANK;		/* End of 'Rank' class */

		public:
			/* default constructor */
			Man();

			/* load human from file 'kbsx32.raftcomp.db' */
			Man(FILE *fileIn, const uint32_t version = 0);

			/* constructor by names */
			Man(const String &lastName,
				const String &firstName,
				const String &secondName = QString());

			/* save human to 'kbsx32.raftcomp.db' type file. */
			const Man& save(FILE *fileOut, const uint32_t version = 0) const;

			/* load human from 'kbsx32.raftcomp.db' type file.
			 *   version 0:
			 *     lastName  : char * : string.
			 *     firstName : char * : string;
			 */
			Man& load(FILE *fileIn, const uint32_t version = 0);
		}; /* end of 'Man' class */

		/* instructors team class forward decl. */
		class InstructorsTeam;

		/* Instructor class */
		class Instructor : public Man
		{
			/* only InstructorsTeam can change pointer to
			 * himself in this class */
			friend class InstructorsTeam;
		private:
			InstructorsTeam *instructorsTeam;
		public:
			/* default constructor.
			 * adds to InstructorsTeam `this class instance.
			 */
			explicit Instructor(const String &lastName,
								const String &firstName,
								const String &secondName = String());

			/* comparator */
			bool operator<(const Instructor &inst1) const;
		}; /* End of 'Instructor' class */

		/* instructors 'database' trainers */
		class InstructorsTeam
		{
		private:
			/* all instructors store */
			std::set<Instructor> _instructors;

		public:
			/* constant-reference to _instructors list */
			const std::set<Instructor> & instructors = _instructors;

			/* add instructor.
			 * returns self-reference.
			 */
			InstructorsTeam& add(const Instructor &instr);

			/* delete instructor.
			 * returns self-reference.
			 */
			InstructorsTeam& remove(Instructor &instr);
		}; /* end of 'InstructorsTeam' class */

	} /* end of 'men' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_HUMAN_H */
