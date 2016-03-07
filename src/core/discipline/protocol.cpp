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

/* explicitted constructor */
rfc::disc::Protocol::TeamScore::TeamScore(const TeamId id) :
	teamId(id),
	score(0)
{
} /* end of 'TeamScore' constructor */

/* explicitted constructor */
rfc::disc::Protocol::TeamScore::TeamScore() :
    teamId(0),
    score(0)
{
} /* end of 'TeamScore' constructor */

/* comparator */
bool rfc::disc::Protocol::TeamScore::operator<(const TeamScore &second) const
{
	if (score != second.score)
		return score > second.score;

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

/* loading proto from file */
rfc::disc::Protocol::Protocol(FILE *fileIn, const uint32_t version)
{
    if (version < 56)
        return ;

    uint32_t sz;
    fread(&sz, sizeof(sz), 1, fileIn);
    score.resize(sz);
    if (sz > 0)
        fread(&score[0], sizeof(score[0]), sz, fileIn);
} /* end of 'Protocol' constructor */

/* saving proto to file */
void rfc::disc::Protocol::save(FILE *fileOut, const uint32_t version)
{
    if (version < 56)
        return ;

    uint32_t sz = score.size();

    fwrite(&sz, sizeof(sz), 1, fileOut);
    fwrite(&score[0], sizeof(score[0]), sz, fileOut);
} /* end of 'save' function */

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
    scores(ENUM_CAST(disc::TypeDisc::COUNT)),
    typeSnapshots(ENUM_CAST(disc::TypeDisc::COUNT))
{
} /* end of 'addProtocol' function */

/* add info to map */
void rfc::disc::CompScore::addProtocol(const TypeDisc type, const Protocol &prot)
{
	scores[ENUM_CAST(type)] = prot;

	resultProt += prot;

    typeSnapshots[ENUM_CAST(type)] = resultProt;
} /* end of 'addProtocol' function */

/* return protocol.
 * if protocol doesn't exists - throws exception.
 */
rfc::disc::Protocol rfc::disc::CompScore::getProtocol(const TypeDisc type)
{
	return scores[ENUM_CAST(type)];
} /* end of 'getProtocol' function */

/* return full competition result */
rfc::disc::Protocol &rfc::disc::CompScore::getResultProtocol()
{
	resultProt.sort();
	return resultProt;
} /* end of 'getResultProtocol' function */

/* return full competition result for choosed moment */
rfc::disc::Protocol &rfc::disc::CompScore::getResultProtocol(const TypeDisc type)
{
    typeSnapshots[ENUM_CAST(type)].sort();
    return typeSnapshots[ENUM_CAST(type)];
} /* end of 'getResultProtocol' function */

/* return all protocols */
const rfc::disc::CompScore::ProtGroup & rfc::disc::CompScore::getProtocols()
{
	return scores;
} /* end of 'getResultProtocols' function */

/* return sorted array of
 * all teams.
 */
void rfc::disc::Protocol::sort()
{
	/* sorting result vector */
	std::sort(score.begin(), score.end());
} /* end of 'getSortedTeamsVector' function */

/* get score of team in protocol */
uint32_t rfc::disc::CompScore::findTeamResult(const disc::Type &type)
{
	Protocol &findAr = scores[ENUM_CAST(type.typeDisc)];

	Protocol::TeamScore const * tmRes = nullptr;

	for (const Protocol::TeamScore &tm : findAr.score)
		if (tm.teamId == type.teamId) {
			tmRes = &tm;
			break;
		}

	/* if can't find team */
	if (tmRes == nullptr)
		return 0; // throw Exception(lang::errorLogical);

	return tmRes->score;
} /* end of 'findTeamResult' function */

/* save all protocols to file */
void rfc::disc::CompScore::save(FILE *fileOut, const uint32_t version)
{
    if (version < 56)
        return ;

    for (Protocol &prot : scores)
        prot.save(fileOut, version);
    for (Protocol &prot : typeSnapshots)
        prot.save(fileOut, version);

    resultProt.save(fileOut, version);
}

/* load all protocols from file */
void rfc::disc::CompScore::load(FILE *fileIn, const uint32_t version)
{
    if (version < 56)
        return ;

    scores.resize(ENUM_CAST(TypeDisc::COUNT));
    typeSnapshots.resize(ENUM_CAST(TypeDisc::COUNT));

    for (Protocol &prot : scores)
        prot = Protocol(fileIn, version);
    for (Protocol &prot : typeSnapshots)
        prot = Protocol(fileIn, version);

    resultProt = Protocol(fileIn, version);
}
