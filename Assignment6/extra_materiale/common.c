/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

#include "common.h"

/*
 * Prints error message and
 * exits the program.
 * Message can be formated in same style as printf.
 */
void fatal_error(char *msg, ...)
{
	va_list arguments;

	va_start(arguments, msg);
	fprintf(stderr, "fatal error:\n");
	vfprintf(stderr, msg, arguments);
	fprintf(stderr, "\n");
	va_end(arguments);

	exit(EXIT_FAILURE);
}

/*
 * Allocates memory with malloc and calls
 * fatal error if malloc failed.
 */
void *emalloc(size_t size)
{
	void *mem_bloc = malloc(size);

	if (!mem_bloc)
	{
		fatal_error("Failed to allocate memory");
	}

	return mem_bloc;
}

/*
 * Allocates memory with calloc and calls
 * fatal error if calloc failed.
 */
void *ecalloc(size_t nitems, size_t size)
{
	void *mem_bloc = calloc(nitems, size);

	if (!mem_bloc)
	{
		fatal_error("Failed to allocate memory");
	}

	return mem_bloc;
}

/*
 * Reallocates memory pointed to by ptr
 * and calls fatal error if realloc failes.
 */
void *erealloc(void *ptr, size_t size)
{
	ptr = realloc(ptr, size);

	if (!ptr)
	{
		fatal_error("Failed to reallocate memory");
	}	

	return ptr;
}
