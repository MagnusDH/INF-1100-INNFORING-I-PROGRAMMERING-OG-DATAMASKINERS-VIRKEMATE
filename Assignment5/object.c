#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "object.h"


/*
 * Return a newly created object based on the arguments provided.
 */
object_t *create_object(SDL_Surface *surface, triangle_t *model, int numtriangles)
{
    /* Implement me */

    //Allocating memory for the sphere
    object_t *sphere_object = malloc(sizeof(object_t));
    if(sphere_object == NULL){
        return NULL;
    }
    
    sphere_object->surface = surface;
    sphere_object->model = malloc(sizeof(triangle_t) * numtriangles);
    memcpy(sphere_object->model, model, sizeof(triangle_t) * numtriangles); //Copying all triangles to a specific location.(Cannot alter the original triangles since we have more spheres)
    

    //Assigning some attributes to the sphere(rest is done in draw_object())
    sphere_object->scale = 0.1;
    sphere_object->tx = 400;
    sphere_object->ty = 400;
    sphere_object->speedx = rand() % 4;
    sphere_object->speedy = rand() % 4;
    sphere_object->ttl = 1;
    sphere_object->numtriangles = numtriangles;
    sphere_object->radius = 510;
    sphere_object->radius *= sphere_object->scale;

    //Returning a newly created sphere
    return sphere_object;
}

/*
 * Destroy the object, freeing the memory.
 */
void destroy_object(object_t *object)
{
    /* Implement me */
    free(object);
}

/*
 * Draw the object on its surface.
 */
void draw_object(object_t *object)
{
    /* Implement me */
    int numtriangles = object->numtriangles;

    for(int i = 0; i < numtriangles; i++){
        object->model[i].scale = object->scale;
        object->model[i].rotation = object->rotation;    
        object->model[i].tx = object->tx;
        object->model[i].ty = object->ty;

        //Drawing sphere
        draw_triangle(object->surface, &object->model[i]);
    }
} 
