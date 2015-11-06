/*
 * Rafting competition dispatcher program.
 *
 * Mandat comission teams widget declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */


#pragma once
#ifndef RFC_GUI_MANDAT_H
#define RFC_GUI_MANDAT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QSignalMapper>
#include <QPushButton>
#include <QFormLayout>

/* include all core dispatcher support */
#include "../../core/dispatcher.h"

/* 'raftcomp' support namespace */
namespace rfc {
	/* graphical user interface elements namespace */
	namespace gui {
		namespace mandat
		{
			/* one men widget */
			class WMan : public QWidget
			{
				Q_OBJECT

				men::Man *man;

				QLineEdit
					*widgLastName,
					*widgFirstName,
					*widgSecondName,
					*widgBirthYear,
					*widgRank;

			public:
				/* constructor */
				WMan(men::Man *man, QWidget *parent = nullptr);

			public slots:
				/* apply changes slot */
				void slotChangesApply();
			}; /* end of 'MandatMan' class */

			/* one men widget */
			class WManInfo : public QWidget
			{
				Q_OBJECT

				men::Man *man;
				Dispatcher *dispatcher;

				QPushButton *widgInfo;
			public:
				/* constructor */
				WManInfo(Dispatcher *dispatcher, men::Man *man, QWidget *parent = nullptr);

				/* update info */
				void update();
			public slots:
				/* edit human */
				void slotEditClicked();
			}; /* end of 'MandatManInfo' class */

			/* Mandat comission single team drawer class */
			class WTeam : public QWidget
			{
				Q_OBJECT

			public:
				static const uint32_t
					butSizeX = 200,
					butSizeY = 100;

			private:
				men::Team *team;  /* connected data for widget */
				Dispatcher *dispatcher;

				QFormLayout *layoutHumen;   /* buttons to connect with info about stupid humen */

				/* all values */
				QLineEdit *widgTeamId;
				QLineEdit *widgTeamName;
				QLineEdit *widgTeamAddress;

			public:
				/* default constructor */
				explicit WTeam(Dispatcher *dispatcher, men::Team *team, QWidget *parent = nullptr);

				/* update info function */
				void update();
			public slots:
				/* apply all changes */
				void slotEditApply();

				/* add new human */
				void slotHumanAdd();
			}; /* end of 'MandatTeam' class */

			/* widgets shows minimal info about team
			 * and has button 'edit' to change info
			 * about team.
			 */
			class WTeamIntro : public QWidget
			{
				Q_OBJECT

				men::Team *team;		/* pointer to connected team */
				Dispatcher *dispatcher; /* dispatcher */
				QLabel *teamInfo;		/* info widget */
			public:
				/* constructor by pointer of team. */
				WTeamIntro(Dispatcher *dispatcher, men::Team *team, QWidget *parent = nullptr);

			public slots:
				/* slot that pushed 'edit' button */
				void slotClickedEditButton();

				/* update all widgets info */
				void update();
			}; /* end of 'MandatTeamMinimal' class */

			/* global mandat-table */
			class Mandat : public QWidget
			{
				Q_OBJECT

				rfc::Dispatcher *dispatcher;
			public:
				/* default constructor */
				explicit Mandat(rfc::Dispatcher *dispatcher, QWidget *parent = 0);

			public slots:
				/* pushed button to create new team */
				void slotCreateNewTeam();

				/* applying mandat comission */
				void slotFinalize();
			}; /* end of 'Mandat' class */
		} /* end of 'mandat' namespace */
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_MANDAT_H */
