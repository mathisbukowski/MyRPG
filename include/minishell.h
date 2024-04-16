/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-raphael.richaud
** File description:
** minishell.h
*/

#ifndef MINISHELL_H
    #define MINISHELL_H
    #define INPUT_SIZE 1024

typedef struct info_s {
    char *input;
    char **fullCommands;
    char *currFullCommand;
    char *currCommand;
    char **currCommandArgs;
    char **envp;
    int status;
} info_t;

int my_cd(info_t *infos);
char *my_getenv(char **envp, const char *name);
int try_builtins(info_t *infos, int *isExit);
int get_double_array_len(char **array);
char *remove_extra_spaces(const char *str);
char **copy_double_array(char **source);
int my_unsetenv(char **names, info_t *infos);
int my_setenv(info_t *infos);
void tokenize_full_command(info_t *infos, char *fullCommand);
void *my_realloc(void *ptr, int oldSize, int newSize);
void *my_calloc(int numElem, int sizeOfElem);
int my_env(char **envp);
void restore_stdout(int stdout_copy);
int handle_redirection(char **args);
int builtin_check_for_redirection(info_t *infos, int *stdout_copy);
void free_envcpy(char **envpCpy);
int is_valid_input(char *input, ssize_t bytesRead);
void signal_handler(int signal);
int process_current_command(info_t *infos);
void display_run_error(info_t *infos);
int is_exit_command(info_t *infos, int *isExit);
void check_exit(info_t *infos, int *isExit);
int try_echo_commands(info_t *infos);
int run_commands(info_t *infos);
int is_exit_command(info_t *infos, int *isExit);
#endif
