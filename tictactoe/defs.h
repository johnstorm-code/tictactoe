/* 
 * File:   defs.h
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
 * Created on April 26, 2012, 11:17 AM
 */

#ifndef DEFS_H
#define	DEFS_H

#define MAX_ROUNDS 5					/* maximum rounds in a TTT game */
#define MAX_MATRIX_ELEMENTS 3		/* Maximum elements in a TTT matrix (3x3) */
#define MAX_COORD_CHARS 4			/* Maximum coord chars accepted including NULL */
#define MAX_CHARS 2					/* Maximum chars for single values including NULL */
#define NO_MOVES -1					/* Indicates no moves on grid */
#define PLAYER1 0					/* Player 1 = 0 on matrix grid */
#define PLAYER2 1					/* Player 2 = 1 on matrix grid */
#define COMPUTER PLAYER2			/* Computer = 1 on matrix grid */
#define MAX_COORDS_RANGE 2			/* Maximum range of acepted coordinates (x, y) = 0-2 */

#endif	/* DEFS_H */
