#include "main..h"

/* fills memory with a constant byte */
char *_memset(char *s, char b, unsigned int n)
{
		unsigned int j;

			for (j = 0; j < n; j++)
						s[j] = b;
				return (s);
}

/* frees a string of strings*/
void fffree(char **pp)
{
	char **a = pp;

			if (!pp)
						return;
				while (*pp)
							free(*pp++);
					free(a);
}

/*reallocates a block of memory */
void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s)
{
		char *f;

			if (!ptr)
						return (malloc(new_s));
				if (!new_s)
							return (free(ptr), NULL);
					if (new_s == old_s)
								return (ptr);

						f = malloc(new_s);
							if (!f)
										return (NULL);

								old_s = old_s < new_s ? old_s : new_s;
									while (old_s--)
												p[old_s] = ((char *)ptr)[old_s];
										free(ptr);
											return (f);
}

