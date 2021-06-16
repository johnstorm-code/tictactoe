/* 
 * File:   xfuncs.h
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
 * Created on April 26, 2012, 11:24 AM
 */

#ifndef XFUNCS_H
#define	XFUNCS_H

/* Hard-convert c to integer - Assumes '0' - '9' */
int xatoi(char c){
	if('0' <= c && c <= '9'){
		if(DEBUG){
			printf("in xatoi() => c => %c => int => %i\n", c, (c - 48));
		}
		return (c - 48);
	}else{
		return c;
	}
}

/* Safe gets() function */
char *xgets(char *s, int length){
	int i = 0;
	for(; i < length - 1; i++){
		s[i] = getchar();
		if(DEBUG){
			if(s[i] == '\n'){
				printf("in xgets() => s[%i] => '\\n'\n", i);
			}else{
				printf("in xgets() => s[%i] => %c\n", i, s[i]);
			}
		}
		/* Blank - no input */
		if(s[i] == '\n'){
			s[i] = '\0';
			return s;
		}
	}
	s[i] = '\0';
	
	/* Flush stdin */
	char c = getchar();
	for(; c != '\n'; c = getchar()){
		if(DEBUG){
			printf("in xgets() => flushing => %c\n", c);
		}
	}
	if(DEBUG){
		printf("in xgets() => s => %s\n", s);
	}
	
	return s;
}

/* Translate block number to coordinates */
struct coord blocktocoord(int block){
	coord ret;
	switch(block){
		case 1:
			ret.x = 0;
			ret.y = 0;
			break;
		case 2:
			ret.x = 0;
			ret.y = 1;
			break;
		case 3:
			ret.x = 0;
			ret.y = 2;
			break;
		case 4:
			ret.x = 1;
			ret.y = 0;
			break;
		case 5:
			ret.x = 1;
			ret.y = 1;
			break;
		case 6:
			ret.x = 1;
			ret.y = 2;
			break;
		case 7:
			ret.x = 2;
			ret.y = 0;
			break;
		case 8:
			ret.x = 2;
			ret.y = 1;
			break;
		case 9:
			ret.x = 2;
			ret.y = 2;
			break;
	}
	return ret;
}

/* count number of chars in s */
size_t xstrlen(const char *s){
	int i = 0;
	while(*s != '\0'){
		i++;
		s++;
	}
	return i;
}

#endif	/* XFUNCS_H */
