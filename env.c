#include "main.h"

/* prints the current environment*/
int _myenv(info_t *info)
{
		print_list_str(info->env);
			return (0);
}

/* gets the value of an environ variable   */
char *_getenv(info_t *info, const char *name)
{
		list_t *node = info->env;
		char *h;

				while (node)
						{
							h = starts_with(node->str, name);
								if (h && *h)
									return (h);
								node = node->next;
														}
					return (NULL);
}

/* Initialize a new environment variable */
int _mysetenv(info_t *info)
{
		if (info->argc != 3)
				{
			_erputs("Incorrect number of arguements\n");
							return (1);
										}
			if (_setenv(info, info->argv[1], info->argv[2]))
						return (0);
				return (1);
}

/*Remove an environment variable */
int _myunsetenv(info_t *info)
{
		int j;

			if (info->argc == 1)
					{
			_erputs("Too few arguements.\n");
									return (1);
											}
				for (j = 1; j <= info->argc; j++)
							_unsetenv(info, info->argv[j]);

					return (0);
}

/* populates env linked list */
int populate_env_list(info_t *info)
{
		list_t *node = NULL;
			size_t i;

			for (i = 0; environ[i]; i++)
				add_node_end(&node, environ[i], 0);
				info->env = node;
				return (0);
}



