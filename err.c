#include"main.h"
/*  prints an error message */
void print_error(info_t *info, char *estr)
{
		_eputs(info->fname);
			_eputs(": ");
				print_d(info->line_count, STDERR_FILENO);
					_eputs(": ");
						_eputs(info->argv[0]);
							_eputs(": ");
								_eputs(estr);
}


/* remove_comments */
void remove_comments(char *buf)
{
		int h;

			for (h = 0; buf[h] != '\0'; h++)
						if (buf[h] == '#' && (!h || buf[h - 1] == ' '))
									{
													buf[h] = '\0';
																break;
																		}
}
