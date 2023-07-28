#include "main.h"

/*exits the shell */
int _meexit(info_t *info)
{
	int exitcheck;
	if (info->argv[1]) 
					{
					exitcheck = _erratoi(info->argv[1]);
					if (exitcheck == -1)
					{
								info->status = 2;
																				print_error(info, "Illegal number: ");
			_erputs(info->argv[1]);
				_erputchar('\n');
																							return (1);
																							}
						info->err_num = _erratoi(info->argv[1]);
								return (-2);
															}
				info->err_num = -1;
					return (-2);
}

/* changes the current directory of the process  */
int _mecd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

		s = getcwd(buffer, 1024);
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
		_erputs(info->argv[1]), _eputchar('\n');
																	}
							else
							{
						_setenv(info, "OLDPWD", _getenv(info, "PWD="));
								_setenv(info, "PWD", getcwd(buffer, 1024));
												}
											return (0);
}

/*changes the current directory of the process  */
int _mehelp(info_t *info)
{
		char **arg_array;
		arg_array = info->argv;
			_puts("help call works. Function not yet implemented \n");
			if (0)
			_puts(*arg_array); /* temp att_unused workaround */
				return (0);
}


