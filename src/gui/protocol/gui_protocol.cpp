/*
 * Rafting competition dispatcher program.
 *
 * Gui preview protocol window class.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include <QHeaderView>

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

        SCORE_RESULT = DISCIPLINES_END,
		PLACE,
		END,
		COUNT = END,
	};

	this->clear();

	disc::Protocol &resProt = dispatcher->getResultProtocol();

	uint32_t teamsCnt = resProt.score.size();

	this->setColumnCount(ENUM_CAST(Columns::COUNT));
    // this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->setRowCount(teamsCnt);

    /* init table headers */
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::ID),              new QTableWidgetItem(lang::id));
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::NAME),            new QTableWidgetItem(lang::name));
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::PEOPLE),          new QTableWidgetItem(lang::people));
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::SCORE_RESULT),    new QTableWidgetItem(lang::score));
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::PLACE),           new QTableWidgetItem(lang::place));

    this->setHorizontalHeaderItem(ENUM_CAST(Columns::DISCIPLINES_BEGIN) + 0, new QTableWidgetItem(lang::qualify));
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::DISCIPLINES_BEGIN) + 1, new QTableWidgetItem(lang::sprint));
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::DISCIPLINES_BEGIN) + 2, new QTableWidgetItem(lang::slalom));
    this->setHorizontalHeaderItem(ENUM_CAST(Columns::DISCIPLINES_BEGIN) + 3, new QTableWidgetItem(lang::longRace));

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

            men::Team *team = dispatcher->getTeam(resProt.score[teamInd].teamId);
            setItem(teamInd, ENUM_CAST(Columns::NAME), new QTableWidgetItem(team->teamName));
            setItem(teamInd, ENUM_CAST(Columns::PEOPLE), new QTableWidgetItem(team->getSurnames()));
            setItem(teamInd, ENUM_CAST(Columns::PLACE), new QTableWidgetItem(QString::number(teamInd + 1)));
        }
} /* end of 'update' function */

/* activated window slot.
 * calls window updating.
 */
void rfc::gui::Protocol::slotWindowActivated()
{
	update();
} /* end of 'slotWindowActivated' function */
