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
ssize_t _getline(char **line, size_t *size);
char *_strtok(char *str, const char *delim);
int allocateMemory(char **line, size_t *size);
int readCharacter(FILE *stream, char **line, ssize_t *bytesRead,
		ssize_t *totalBytesRead, size_t *size);
int resizeLineBuffer(char **line, size_t *size);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
int _puts(const char *str);
int _putchar(int character);
size_t _strcspn(const char *str, const char *reject);
void *_realloc(void *ptr, size_t new_size);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *str1, const char *str2, size_t n);

#endif

