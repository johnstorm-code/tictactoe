/* 
 * File:   rules.h
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
 * Created on April 26, 2012, 11:20 AM
 */

#ifndef RULES_H
#define	RULES_H

/* Check that user values are within ranges. 
 * Ranges: x = 0-2 && y = 0-2
 */
int iscoordoutrange(struct coord coor){
	int outrange = 0;
	if(DEBUG){
		printf("in iscoordoutrange() => coor.x => %i, coor.y => %i\n", coor.x, coor.y);
	}
	if(coor.x > MAX_COORDS_RANGE || coor.y > MAX_COORDS_RANGE || coor.x <= NO_MOVES || coor.y <= NO_MOVES){
		outrange = 1;
		cooroutrangemsg(coor);
		printmatrix();
	}
	return outrange;
}

/* Check coordinates already set in matrix grid.
 * If a player value has already been set return 1,
 * 0 otherwise. */
int ismoveset(struct coord coor){
	int mvset = 0;
	if(DEBUG){
		printf("in ismoveset() => coor.x => %i, coor.y => %i\n", coor.x, coor.y);
	}
	if(matrix[coor.x][coor.y] != NO_MOVES){
		mvset = 1;
		invalidmovemsg();
		printmatrix();
	}
	return mvset;
}

/* Check that the given x, y coordinates are separated by space 
 * or that it's length is == to 1 for block values 
 */
int isproperformat(char *coordinate){
	int isproper = 0;
	if(isspace(coordinate[1]) || xstrlen(coordinate) == 1){
		isproper = 1;
	}else{
		improperformatmsg(coordinate);
	}
	if(DEBUG){
		printf("in isproperformat() => coordinate[1] => %c\n", coordinate[1]);
	}
	return isproper;
}

/* Check that icon is not already in use */
int isiconused(){
	int used = 0;
	if(playicons.PLAYER1ICON == playicons.PLAYER2ICON){
			used = 1;
		}
	if(DEBUG){
		printf("in isiconused() => used => %i\n", used);
	}
	if(used == 1){
		iconusedmsg();
	}
	return used;
}

#endif	/* RULES_H */
