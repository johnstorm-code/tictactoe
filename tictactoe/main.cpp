/* 
 * File:   main.cpp
 *
 * Tic-tac-toe game
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
 * Created on April 25, 2012, 2:17 PM
 */

#define DEBUG 0		/* Debug on = 1, off = 0 */

#include <stdio.h> /* printf, etc, ... */
#include <stdlib.h> /* srand, exit, ... */
#include <time.h> /* seed rand, etc, ... */
#include <ctype.h> /* tolower, etc, ... */

#include "defs.h"
#include "data.h"
#include "decls.h"
#include "msgs.h"
#include "ai.h"
#include "matrix.h"
#include "game.h"
#include "xfuncs.h"
#include "system.h"
#include "rules.h"
#include "stats.h"

/*
 * Play the tic-tac-toe game
 */
int main(void) {
		
	/* Display GPL (license) */
	GPL("Tic-tac-toe Game", "2012", "jstorm");
	
	/* init */
	init();
		
	/* messages */
	headermsg();
		
	/* number of players */
	setplayers();
		
	/* Set move order */
	setmoveorder();
		
	/* Set custom icons */
	setcustomicon();
	
	/* Play */
	do{
		recordwinner(play());
		invertorder();
		initmatrix();
		initcoord();
		
	}while(playagain());
	
	/* Stats */
	printstats();
	
	/* exit messages */
	doneplaymsg();
	
	return 0;
}
