/* 
 * File:   msgs.h
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
 * Created on April 26, 2012, 11:19 AM
 */

#ifndef MSGS_H
#define	MSGS_H

void customiconmsg(int player){
	printf("\nPlayer %i select a custom icon: ", (player+1));
}

void defaulterrormsg(const char *msg){
	printf("\nUsing default %s!!\n", msg);
}

void headermsg(){
	printf("\nWelcome to tic-tac-toe!!\n");
}

void improperformatmsg(char *input){
	printf("\nMove structure %s invalid!!\n", input);
}

void playersmsg(){
	printf("\nPlease specify the number of players? (S=simulation) ");
}

void winnermsg(int player, char icon){
	printf("\nPlayer %i (%c) wins!!!\n", (player+1), icon);
}

void drawmsg(){
	printf("\nIt's a draw!!\n");
}

void doneplaymsg(){
	printf("\nThanks for playing tic-tac-toe!!\n");
}

void playagainmsg(){
	printf("\nPlay again? (gameplay will be reversed) ");
}

void invalidmovemsg(){
	printf("\nInvalid move!!\n");
}

void cooroutrangemsg(coord coor){
	printf("\nMove x, y out of range %i, %i!!\n", coor.x + 1, coor.y + 1);
}

void moveordermsg(){
	printf("\nWhich player should go first? ");
}

void iconusedmsg(){
	printf("\nIcon already in use!!\n");
}

void simmplaymsg(){
	printf("\nIn Simulation mode!!\n");
}

void GPL(const char *program, const char *year, const char *author){
	printf("\n%s Copyright (C) %s %s\n", program, year, author);
	printf("This program comes with ABSOLUTELY NO WARRANTY.\n");
	printf("This is free software, and you are welcome to \n");
	printf("redistribute it under certain conditions.\n");
}

#endif	/* MSGS_H */
