#include "push_swap.h"

parse_do_op()
{

}

print_output()
{

}

int main()
{
    char    *line;

    line = get_next_line(STDIN_FILENO);
    while(line)
    {
		free(line);
        line = get_next_line(STDIN_FILENO);
        if (!line)
            return(print_output(), 0);
		print_output();
        parse_do_op(); //should parse within gnl.
    }
	free(line);
}
