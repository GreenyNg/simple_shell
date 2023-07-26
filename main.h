#ifndef MAIN_H_
#define MAIN_H

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

/*string_handlers*/
char *duplicate_str(char *str);
char *check_str(char *str, int chrs);
int _strlen(const char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *f, const char *s, int n);

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


/*command_handler*/
char *_getpath(void);
char **put_token(char *str);
void exec(char *c, char **cmd);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *app_path(char *path, char *cmd);
char *sch_path(char **p, char *cmd);

/*built-ins*/
void env_builtin(void);
void logout(char **cmd, char *b);
int is_builtin(char **cmd, char *b);
void prompt(void);
void handle_sig(int n);

/*helper function*/
int cmd_type(char **cmd, char *b);
void free_cmds(char **m);

/*environment variables*/
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;


struct builtins
{
		char *env;
			char *exit;

} builtins;


struct info
{
		int final_exit;
			int ln_count;
} info;


struct flags
{
		bool interactive;
} flags;


#endif 
