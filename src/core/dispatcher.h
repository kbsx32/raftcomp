/*
 * Rafting competition dispatcher program.
 *
 * 'raftcomp' teams dispatcher header.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_DISPATCHER_H_
#define RFC_DISPATCHER_H_

#include "humen/team.h"
#include "discipline/ride_team.h"
#include "discipline/disciplines.h"

/* 'raftcomp' support namespace */
namespace rfc {

	/* global class support */
	class Dispatcher : public disc::Rides,
					   public men::MenDatabase,
					   public disc::CompScore
	{
	private:
		/* signature for saving database-competition files */
		static const char fileSignature[]; /* = "kbsx32.rafrcomp.dbc" */

		String fileSaving;  /* file to save */
	public:
		/* extension for saving format */
		static const String fileExt; /*  = String(".dbc"); */

		/* declared teams */
		std::vector<men::Team *> teams;

		/* add new team to list. */
		void addTeam(men::Team *teamNew);

		/* get team pointer from list */
		men::Team * getTeam(uint32_t teamId);

		/* save info to file.
         * current saving version : 56.
		 * see doc/format-dbc/v*.txt files
		 * to full info about saving format.
		 */
		void save(const String &fileOutName);

		/* save by Dispatcher's current saving file */
		void save();

		/* set default file to save */
		void setSavingFile(const String &file);

		/* get exists default saving file flag */
		bool isSavingFileSet();

		/* get default saving file name */
		const String getSavingFile();

		/* load info from file. */
		void load(const String &fileInName);

		/* reset all dispatcher info */
		void reset();

        /* get result protocol snapshot */
        disc::Protocol &getResultProtocolSnapshot(const disc::TypeDisc type);

		/* class destructor */
		~Dispatcher();
	}; /* end of 'CompDispatcher' class */
} /* end of 'rfc' namespace' */

#endif /* RFC_DISPATCHER_H_ */
