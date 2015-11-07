/*
 * Rafting competition dispatcher program.
 *
 * Discipline result protocol widget.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "protocol.h"

/* constructor */
rfc::disc::Protocol::TeamScore::TeamScore(const TeamId teamId, const uint32_t score) :
	teamId(teamId),
	score(score)
{
} /* end of 'TeamScore' constructor */

/* comparator */
bool rfc::disc::Protocol::TeamScore::operator<(const TeamScore &second) const
{
	if (score != second.score)
		return score < second.score;

	return teamId < second.teamId;
} /* end of 'operator<' function */

/*
 * protocol functions.
 */

/* default constructor */
rfc::disc::Protocol::Protocol()
{
} /* end of 'Protocol' constructor */

/* constructor by rides array */
rfc::disc::Protocol::Protocol(const std::vector<RideTeam *> &vec)
{
	/*
	for (const auto &item : vec)
		score[((RideTeam *)item)->getItemId()]
	*/
} /* end of 'Protocol' constructor */

/* copying constructor */
rfc::disc::Protocol::Protocol(const Protocol &src) :
	score(src.score)
{
} /* end of 'Protocol' constructor */

/* sum all results from protocols
 * returns self-reference.
 */
rfc::disc::Protocol & rfc::disc::Protocol::operator+=(const Protocol &prot1)
{
	for (const auto &val : prot1.score) {
		/* find given team element in vector */
		const auto &item = std::find_if(score.begin(), score.end(),
										[&](const TeamScore &score)
										{
											return score.teamId == val.teamId;
										});

		/* if protocol is empty now */
		if (item == score.end())
			score.push_back(val);
		else
			/* get value from iterator */
			(*item).score += val.score;
	}

	return *this;
} /* end of 'operator+=' function */

/* add info to map */
rfc::disc::CompScore::CompScore() :
	scores(ENUM_CAST(disc::TypeDisc::COUNT))
{
} /* end of 'addProtocol' function */

/* add info to map */
void rfc::disc::CompScore::addProtocol(const TypeDisc type, const Protocol &prot)
{
	scores[ENUM_CAST(type)] = prot;

	resultProt += prot;
} /* end of 'addProtocol' function */

/* return protocol.
 * if protocol doesn't exists - throws exception.
 */
rfc::disc::Protocol rfc::disc::CompScore::getProtocol(const TypeDisc type)
{
	return scores[ENUM_CAST(type)];
} /* end of 'getProtocol' function */

/* return full competition result */
rfc::disc::Protocol rfc::disc::CompScore::getResultProtocol()
{
	resultProt.sort();
	return resultProt;
} /* end of 'getResultProtocol' function */

/* return sorted array of
 * all teams.
 */
void rfc::disc::Protocol::sort()
{
	/* sorting result vector */
	std::sort(score.begin(), score.end(),
			  [&](const TeamScore &t0, const TeamScore &t1)
			  {
				return t0.score < t1.score;
			  }
	);
} /* end of 'getSortedTeamsVector' function */
