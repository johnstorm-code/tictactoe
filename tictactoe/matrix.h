/* 
 * File:   matrix.h
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
 * Created on April 26, 2012, 11:34 AM
 */

#ifndef MATRIX_H
#define	MATRIX_H

/* Print all matrix grid values (formated) */
void printmatrix(){
	printf("\n");
	printf("   1   2   3 \n");
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		printf(" |-----------|\n");
		printf("%i", (i+1));
		for(int j = 0; j < MAX_MATRIX_ELEMENTS; j++){
			if(matrix[i][j] == NO_MOVES){
				printf("| %c ", ' ');
			}else{
				if(matrix[i][j] == PLAYER1){
					printf("| %c ", playicons.PLAYER1ICON);
				}else{
					printf("| %c ", playicons.PLAYER2ICON);
				}
			}
		}
		printf("|\n");
	}
	printf(" |-----------|\n");
}

#endif	/* MATRIX_H */
