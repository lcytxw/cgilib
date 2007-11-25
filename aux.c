/*
    aux.c - Auxilliary code for CGI library
    Copyright (C) 2007 by Martin Schulze <joey@infodrom.org>
     
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software 
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <stdlib.h>
#include <string.h>

char *cgiEscape (char *string)
{
    char *cp, *np;
    char *buf;
    size_t len;

    for (cp=string, len=0; *cp; cp++) {
	switch (*cp) {
	case '&':
	    len+=5;
	    break;
	case '<':
	case '>':
	    len+=4;
	    break;
	default:
	    len++;
	    break;
	}
    }

    if (len == strlen(string))
	return strdup(string);

    if ((buf = (char *)malloc(len+1)) == NULL)
	return NULL;

    for (cp=string, np=buf; *cp; cp++) {
	switch (*cp) {
	case '&':
	    *np++ = '&';
	    *np++ = 'a';
	    *np++ = 'm';
	    *np++ = 'p';
	    *np++ = ';';
	    break;
	case '<':
	    *np++ = '&';
	    *np++ = 'l';
	    *np++ = 't';
	    *np++ = ';';
	    break;
	case '>':
	    *np++ = '&';
	    *np++ = 'g';
	    *np++ = 't';
	    *np++ = ';';
	    break;
	default:
	    *np++ = *cp;
	    break;
	}
    }
    *np = '\0';

    return buf;
}

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  tab-width: 8
 * End:
 */
