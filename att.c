#include "main.h"

/* returns true if shell is interactive mode  */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/* checks if character is a delimeter  */
int is_delim(char c, char *delim)
{
		while (*delim)
					if (*delim++ == c)
									return (1);
			return (0);
}

/* checks for alphabetic character*/

int _isalpha(int c)
{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
			else
						return (0);
}

/* converts a string to an integer */

int _atoi(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;
		for (j = 0; s[j] != '\0' && flag != 2; j++)
						{
							if (s[j] == '-')
									sign *= -1;
							if (s[j] >= '0' && s[j] <= '9')
														{
																		flag = 1;
																					result *= 10;
									result += (s[j] - '0');
																										}
										else if (flag == 1)
										flag = 2;
											}

					if (sign == -1)
				output = -result;
						else
						output = result;
							return (output);
}


