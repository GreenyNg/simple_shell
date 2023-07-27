#include "main.h"

/* input string  */
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

/* writes the character c to stderr  */
int _putchar(char c)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
						{
							write(2, buf, v);
											v = 0;
												}
					if (c != BUF_FLUSH)
								buf[v++] = c;
						return (1);
}

/* writes the character c to given */
int _putfd(char c, int fd)
{
		static int i;
			static char buf[WRITE_BUF_SIZE];

				if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
						{
									write(fd, buf, i);
											i = 0;
												}
					if (c != BUF_FLUSH)
								buf[i++] = c;
						return (1);
}

/*
 * _putsfd - prints an input string
  */
int _putsfd(char *str, int fd)
{
		int i = 0;

			if (!str)
						return (0);
				while (*str)
						{
									i += _putfd(*str++, fd);
										}
					return (i);
}


