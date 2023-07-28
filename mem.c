#include "main.h"

/* frees a pointer and NULLs the address */
int bfree(void **ptr)
{
	if (ptr && *ptr)
			free(*ptr);
			*ptr = NULL;
				return (1);
					}
	return (0);
}


