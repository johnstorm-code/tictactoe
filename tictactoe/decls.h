/* 
 * File:   decls.h
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
 * Created on April 26, 2012, 11:39 PM
 */

#ifndef DECLS_H
#define	DECLS_H

/* AI.h */
int iswinpossible(int player);				/* Checks for possibility player will win */
struct coord preventwin(int player);	/* Prevents player from winning with ret coordinates */
int iswinner(int player);					/* Checks for winner */

/* Rules.h */
int iscoordoutrange(struct coord cmover);	/* Checks if coordinates are out of range */
int ismoveset(struct coord cmove);			/* Checks if matrix grid already has a value set */
int isproperformat(char *coordinate);		/* Basic validation of format of coordinates - must be separated by space */
int isiconused();							/* Checks if custom icon is already in-use */

/* Game.h */
void setcoord(struct coord c, int player);	/* Sets player coordinates */
struct coord getmove(int player, char playvalue);	/* Gets coordinates for matrix grid */
int play();								/* Play the game return winner */
struct coord getcomputermove(int asplayer, int opponent);	/* Gets computer coordinates */
void setplayers();									/* Sets the number of players */
void setcustomicon();						/* Set the custom icons for each player */
void setmoveorder();						/* Set the move-order for players */
int playagain();							/* Allows the game to be played again */
int simmplay();								/* Simulation play returns winner */
void invertorder();						/* Inverts the order of play */

/* Matrix.h */
void printmatrix();									/* Prints the matrix */

/* Messages.h */
void improperformatmsg(char *input);			/* Display improper format message */
void headermsg();								/* Display welcome to TTT message */
void playersmsg();							/* Display number of players message */
void winnermsg(int player, char icon);			/* Display winner message */
void drawmsg();								/* Display 'draw' message */
void doneplaymsg();							/* Display done playing message */
void playagainmsg();						/* Display play again message */
void invalidmovemsg();							/* Display invalid move message */
void cooroutrangemsg(coord coor);						/* Display coordinates out of range message */
void moveordermsg();						/* Display move order message */
void defaulterrormsg(const char *msg);			/* Display generic error message */
void customiconmsg(int player);				/* Display custom icon message */
void iconusedmsg();							/* Display icon used message */
void simmplaymsg();						/* Display game-in-simulation mode */
void GPL(char *program, char *year, char *author);	/* General Public License */

/* XFuncs.h */
int xatoi(char c);							/* Hard-conversion of char c to int */
char *xgets(char *s, int length);			/* Safe gets() function */
struct coord blocktocoord(int block);	/* Converts block numbers to x, y coordinates */
size_t xstrlen(const char *s);				/* Returns char count of string */

/* System.h */
void initmatrix();							/* Initializes the matrix */
void initicons();							/* Initialize the player icons */
void init();								/* Initialize all */
void initcoord();					/* Initialize coordinates */

/* Stats */
void recordwinner(int winner);			/* Record each winner */
void printstats();					/* print winner statistics */

#endif	/* DECLS_H */
