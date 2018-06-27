#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

int ignore_comment(char a,char b)
{

	if(a == '#' && b != '#')
	{
		return 0;
	}
	return (1);
}

int			main(void)
{

	ft_printf("hello world!!!\n");

	//number = get_the_ant_number();
	//number=0;
	ft_printf("\nGet the number %d \n",  get_the_ant_number());


	get_the_rooms();
return(0);
}
