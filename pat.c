#include "main.h"

/** determines if a file is an executable command  */
int is_cmd(info_t *info, char *path)
{
		struct stat st;

			(void)info;
				if (!path || stat(path, &st))
							return (0);

					if (st.st_mode & S_IFREG)
							{
										return (1);
											}
						return (0);
}

/*duplicates characters */
char *dup_chars(char *pathstr, int start, int stop)
{
		static char buff[1024];
		int j = 0, k = 0;
				for (k = 0, j = start; i < stop; j++)
							if (pathstr[j] != ':')
											buff[k++] = pathstr[j];
					buff[k] = 0;
						return (buff);
}

/*finds this cmd in the PATH string */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int v = 0, cur_pos = 0;
			char *path;

				if (!pathstr)
							return (NULL);
					if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
							{
										if (is_cmd(info, cmd))
														return (cmd);
											}
						while (1)
								{
											if (!pathstr[v] || pathstr[v] == ':')
														{
	path = dup_chars(pathstr, cur_pos, v);
																					if (!*path)
																										_strcat(path, cmd);
																								else
																												{
																												_strcat(path, "/");
																																			_strcat(path, cmd);
																																								}
																						if (is_cmd(info, path))
																											return (path);
						if (!pathstr[v])
																																			break;
							cur_pos = v;
											}
								v++;
														}
							return (NULL);
}


