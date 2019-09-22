#ifndef _STDIO_H
#define _STDIO_H 1

#include "stddef.h"

#define NULL ((void *)0)

#define EOF (-1)

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define FOPEN_MAX    255
#define FILENAME_MAX 255

#define SEEK_SET  0
#define SEEK_CURR 1
#define SEEK_END  2

typedef long int fpos_t;

typedef struct {
	int fd;
	fpos_t pos;

	char mode;
	int eof;
} FILE;

static const FILE stdin = {
	.fd = 0,
	.pos = 0,
};
static const FILE stdout = {
        .fd = 1,
        .pos = 0,
};
static const FILE stderr = {
	.fd = 2,
	.pos = 0,
};

#define stdin  (&stdin)
#define stdout (&stdout)
#define stderr (&stderr)

int printf(const char *restrict format, ...);
char *fgets(char *str, int n, FILE *stream);

FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *stream);

int feof(FILE *stream);
long int ftell(FILE *stream);
int fseek(FILE *stream, long int offset, int whence);

int fgetc(FILE *stream);

void rewind(FILE *stream);

#endif /* _STDIO_H */
