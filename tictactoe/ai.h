/* 
 * File:   ai.h
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
 * Created on April 28, 2012, 9:05 PM
 */

#ifndef AI_H
#define	AI_H

/* Checks if there is possibility player will win */
int iswinpossible(int player){
	int posswin = 0;
	
	/* Horizontal */
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		if(matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == NO_MOVES){
			posswin = 1;
		}
		if(matrix[i][0] == player && matrix[i][2] == player && matrix[i][1] == NO_MOVES){
			posswin = 1;
		}
		if(matrix[i][1] == player && matrix[i][2] == player && matrix[i][0] == NO_MOVES){
			posswin = 1;
		}
	}
	
	/* Diagonal top to bottom */
	if(matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == NO_MOVES){
		posswin = 1;
	}
	if(matrix[0][0] == player && matrix[2][2] == player && matrix[1][1] == NO_MOVES){
		posswin = 1;
	}
	if(matrix[1][1] == player && matrix[2][2] == player && matrix[0][0] == NO_MOVES){
		posswin = 1;
	}
	
	/* Vertical */
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		if(matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == NO_MOVES){
			posswin = 1;
		}
		if(matrix[0][i] == player && matrix[2][i] == player && matrix[1][i] == NO_MOVES){
			posswin = 1;
		}
		if(matrix[1][i] == player && matrix[2][i] == player && matrix[0][i] == NO_MOVES){
			posswin = 1;
		}
	}
	
	/* Diagonal bottom to top */
	if(matrix[2][0] == player && matrix[1][1] == player && matrix[0][2] == NO_MOVES){
		posswin = 1;
	}
	if(matrix[2][0] == player && matrix[0][2] == player && matrix[1][1] == NO_MOVES){
		posswin = 1;
	}
	if(matrix[1][1] == player && matrix[0][2] == player && matrix[2][0] == NO_MOVES){
		posswin = 1;
	}
	
	if(DEBUG){
		printf("in iswinposs() => player => %i, posswin => %i\n", player, posswin);
	}
	
	return posswin;
}

/* Sets coordinates to prevent player from winning */
struct coord preventwin(int player){
	struct coord preventwin;
	
	/* Horizontal */
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		if(matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == NO_MOVES){
			preventwin.x = i;
			preventwin.y = 2;
		}
		if(matrix[i][0] == player && matrix[i][2] == player && matrix[i][1] == NO_MOVES){
			preventwin.x = i;
			preventwin.y = 1;
		}
		if(matrix[i][1] == player && matrix[i][2] == player && matrix[i][0] == NO_MOVES){
			preventwin.x = i;
			preventwin.y = 0;
		}
	}
	
	/* Diagonal top to bottom */
	if(matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == NO_MOVES){
		preventwin.x = 2;
		preventwin.y = 2;
	}
	if(matrix[0][0] == player && matrix[2][2] == player && matrix[1][1] == NO_MOVES){
		preventwin.x = 1;
		preventwin.y = 1;
	}
	if(matrix[1][1] == player && matrix[2][2] == player && matrix[0][0] == NO_MOVES){
		preventwin.x = 0;
		preventwin.y = 0;
	}
	
	/* Vertical */
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		if(matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == NO_MOVES){
			preventwin.x = 2;
			preventwin.y = i;
		}
		if(matrix[0][i] == player && matrix[2][i] == player && matrix[1][i] == NO_MOVES){
			preventwin.x = 1;
			preventwin.y = i;
		}
		if(matrix[1][i] == player && matrix[2][i] == player && matrix[0][i] == NO_MOVES){
			preventwin.x = 0;
			preventwin.y = i;
		}
	}
	
	/* Diagonal bottom to top */
	if(matrix[2][0] == player && matrix[1][1] == player && matrix[0][2] == NO_MOVES){
		preventwin.x = 0;
		preventwin.y = 2;
	}
	if(matrix[2][0] == player && matrix[0][2] == player && matrix[1][1] == NO_MOVES){
		preventwin.x = 1;
		preventwin.y = 1;
	}
	if(matrix[1][1] == player && matrix[0][2] == player && matrix[2][0] == NO_MOVES){
		preventwin.x = 2;
		preventwin.y = 0;
	}
	
	if(DEBUG){
		printf("in prevwincoord() => player => %i, preventwin.x => %i, preventwin.y => %i\n", player, preventwin.x, preventwin.y);
	}
	return preventwin;
}

/* Check for winner by looking at 8 possible win scenarios.
 * If a win is encountered return 1, 0 otherwise. 
 */
int iswinner(int player){
	int win = 0;
	
	/* Horizontal */
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		if(matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player){
			win = 1;
		}
	}
	
	/* Diagonal */
	if(matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player){
		win = 1;
	}
	
	/* Vertical */
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		if(matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player){
			win = 1;
		}
	}
	
	/* Diagonal */
	if(matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player){
		win = 1;
	}	

	if(DEBUG){
		printf("in iswinner() => win => %i\n", win);
	}
	
	return win;
}

#endif	/* AI_H */

