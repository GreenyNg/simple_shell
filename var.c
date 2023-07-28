#include "main.h"

/*test if current char in buffer       */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;
		if (buf[j] == '|' && buf[j + 1] == '|')
				{
			buf[j] = 0;
						j++;
							info->cmd_buf_type = CMD_OR;
										}
	else if (buf[j] == '&' && buf[j + 1] == '&')
			{
			buf[j] = 0;
			j++;
					info->cmd_buf_type = CMD_AND;
									}
		else if (buf[j] == ';') 
				{
							buf[j] = 0; 
							info->cmd_buf_type = CMD_CHAIN;
													}
						else
									return (0);
						*p = j;
								return (1);
}

/*checks we should continue chaining based on last status */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
					{
					if (info->status)
						{
									buf[i] = 0;
											j = len;
																		}
				}
			if (info->cmd_buf_type == CMD_OR)
				{
						if (!info->status)
					{
								buf[i] = 0;
								j = len;
											}
							}
	*p = j;
}

/*replaces an aliases in the tokenized string */
int replace_alias(info_t *info)
{
	int j;
			list_t *node;
				char *h;

		for (j = 0; j < 10; j++)
						{
						node = node_starts_with(info->alias, info->argv[0], '=');
									if (!node)
										return (0);
								free(info->argv[0]);
							h = _strchr(node->str, '=');
											if (!h)
																					return (0);
	h = _strdup(p + 1);
						if (!h)
																										return (0);
							info->argv[0] = h;
																									}
						return (1);
}

/*replaces vars in the tokenized string */
int replace_vars(info_t *info)
{
		int j = 0;
		list_t *node;

				for (j = 0; info->argv[j]; j++)
						{
							if (info->argv[j][0] != '$' || !info->argv[j][1])
													continue;
						if (!_strcmp(info->argv[i], "$?"))
								{
		replace_string(&(info->argv[j]),
																							_strdup(convert_number(info->status, 10, 0)));
																					continue;
																							}
						if (!_strcmp(info->argv[j], "$$"))
														{
					replace_string(&(info->argv[j]),
								_strdup(convert_number(getpid(), 10, 0)));
																							continue;
																									}
		node = node_starts_with(info->env, &info->argv[j][1], '=');
																	if (node)
																				{
								replace_string(&(info->argv[j]),
																									_strdup(_strchr(node->str, '=') + 1));
																									continue;
																						}
								replace_string(&info->argv[j], _strdup(""));

																				}
					return (0);
}

/*replaces string   */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

