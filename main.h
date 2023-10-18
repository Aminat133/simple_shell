#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
extern char **environ;

#define MAX_ARGS 64
#define MAX_ARG_LEN 16

char *read_input(void);
void execute_command(char *cmd);
void execute_env(void);
void execute_child_process(char *argv[]);
void execute_parent_process(pid_t pid);
char *_getenv(const char *name);
ssize_t _getline(char **line, size_t *size, FILE *stream);
char *_strtok(char *str, const char *delim);
int allocateMemory(char **line, size_t *size);
int readCharacter(FILE *stream, char **line, ssize_t *bytesRead,
		ssize_t *totalBytesRead, size_t *size);
int resizeLineBuffer(char **line, size_t *size);

#endif

