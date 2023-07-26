#include "main.h"

/* Compares two strings*/

int _strcmp(char *s1, char *s2)
{
	int run;

	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && *s2)
		{
			run = *s1 - *s2;
				if (run != 0)
					break;
						s1++;
						s2++;
		}
					return (run);

}


/* duplicate string */

char *duplicate_str(char *str)
{
	char *b;
	int i, len;

	if (str == NULL)
		{
			return (NULL);
		}

	len = _strlen(str);

		b = malloc(sizeof(char) * (len + 1));
			if (b == NULL)
				{
					return (NULL);
				}
			for (i = 0; *str != '\0'; str++, i++)
				{
					b[i] = str[0];
												}
						b[i++] = '\0';

										return (p);
}

/*compare strings*/
int _strncmp(const char *f, const char *s, int n)
{
		int il;

		for (il = 0; f[il] && s[il] && il < n; il++)
			{
				if (f[il] != s[il])
						return (f[il] - s[il]);
									}
				return (0);
}


/*length of a strin*/

int _strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;
		return (i);
}


/*searches a string */

char *check_str(char *str, int chrs)
{
	while (*str)
		{
			if (*str == chrs)
					return (str);
						str++;
										}
			return (NULL);
}
