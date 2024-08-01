/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#ifndef _COMMON_H
#define _COMMON_H

#include <stdlib.h>
#include <stdint.h>

/*
 * Prints error message and
 * exits the program.
 * Message can be formated in same style as printf.
 */
void fatal_error(char *msg, ...);

/*
 * Allocates memory with malloc and handles
 * errors if malloc failed.
 */
void *emalloc(size_t size);

/*
 * Allocates memory with calloc and calls
 * fatal error if calloc failed.
 */
void *ecalloc(size_t nitems, size_t size);

/*
 * Reallocates memory pointed to by ptr
 * and calls fatal error if realloc failes.
 */
void *erealloc(void *ptr, size_t size);


#endif