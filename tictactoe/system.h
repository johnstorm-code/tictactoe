/* 
 * File:   system.h
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
 * Created on April 26, 2012, 11:36 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

/* Initializes the matrix to -1 values (no moves on grid) */
void initmatrix(){
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		for(int j = 0; j < MAX_MATRIX_ELEMENTS; j++){
			matrix[i][j] = NO_MOVES;
		}
	}
}

/* Initialize the default player icons */
void initicons(){
	playicons.PLAYER1ICON = 'O';
	playicons.PLAYER2ICON = 'X';
}

/* Initialize coordinates */
void initcoord(){
	game_coords.x = 0;
	game_coords.y = 0;
}

void init(){
	initmatrix();
	initicons();
	initcoord();
}

#endif	/* SYSTEM_H */
