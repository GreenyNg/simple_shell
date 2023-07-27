#include"main.h"

/* current environment*/
 int _env(info_t *info)
{
	print_list_str(info->env);
		return (0);
}

/*gets the value of an environ  */
char *_getenv(info_t *info, const char *name)
{
		list_t *node = info->env;
		char *v;

			while (node)
					{
			v = starts_with(node->str, name);
				if (v && *v)
					return (v);
													node = node->next;
													}
					return (NULL);
}

/*Initialize a new environment*/
int _setenv(info_t *info)
{
	if (info->argc != 3)
				{
		_puts("Incorrect number of arguements\n");
									return (1);
										}
			if (_setenv(info, info->argv[1], info->argv[2]))
						return (0);
				return (1);
}

/* Remove an environment variable */
int _unsetenv(info_t *info)
{
		int j;
		if (info->argc == 1)
					{
								_puts("Too few arguements.\n");
										return (1);
											}
				for (j = 1; j <= info->argc; j++)
							_unsetenv(info, info->argv[j]);

					return (0);
}

/* populates env linked list */
int pop_env_list(info_t *info)
{
		list_t *node = NULL;
			size_t i;

				for (i = 0; environ[i]; i++)
							add_node_end(&node, environ[i], 0);
					info->env = node;
						return (0);
}



