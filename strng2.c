#include "main.h"

/* copies a string  */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

		if (dest == src || src == 0)
				return (dest);
		while (src[j])
					{
					dest[j] = src[j];
							j++;
												}
					dest[j] = 0;
						return (dest);
}

/*duplicates a string */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
			return (NULL);
	while (*str++)
			length++;
			ret = malloc(sizeof(char) * (length + 1));
				if (!ret)
							return (NULL);
				for (length++; length--;)
			ret[length] = *--str;
									return (ret);
}

/* prints an input string */
void _puts(char *str)
{
	int j = 0;

	if (!str)
				return;
				while (str[j] != '\0')
						{
						_putchar(str[j]);
											j++;
												}
}

/*writes the character c to stdout */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

		if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
			{
									write(1, buf, i);
											i = 0;
												}
					if (c != BUF_FLUSH)
								buf[i++] = c;
						return (1);
}


