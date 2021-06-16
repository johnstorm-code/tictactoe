/* 
 * File:   game.h
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
 * Created on April 26, 2012, 11:25 AM
 */

#ifndef GAME_H
#define	GAME_H

/* Sets player coordinates */
void setcoord(struct coord c, int player){
	if(DEBUG){
		printf("in setcoord() => c.x => %i, c.y => %i, player => %i\n", c.x, c.y, player);
	}
	matrix[c.x][c.y] = player;
}

/* Gets a move for each physical player */
struct coord getmove(int player, char playvalue){
	char coordinate[MAX_COORD_CHARS];
	struct coord currmove;
	
	/* Ensure physical players enter proper values */
	do{
		printf("\n");
		printf("Player %i (%c), enter coordinates or block value 1-9: ", (player+1), playvalue);
		xgets(coordinate, MAX_COORD_CHARS);
		if(DEBUG){
			printf("in getmove() => coordinates => %s\n", coordinate);
		}
		/* check for single value to indicate a block between 1 - 9 */
		if(xstrlen(coordinate) == 1 && xatoi(coordinate[0]) >= 1 && xatoi(coordinate[0]) <= 9){
			currmove = blocktocoord(xatoi(coordinate[0]));
		}else{
			currmove.x = xatoi((coordinate[0]-1));
			currmove.y = xatoi((coordinate[2]-1));
		}
	}while(ismoveset(currmove) || !isproperformat(coordinate) || iscoordoutrange(currmove));
	
	if(DEBUG){
		printf("in getmove() => currmove.x => %i, currmove.y => %i\n", currmove.x, currmove.y);
	}
	/* If all is within range, return the coordinates for player */
	return currmove;
}

int play(){
	/* Statistics - 2 = draw */
	int winner = 2;
	
	/* Handle simulation playing */
	if(players == -1){
		winner = simmplay();
		return winner;
	}
	
	/* For 2 players and sequential order - always display initial grid */
	if(players == 2 || moveorder == 1){
		printmatrix();
	}
		
	/* Game is comprised of 5 rounds. 
	 * A winner is checked every time a move is made.
	 * A computer move is played when the number of players is 1.
	 * If a winner is found, the game ends, if no winners, end with draw.
	 */
	for(int i = 0; i < MAX_ROUNDS; i++){
		if(DEBUG){
			printf("in play() => round => %i\n", i);
		}
		/* Get moves in sequential order */
		if(moveorder == 1){
			setcoord(getmove(PLAYER1, playicons.PLAYER1ICON), PLAYER1);
			printmatrix();
			if(iswinner(PLAYER1)){
				winner = PLAYER1;
				winnermsg(PLAYER1, playicons.PLAYER1ICON);
				break;
			}
			/* Check draw after last move by player */
			if(i == (MAX_ROUNDS - 1)){
				drawmsg();
				break;
			}
			if(players == 2){
				setcoord(getmove(PLAYER2, playicons.PLAYER2ICON), PLAYER2);
				printmatrix();
			}else{
				setcoord(getcomputermove(COMPUTER, PLAYER1), COMPUTER);
				printmatrix();
			}
			if(iswinner(PLAYER2)){
				winner = PLAYER2;
				winnermsg(PLAYER2, playicons.PLAYER2ICON);
				break;
			}
		}else{
			/* Get moves in reverse order */
			if(players == 2){
				setcoord(getmove(PLAYER2, playicons.PLAYER2ICON), PLAYER2);
				printmatrix();
			}else{
				setcoord(getcomputermove(COMPUTER, PLAYER1), COMPUTER);
				printmatrix();
			}
			if(iswinner(PLAYER2)){
				winner = PLAYER2;
				winnermsg(PLAYER2, playicons.PLAYER2ICON);
				break;
			}
			/* Check draw after last move by player */
			if(i == (MAX_ROUNDS - 1)){
				drawmsg();
				break;
			}
			setcoord(getmove(PLAYER1, playicons.PLAYER1ICON), PLAYER1);
			printmatrix();
			if(iswinner(PLAYER1)){
				winner = PLAYER1;
				winnermsg(PLAYER1, playicons.PLAYER1ICON);
				break;
			}
		}
	}
	return winner;
}

/* Obtain a random or 'smart' computer move */
struct coord getcomputermove(int asplayer, int opponent){
	struct coord cpucoord;
	srand(time(NULL));
	int x = 0;
	int y = 0;
	
	/* Determine available slots for CPU move */
	for(int i = 0; i < MAX_MATRIX_ELEMENTS; i++){
		for(int j = 0; j < MAX_MATRIX_ELEMENTS; j++){
			if(matrix[i][j] == NO_MOVES){
				x = i;
				y = j;
			}
		}
	}
	
	if(DEBUG){
		printf("in getcomputermove() => slot x => %i, slot y => %i\n", x, y);
	}
	
	/* If an 'open slot' is found we are able to fill it with a CPU move.
	 * Sanity-check to ensure the slot chosen is not already used.  
	 * Our CPU acts with some intelligence by checking if the opponent will
	 * 'win' on their next move, if so the opponent's win slot' is filled.
	 * Our CPU can override it's own coordinates if it knows it can win on it's
	 * next move.
	 */
	if(iswinpossible(opponent)){
		cpucoord = preventwin(opponent);
	}else{
		do{
			cpucoord.x = rand() % (x + 1);
			cpucoord.y = rand() % (y + 1);
			if(DEBUG){
				printf("in getcomputermove() fetched random x, y coordinates\n");
			}
			/* TODO: test while() code below thoroughly */
		}while(matrix[cpucoord.x][cpucoord.y] != NO_MOVES || cpucoord.x > MAX_COORDS_RANGE || cpucoord.y > MAX_COORDS_RANGE || cpucoord.x <= NO_MOVES || cpucoord.y <= NO_MOVES);
	}
	/* AI win if it can */
	if(iswinpossible(asplayer)){
		cpucoord = preventwin(asplayer);
	}
	
	if(DEBUG){
		printf("in getcomputermove() => cpucoord.x => %i, cpucoord.y => %i\n", cpucoord.x, cpucoord.y);
	}
	/* If all is well, return the coordinates */
	return cpucoord;
}

/* Set the number of players for the game 
 * Always assume 1 player unless players set is 2
 */
void setplayers(){
	playersmsg();
	char numplayers[MAX_CHARS];
	xgets(numplayers, MAX_CHARS);
	if(DEBUG){
		printf("in setplayers() => numplayers => %s, numplayers[0] => %i\n", numplayers, xatoi(numplayers[0]));
	}
	if(toupper(numplayers[0]) == 'S'){
		players = -1;
		return;
	}
	players = xatoi(numplayers[0]);
	if(DEBUG){
		printf("in setplayers() => int players => %i\n", players);
	}
	if(players != 2 && players != 1 && players != -1){
		players = 1;
		defaulterrormsg("1 player");
	}
}

/* Set a custom icon for each player, if none specified 
 * internal defaults 'O' and 'X' are used
 */
void setcustomicon(){
	char customicon[MAX_CHARS];
	if(players == 1){
		do{
			customiconmsg(PLAYER1);
			xgets(customicon, MAX_CHARS);
			if(DEBUG){
				printf("in customicon() => customicon => %s, customicon[0] => %c\n", customicon, customicon[0]);
			}
			if(customicon[0] != '\0'){
				playicons.PLAYER1ICON = toupper(customicon[0]);
			}else{
				defaulterrormsg("icon!!");
			}
		}while(isiconused());
	}else{
		for(int i = 0; i < players; i++){
			do{
				customiconmsg((i));
				xgets(customicon, MAX_CHARS);
				if(DEBUG){
					printf("in customicon() => customicon => %s, customicon[0] => %c\n", customicon, customicon[0]);
				}
				if(customicon[0] == '\0'){
					defaulterrormsg("icon!!");
					continue;
				}
				switch(i){
					case 0:
						playicons.PLAYER1ICON = toupper(customicon[0]);
						break;
					case 1:
						playicons.PLAYER2ICON = toupper(customicon[0]);
						break;
				}
			}while(isiconused());
		}
	}
}

/* invert the order of play */
void invertorder(){
	if(moveorder == 1){
		moveorder = -1;
	}else if(moveorder == -1){
		moveorder = 1;
	}
}

/* Set the move-order for the game - Always assume sequential order (1)
 * If 2 (-1) order is reversed (player 2 moves first)
 */
void setmoveorder(){
	/* Handle simulation */
	if(players == -1){
		return;
	}
	
	moveordermsg();
	char smoveorder[MAX_CHARS];
	xgets(smoveorder, MAX_CHARS);
	if(DEBUG){
		printf("in setmoveorder() => string movorder => %s\n", smoveorder);
	}
	moveorder = xatoi(smoveorder[0]);
	switch(moveorder){
		case 1:
			moveorder = 1;		/* sequential order */
			break;
		case 2:
			moveorder = -1;		/* reverse order */
			break;
		default:
			moveorder = 1;
			defaulterrormsg("player 1");
			break;
	}
	if(DEBUG){
		printf("in setmoveorder() => set moveorder => %i\n", moveorder);
	}
}

int playagain(){
	int replay = 0;
	playagainmsg();
	char playagain[MAX_CHARS];
	xgets(playagain, MAX_CHARS);
	if(DEBUG){
		printf("in playagain() => playagain => %s\n", playagain);
	}
	if(tolower(playagain[0]) == 'y'){
		replay = 1;
	}
	return replay;
}

/* Simulation play capability */
int simmplay(){
	/* Statistics - 2 = draw */
	int winner = 2;
	
	simmplaymsg();
	for(int i = 0; i < MAX_ROUNDS; i++){
		if(DEBUG){
			printf("in simulation() => round => %i\n", i);
		}
		/* Sequential */
		if(moveorder == 1){
			setcoord(getcomputermove(PLAYER1, COMPUTER), PLAYER1);
			printmatrix();
			if(iswinner(PLAYER1)){
				winner = PLAYER1;
				winnermsg(PLAYER1, playicons.PLAYER1ICON);
				break;
			}
			/* Check draw after last move by player */
			if(i == (MAX_ROUNDS - 1)){
				drawmsg();
				break;
			}
			setcoord(getcomputermove(COMPUTER, PLAYER1), COMPUTER);
			printmatrix();
			if(iswinner(PLAYER2)){
				winner = PLAYER2;
				winnermsg(PLAYER2, playicons.PLAYER2ICON);
				break;
			}
		}else{
			/* Reversed */
			setcoord(getcomputermove(COMPUTER, PLAYER1), COMPUTER);
			printmatrix();
			if(iswinner(PLAYER2)){
				winner = PLAYER2;
				winnermsg(PLAYER2, playicons.PLAYER2ICON);
				break;
			}
			/* Check draw after last move by player */
			if(i == (MAX_ROUNDS - 1)){
				drawmsg();
				break;
			}
			setcoord(getcomputermove(PLAYER1, COMPUTER), PLAYER1);
			printmatrix();
			if(iswinner(PLAYER1)){
				winner = PLAYER1;
				winnermsg(PLAYER1, playicons.PLAYER1ICON);
				break;
			}
		}
	}
	return winner;
}

#endif	/* GAME_H */
