#include "main.h"

/*ashell begins*/

int main(int argc, char *argv[], char *envp[])
{
	char *lptr = NULL, *pathcmd = NULL, *path = NULL;
	size_t buffer_size = 0;
	ssize_t num_read = 0;
	char **cmd = NULL, **paths = NULL;
	(void) envp, (void) argv;
	if (argc < 1)
		return (-1);
	signal(SIGINT, handle_sig);
	while (1)
		{
			free_cmds(cmd);
				free_cmds(paths);
		free(pathcmd);
		prompt();
		num_read = getline(&lineptr, &buffer_size, stdin);
	if (num_chars_read < 0)
		break;
		info.ln_count++;
		if (lptr[num_read - 1] == '\n')
			lineptr[num_read - 1]  = '\0';
		cmd = put_token(lptr);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (cmd_type(cmd, lptr))
				continue;
	path = _getpath();
	paths = Put_token(path);
	pathcmd = search_path(paths, cmd[0]);
																		if (pathcmd == NULL)
			perror(argv[0]);
																		else
																			exec_cmd(pathcmd, cmd);
																																	}
			if (num_read < 0 && flags.interactive)
										write(STDERR_FILENO, "\n", 1);
									free(lptr);
												return (0);
}


/* prompt*/
void prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
			flags.interactive = 1;
	if (flags.interactive)
						write(STDERR_FILENO, "$ ", 2);
}

/* handle_sig */
void handle_sig(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}


/*Checks the command*/
int cmd_type(char **cmd, char *b)
{
		if (is_builtin(cmd, b))
				{
							return (1);
								}
			else if (**cmd == '/')
					{
								exec_cmd(cmd[0], cmd);
										return (1);
											}
				return (0);
}
