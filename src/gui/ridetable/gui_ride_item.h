/*
 * Rafting competition dispatcher program.
 *
 * Gui table widget items declaration file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#pragma once
#ifndef RFC_GUI_RIDE_ITEM_H
#define RFC_GUI_RIDE_ITEM_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>

#include "../../core/dispatcher.h"

/* 'raftcomp' support namespace */
namespace rfc {
	namespace gui {

		/* forward declaration class */
		class PushPins;

		/* single pushpin edit */
		class Pin : public QLineEdit
		{
			Q_OBJECT

			const int pinId;	            /* pushpin identificator */
			rfc::RideTeam * rideTeam;	    /* connected lap */

		public:
			/* construcotr by pin identificator */
			Pin(rfc::RideTeam *rideTeam, const int pinNumber, gui::PushPins *parent = nullptr);

		signals:
			/* signal that pin changed */
			void signalPinChanged();
		public slots:
			/* 'onFinishEdit' catcher slot */
			void slotTextChanged();
		}; /* end of 'Pin' class */

		/* pushpins class */
		class PushPins : public QTableWidget
		{
			Q_OBJECT

			RideTeam *rideTeam;    /* connected ride team class */
		public:
			/* default constructor */
			PushPins(rfc::RideTeam *rideTeam, QWidget *parent = nullptr);

			/* update all pushpins info */
			void update();

			/* update all row function */
			void updateRow();
		signals:
			/* signal that pin was changer */
			void signalPinsChanged();

		public slots:
			/* pins changed slot */
			void slotPinsChanged();
		}; /* end of 'PushPins' class */

		class RideItem : public QLineEdit
		{
			Q_OBJECT

			RideTeam *lap;      /* connected to this widget lap */
			Team *team;         /* connected team */
		public:
			enum class Type {
				TEAM_ID,		/* team number */
				TEAM_HUMEN,     /* team humen */
				PINS,			/* pushpins */
				PENALTY_OTHER,	/* other penalties slot
								 * for example : bad team start, etc.
								 */
				PENALTY_SUM,	/* result penalty */
				TIME_START,		/* start lap time slot */
				TIME_END,		/* end lap time slot */
				TIME_DISTANCE,  /* distance time */
				TIME_RESULT,    /* summary time */
				PLACE,			/* place in lap */
				SCORE,			/* score given for that plaguice */
				END,            /* Last table slot */
			}; /* end of 'Type' enum class */

			Type type;					/* global semantics */

			/* class constructor.
			 * arguments:
			 *   team : connected team.
			 *   lapConnected : Lap connected with current element.
			 *   controlType : Lap subitem to control.
			 *   parent : controller parent widget.
			 */
			RideItem(Team *team, RideTeam *lapConnected, Type controlType, QWidget *parent = nullptr);

			/* update info function */
			void update();
		signals:
			/* signal editing of text finished */
			void signalTextEdited();
		public slots:

			/* capture changed text slot */
			void slotTextChanged();

		public:
			~RideItem()
			{
				// qDebug() << "closed ride item";
			}
		};
	} /* end of 'gui' namespace */
} /* end of 'rfc' namespace */

#endif /* RFC_GUI_RIDE_ITEM_H */
