#ifndef _STDLIB_H
#define _STDLIB_H 1

#include "stddef.h"

void *malloc(size_t size);
void *calloc(size_t count, size_t size);
void *realloc(void *p, size_t size);
void free(void *p);

unsigned long int strtoul(const char *nptr, char **endptr, int base);

#endif /* _STDLIB_H */
