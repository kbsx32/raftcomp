/*
 * Rafting competition dispatcher program.
 *
 * Disciplines classes functions implementation file.
 *
 * kbsx32. <kbsx32@yandex.ru>.
 */

#include "disciplines.h"

/* add new lap function */
void rfc::disc::Sprint::addNewLap(const LapType Type, const Lap &lap) {
	laps[Type] = lap;
} /* end of 'DiscSprint::addNewLap' function */

/* get lap info */
rfc::Lap& rfc::disc::Sprint::getLapInfo(const LapType Type) {
	return laps[Type];
} /* end of 'DiscSprint::GetLapInfp' function */
