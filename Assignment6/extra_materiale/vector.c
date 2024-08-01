/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>

#include "drawline.h"
#include "common.h"
#include "object.h"
#include "vector.h"

struct Vector
{
	double x;
	double y;
};


/*
 * Creates a new vector 
 */
Vector *create_vector(double x, double y)
{
	Vector *vector;

	vector = emalloc(sizeof(Vector));
	vector->x = x;
	vector->y = y;

	return vector;
}

/*
 * Adds x and y to vector coordinates
 */
void add_vector_coordinates(Vector *vector, double x, double y)
{
	if (!vector)
	{
		fatal_error("NULL vector in add_vector_coordinates");
	}
	
	vector->x += x;
	vector->y += y;
}

/*
 * subtracts x and y to vector coordinates
 */
void sub_vector_coordinates(Vector *vector, double x, double y)
{
	if (!vector)
	{
		fatal_error("NULL vector in sub_vector_coordinates");
	}
	
	vector->x -= x;
	vector->y -= y;
}

/*
 * Add a vector with another vector
 * first vector holds the result
 */
void add_vector(Vector *vec1, Vector *vec2)
{
	if (!vec1 || !vec2)
	{
		fatal_error("NULL vector to add_vector");
	}

	vec1->x += vec2->x;
	vec1->y += vec2->y;
}

/*
 * subtract a vector with another vector
 * first vector holds the result
 */
void sub_vector(Vector *vec1, Vector *vec2)
{
	if (!vec1 || !vec2)
	{
		fatal_error("NULL vector to sub_vector");
	}

	vec1->x -= vec2->x;
	vec1->y -= vec2->y;
}

/*
 * multiply a vector with a scalar
 * given vector holds result
 */
void mul_vector(Vector *vector, double scalar)
{
	if (!vector)
	{
		fatal_error("NULL vector to mul_vector");
	}

	vector->x *= scalar;
	vector->y *= scalar;
}

/*
 * divide a vector with a scalar
 * given vector holds result
 */
void div_vector(Vector *vector, double scalar)
{
	if (!vector)
	{
		fatal_error("NULL vector to div_vector");
	}
	if (scalar == 0)
	{
		fatal_error("division by zero in div_vector");
	}

	vector->x /= scalar;
	vector->y /= scalar;
}


/*
 * Get length of vector.
 */
double get_length_vector(Vector *vector)
{
	if (!vector)
	{
		fatal_error("NULL vector to get_length_vector");
	}

	double x, y;

	x = vector->x;
	y = vector->y;

	return sqrt(x*x + y*y);
}

/*
 * Returns x value in vector
 */
double get_x(Vector *vector)
{
	if (!vector)
	{
		fatal_error("NULL vector to get_x");
	}

	return vector->x;
}

/*
 * Returns y value in vector
 */
double get_y(Vector *vector)
{
	if (!vector)
	{
		fatal_error("NULL vector to get_y");
	}
	
	return vector->y;
}

/*
 * Sets x value in vector
 */
void set_x(Vector *vector, double x)
{
	if (!vector)
	{
		fatal_error("NULL vector to set_x");
	}

	vector->x = x;
}

/*
 * Sets y value in vector
 */
void set_y(Vector *vector, double y)
{
	if (!vector)
	{
		fatal_error("NULL vector to set_y");
	}

	vector->y = y;
}

/*
 * Free memory held by vector
 */
void destroy_vector(Vector *vector)
{
	if (!vector)
	{
		fatal_error("Tried to free empty vector");
	}

	free(vector);
}