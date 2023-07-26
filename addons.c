#include "main.h"

/* exec_cmd - This program creates a new child process */

void exec_cmd(char *c, char **cmd)
{
	pid_t newProcess;
	int stat;
	char **envp = env;

	newProcess = fork();
	if (newProcess < 0)
		perror(c);
	if (newProcess == 0)
		{
			execve(c, cmd, envp);
				perror(c);
					free(c);
						free_cmds(cmd);
							exit(98);
			}
	else
		{
			wait(&stat);
		}
}

/*tokenize*/

char **Put_token(char *str)
{
	size_t ind = 0, z = 0;
	int tkn = 1;
	char **tokens = NULL;
	char *buf = NULL, *token = NULL, *bufptr = NULL, *delim = " :\t\r\n";

	buf = duplicate_str(str);
	if (buf == NULL)
		return (NULL);
	bufptr = buf;
	while (*bufptr)
		{
			if (check_str(delim, *bufptr) != NULL && io == 0)
				{
					tkn++;
	z = 1;
																										}
			else if (check_str(delim, *bufptr) == NULL && z == 1)
					z = 0;
					bufptr++;
		}
		tokens = malloc(sizeof(char *) * (tkn + 1));
		token = strtok(buf, delim);
		while (token)
			{
				tokens[ind] = duplicate_str(token);
					if (tokens[ind] == NULL)
						{
							free(tokens);
								return (NULL);
						}
		token = strtok(NULL, delim);
			ind++;
			}
		tokens[ind] = NULL;
			free(buf);
		return (tokens);
}


