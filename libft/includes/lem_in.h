#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

typedef struct  	s_room
{
	char		*name;
	int 	ord;
	int			x;
	int			y;
	int 		ispassed;
	int 		setlink;
	char		type;
	struct  s_room *array_of_rooms;
	struct  s_room *next;
	struct  s_room *back;
} s_room;

typedef struct  	s_link
{
	char		*name_s;
	char		*name_d;
} s_link;
int number_of_rooms;
int number_of_links;



int   get_the_ant_number();
int   is_comment(char *c);
int   is_comment_room(char *c);
int   check_patern(char *str);
char   check_patern_room(char *str);
void   get_the_rooms();
int   check_patern_links(char *str);
int   get_len(char **str);
int   all_digits(char *str);
char  is_command(char *s);
void set_the_links(s_room *rooms, s_link *links);


# endif
