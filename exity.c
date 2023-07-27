#include"main.h"

/*- exits */
int _exit(info_t *info)
{
	int exitchk;

	if (info->argv[1]) 
				{
			exitchk = _erratoi(info->argv[1]);
					if (exitchk == -1)
													{
																	info->status = 2;
			print_err(info, "Illegal number: ");
			_puts(info->argv[1]);
			_putchar('\n');
																								return (1);
																													}
			info->err_num = _erratoi(info->argv[1]);
														return (-2);
															}
				info->err_num = -1;
					return (-2);
}

/* changes  directory */
int _cd(info_t *info)
{
char *g, *dir, buff[1024];
int chdir_ret;

g = getcwd(buff, 1024);
if (!s)
	_puts("TODO: >>getcwd failure emsg here<<\n");
						if (!info->argv[1])
							{
											dir = _getenv(info, "HOME=");
													if (!dir)
	chdir_ret = /* TODO: what should this be? */
																	chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
															else
		chdir_ret = chdir(dir);
																}
							else if (_strcmp(info->argv[1], "-") == 0)
									{
												if (!_getenv(info, "OLDPWD="))
															{
																			_puts(s);
																						_putchar('\n');
																									return (1);
																											}
														_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
																chdir_ret = /* TODO: what should this be? */
																				chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
																	}
								else
											chdir_ret = chdir(info->argv[1]);
									if (chdir_ret == -1)
											{
														print_error(info, "can't cd to ");
				_puts(info->argv[1]), _putchar('\n');
																	}
										else
												{
															_setenv(info, "OLDPWD", _getenv(info, "PWD="));
																	_setenv(info, "PWD", getcwd(buffer, 1024));
																		}
											return (0);
}

/*changes directory*/
int _help(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
		_puts("help call works. Function not yet implemented \n");
		if (0)
			_puts(*arg_array); 
			return (0);
}


