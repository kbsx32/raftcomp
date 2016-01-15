/*
 * Rafting competition dispatcher program.
 *
 * Gui preview protocol window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "gui_protocol.h"

rfc::gui::Protocol::Protocol(Dispatcher *disp, QWidget *parent) :
	QTableWidget(parent),
	dispatcher(disp)
{
	/* activating signal capture */
	connect(this, SIGNAL(activated(QModelIndex)),
			this, SLOT(slotWindowActivated()));

	update();
} /* end of 'Protocol' constructor */

/* reinitting info in table */
void rfc::gui::Protocol::update()
{
	enum class Columns
	{
		ID,
		NAME,
		PEOPLE,

		/* control gives to protocol loops generating. */
		DISCIPLINES_BEGIN = 3,
		DISCIPLINES_END = ENUM_CAST(disc::TypeDisc::COUNT)
						  - ENUM_CAST(disc::TypeDisc::QUALIFY)
						  + ENUM_CAST(Columns::DISCIPLINES_BEGIN),

		SCORE_RESULT,
		PLACE,
		END,
		COUNT = END,
	};

	this->clear();

	disc::Protocol &resProt = dispatcher->getResultProtocol();

	uint32_t teamsCnt = resProt.score.size();

	this->setColumnCount(ENUM_CAST(Columns::COUNT));
	this->setRowCount(teamsCnt);

	/* generating table */
	uint32_t
		discIndBegin = ENUM_CAST(Columns::DISCIPLINES_BEGIN),
		discIndEnd = ENUM_CAST(Columns::DISCIPLINES_END);

	for (uint32_t teamInd = 0; teamInd < teamsCnt; ++teamInd)
		for (uint32_t col = 0; col< ENUM_CAST(Columns::COUNT); ++col) {
			/* check if filling discipline */
			if (col >= discIndBegin && col < discIndEnd)
			{
				/* shift to previous */
				disc::TypeDisc td =
						ENUM_SHIFTED(disc::TypeDisc::QUALIFY, col - discIndBegin);

				uint32_t res = dispatcher->findTeamResult(disc::Type(td, resProt.score[teamInd].teamId));

				this->setItem(teamInd, col, new QTableWidgetItem(QString::number(res)));
			}

			/* another columns filling */
			setItem(teamInd, ENUM_CAST(Columns::SCORE_RESULT),
					new QTableWidgetItem(QString::number(resProt.score[teamInd].score)));

			setItem(teamInd, ENUM_CAST(Columns::ID),
					new QTableWidgetItem(QString::number(resProt.score[teamInd].teamId)));

		}
} /* end of 'update' function */

/* activated window slot.
 * calls window updating.
 */
void rfc::gui::Protocol::slotWindowActivated()
{
	update();
} /* end of 'slotWindowActivated' function */
