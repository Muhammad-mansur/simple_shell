#include "main.h"

/**
 * read_cmd - A function that reads the user input from standard input
 *
 * @line: input
 * @len: input
 *
 * Return: line
 */

ssize_t read_cmd(char **line, size_t *len)
{
	ssize_t readt = 0;

	if (isatty(STDIN_FILENO))
	{
		write(1, "($) ", 4);
	}
	readt = getline(line, len, stdin);
	if (readt == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			return (-1);
		}
		free(line);
		exit(EXIT_FAILURE);
	}
	return (readt);
}
/**
 * tokenize - Divides a command line into separate arguments.
 * @line: input
 * @arg: input
 * Return: no of arguments
 */

int tokenize(char *line, char **arg)
{
	int i;
	char *tock;

	for (tock = strtok(line, " \t\n\"\'\\#&*`"), i = 0; tock != NULL;
		 tock = strtok(NULL, " \t\n\"\'\\#&*`"), i++)
	{
		arg[i] = tock;
	}
	arg[i] = NULL;
	return (i);
}
