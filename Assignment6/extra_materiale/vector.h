/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#ifndef VECTOR_H
#define VECTOR_H


typedef struct Vector Vector;

/*
 * Creates a new vector 
 */
Vector *create_vector(double x, double y);

/*
 * Add a vector with another vector
 * first vector holds the result
 */
void add_vector(Vector *vec1, Vector *vec2);

/*
 * subtract a vector with another vector
 * first vector holds the result
 */
void sub_vector(Vector *vec1, Vector *vec2);

/*
 * multiply a vector with a scalar
 * given vector holds result
 */
void mul_vector(Vector *vector, double scalar);

/*
 * divide a vector with a scalar
 * given vector holds result
 */
void div_vector(Vector *vector, double scalar);

/*
 * Adds x and y to vector coordinates
 */
void add_vector_coordinates(Vector *vector, double x, double y);

/*
 * subtracts x and y to vector coordinates
 */
void sub_vector_coordinates(Vector *vector, double x, double y);

/*
 * Get length of vector.
 */
double get_length_vector(Vector *vector);

/*
 * Returns x value in vector
 */
double get_x(Vector *vector);

/*
 * Returns y value in vector
 */
double get_y(Vector *vector);

/*
 * Sets x value in vector
 */
void set_x(Vector *vector, double x);

/*
 * Sets y value in vector
 */
void set_y(Vector *vector, double y);

/*
 * Free memory held by vector
 */
void destroy_vector(Vector *vector);

#endif