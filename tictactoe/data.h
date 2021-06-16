/* 
 * File:   data.h
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
 * Created on April 26, 2012, 11:21 AM
 */

#ifndef DATA_H
#define	DATA_H

/* TTT matrix of (9) elements */
int matrix[MAX_MATRIX_ELEMENTS][MAX_MATRIX_ELEMENTS];

/* Coordinate system x, y */
struct coord{
	int x;
	int y;
}game_coords;

/* Number of players - default 1, -1 for simm */
int players = 1;

/* The order of moves -1 = reverse order, 1 = sequential order 
 * Default is sequential
 */
int moveorder = 1;

/* Define a structure for icons */
struct icons{
	char PLAYER1ICON;
	char PLAYER2ICON;
}playicons;

/* winner stats - holds n-times player wins */
int winstats[3] = {0};

#endif	/* DATA_H */
