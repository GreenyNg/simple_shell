#include"main.h"

/*is the shell interactive*/
int _at(char *m)
{
	int i, sign = 1, flg = 0, out;
	unsigned int res = 0;

			for (i = 0; m[i] != '\0' && flg != 2; i++)
						{
							if (m[i] == '-')
						sign *= -1;
				if (s[i] >= '0' && m[i] <= '9')
														{
				flg = 1;
				res *= 10;
				res += (m[i] - '0');
																								}
				else if (flg == 1)
					flg = 2;
													}
					if (sign == -1)
		out = -res;
					else
			out = res;

				return (out);
}

