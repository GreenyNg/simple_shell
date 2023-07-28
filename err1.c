#include "main.h"

/* converts a string to an integer  *       -1 on error
 *      */
int _erratoi(char *s)
{
	int j = 0;
	unsigned long int result = 0;

		if (*s == '+')
				s++;  /* TODO: why does this make main return 255? */
		for (j = 0;  s[j] != '\0'; j++)
						{
					if (s[j] >= '0' && s[j] <= '9')
													{
												result *= 10;
						result += (s[j] - '0');
																							if (result > INT_MAX)
																												return (-1);
																					}
												else
													return (-1);
											}
						return (result);
}

/*prints an error message   */
void print_error(info_t *info, char *estr)
{
		_erputs(info->fname);
			_erputs(": ");
				print_d(info->line_count, STDERR_FILENO);
					_erputs(": ");
						_erputs(info->argv[0]);
							_erputs(": ");
								_erputs(estr);
}

/*function prints a decimal (integer) number   */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int _abs_, current;
		if (fd == STDERR_FILENO)
				__putchar = _erputchar;
						if (input < 0)
								{
									_abs_ = -input;
						__putchar('-');
								count++;
													}
					else
							_abs_ = input;
						current = _abs_;
						for (j = 1000000000; j > 1; j /= 10)
											{
									if (_abs_ / i)
																	{
								__putchar('0' + current / j);
												count++;
																				}
											current %= j;
															}
										__putchar('0' + current);
											count++;

										return (count);
}

/* converter function */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
		static char buffer[50];
		char sign = 0;
			char *ptr;
			unsigned long n = num;
				if (!(flags & CONVERT_UNSIGNED) && num < 0)
									{
								n = -num;
					sign = '-';
													}
			array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
						ptr = &buffer[49];
							*ptr = '\0';
								do	{
				*--ptr = array[n % base];
								n /= base;
								} while (n != 0);
					if (sign)
					*--ptr = sign;
						return (ptr);
}

/*function replaces first instance of '#' with '\0' */
void remove_comments(char *buf)
{
		int j;

			for (j = 0; buf[j] != '\0'; j++)
						if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
									{
											buf[j] = '\0';
												break;
												}
}
