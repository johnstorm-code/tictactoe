/* 
 * File:   stats.h
 * Author: jstorm
 *
 * Copyright (C) 2012  jstorm
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Created on May 12, 2012, 6:54 PM
 */

#ifndef STATS_H
#define	STATS_H

/* Record each time a winner wins 
 * index 0 = player 1, index 1 = player 2, index 3 = draw
 */
void recordwinner(int winner){
	switch(winner){
		case 0:
			winstats[0] += 1;
			break;
		case 1:
			winstats[1] += 1;
			break;
		case 2:
			winstats[2] += 1;
			break;
	}
}

void printstats(){
	printf("\n");
	printf("Player 1 wins: %i\n", winstats[0]);
	printf("Player 2 wins: %i\n", winstats[1]);
	printf("Game Draws: %i\n", winstats[2]);
}

#endif	/* STATS_H */

