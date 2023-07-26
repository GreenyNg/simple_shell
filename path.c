#include "main.h"

/*finds and return the PATH*/

char *_getpath(void)
{
	int i = 0;
	char **env = environ;
	char *pth = NULL;

	while (*env)
		{
		if (_strncmp(*env, "PATH=", 5) == 0)
									{
			pth = *env;
	while (*pth && i < 5)
			{
				pth++;
																																	i++;
																																				}
		return (pth);
																									}
					env++;
													}
						return (NULL);
}


/* search for PATH  */

char *sch_path(char **p, char *cmd)
{
	int i = 0;
	char *des;

	while (p[i])
		{
			des = app_path(p[i], cmd);
											if (access(des, F_OK | X_OK) == 0)
														{
			return (des);
																				}
													else
		free(des);
															i++;
																}
					return (NULL);
}


/* concatenates path */

char *app_path(char *path, char *cmd)
{
	char *buf;
	size_t a = 0, b = 0;

	if (cmd == 0)
		cmd = "";
	if (path == 0)
								path = "";
		buf = malloc(sizeof(char) * _strlen(path) + _strlen(cmd) + 2);
							if (buffer == NULL)
										return (NULL);
								while (path[a])
										{
				buf[a] = path[a];
															a++;
																}
									if (path[a - 1] != '/')
											{
					buf[a] = '/';
																a++;
																	}
						while (cmd[b])
							{
						buf[a + b] = cmd[b];
																	b++;
																		}
						buf[a + b] = '\0';

												return (buf);
}
