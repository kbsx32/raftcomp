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
		/* forward declaration */
		class MenDatabase;

		/* single man class declaration */
		class Man {
			/* only men database can create human ( and delete obviosly ) */
			friend class MenDatabase;

		private:
			/* 'creator' database of this human */
			MenDatabase *databaseConnected;
		public:
			String
				lastName,       		/* man family name  */
				firstName,				/*   and first name */
				secondName;             /*     and second name */

			uint32_t birthYear;         /* year of mans birth */

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
			/* parse rank function.
			 * argument:
			 *   str : see 'lang::rankAbout'.
			 */
			static Rank parseRank(const String &str);

			/* convert rank to string,
			 * See string format at function
			 * 'parseRank'.
			 */
			static String stringRank(const Rank rank);

		private:
			/* default constructor */
			Man(MenDatabase *menDatabase);

			/* set names */
			void setNames(const String &lastName,
						  const String &firstName,
						  const String &secondName = QString());

		public:  /* deprecated (version of 'dbc' 0 is deprecated).
				  * TODO :
				  *   public --> private.
				  */
			/* save human to 'kbsx32.raftcomp.dbc' type file. */
			const Man& save(FILE *fileOut, const uint32_t version) const;

			/* load human from 'kbsx32.raftcomp.dbc' type file. */
			Man* load(FILE *fileIn, const uint32_t version);

		public:
			/* get index of human in connected database */
			uint32_t getIndexInDatabase();
		}; /* end of 'Man' class */

		/* humen 'database' trainers */
		class MenDatabase
		{
		private:
			/* all instructors store */
			std::vector<Man *> _men;

		public:
			/* constant-reference to _instructors list */
			const std::vector<Man *> & men = _men;

			/* destroy class */
			~MenDatabase();

			/* add instructor.
			 * returns pointer to created men.
			 */
			Man* manAdd();

			/* get man identificator in MenDatabase
			 * note :
			 *   index can change, if you remove some humans
			 *   from database. So, if you want to correctly save
			 *   humen index, do not change humans vector
			 *   in state between saving database and saving current human.
			 */
			uint32_t getManIndex(const Man *man);

			/* delete human. */
			void manRemove(const Man *man);

			/* reset all database */
			void reset();
		protected:
			/* save men database.
			 * required minimal version : 1;
			 */
			void save(FILE *fout, const uint32_t version);

			/* load men database
			 * required minimal version : 1;
			 */
			void load(FILE *fin, const uint32_t version);
		}; /* end of 'InstructorsTeam' class */

	} /* end of 'men' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_HUMAN_H */
