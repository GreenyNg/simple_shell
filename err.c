#include "main.h"

/* prints an input string */
void _erputs(char *str)
{
	int j = 0;

			if (!str)
						return;
		while (str[j] != '\0')
				{
						_erputchar(str[j]);
											j++;
												}
}

/*writes the character c to stderr */
int _erputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
				{
					write(2, buf, i);
						i = 0;
										}
				if (c != BUF_FLUSH)
						buf[i++] = c;
			return (1);
}

/*rites the character c to given fd  */
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

/* prints an input string */
int _putsfd(char *str, int fd)
{
		int j = 0;

			if (!str)
						return (0);
				while (*str)
						{
									j += _putfd(*str++, fd);
										}
					return (j);
}


