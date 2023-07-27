#include "main.h"

/* converts a string to an integer *     *       -1 on error
 *      */
int _erratoi(char *s)
{
	int v = 0;
	unsigned long int res = 0;

				if (*s == '+')
							s++;  /* TODO: why does this make main return 255? */
				for (v = 0;  s[v] != '\0'; v++)
							{
										if (s[v] >= '0' && s[v] <= '9')
													{
									res *= 10;
					res += (s[v] - '0');
							if (res > INT_MAX)
																												return (-1);
																									}
												else
																return (-1);
													}
						return (res);
}

/* prints an error message */
void print_error(info_t *info, char *estr)
{
		_puts(info->fname);
			_puts(": ");
				print_d(info->line_count, STDERR_FILENO);
					_puts(": ");
						_puts(info->argv[0]);
							_puts(": ");
								_puts(estr);
}

/* print_d - function prints a decimal (integer)  */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
		int i, count = 0;
			unsigned int _abs_, current;

					if (fd == STDERR_FILENO)
								__putchar = _putchar;
						if (input < 0)
								{
											_abs_ = -input;
													__putchar('-');
															count++;
																}
							else
										_abs_ = input;
								current = _abs_;
									for (i = 1000000000; i > 1; i /= 10)
											{
														if (_abs_ / i)
																	{
																					__putchar('0' + current / i);
																								count++;
																										}
																current %= i;
																	}
										__putchar('0' + current);
											count++;

												return (count);
}

/* converter function, a clone of itoa   */
char *convert_number(long int num, int base, int flags)
{
		static char *arr;
			static char buff[50];
				char sign = 0;
					char *ptr;
						unsigned long n = num;

							if (!(flags & CONVERT_UNSIGNED) && num < 0)
									{
												n = -num;
														sign = '-';

															}
								arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
									ptr = &buff[49];
										*ptr = '\0';

											do	{
											*--ptr = arr[n % base];
													n /= base;
															} while (n != 0);

												if (sign)
													*--ptr = sign;
												return (ptr);
}

/* function replaces first instance of '#' with '\0'*/
void remove_comments(char *buf)
{
		int j;

			for (j = 0; buf[j] != '\0'; j++)
						if (buf[j] == '#' && (!i || buf[j - 1] == ' '))
									{
													buf[j] = '\0';
																break;
																		}
}

