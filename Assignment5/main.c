#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "list.h"
#include "teapot_data.h"
#include "sphere_data.h"
#include "object.h"

/* Two macro's that find the lesser or greater of two values */
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

/*
 * Clear the surface by filling it with 0x00000000(black).
 */
void clear_screen(SDL_Surface *surface)
{
    if(SDL_FillRect(surface, NULL, 0x00000000) < 0){
        fprintf(stderr, "Unable to clear the surface. Error returned: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

/*
 * Accelerate the object; altering its speed based on the boost given.
 */
void accelerate_object(object_t *a, float boost, float maxspeed)
{
    float s;
    float news;
    
    /* Calculate lenght of speed vector */
    s = sqrtf(a->speedx * a->speedx + a->speedy * a->speedy);

    /* Boost speed */
    news = s * boost;
    if (news < 0.0)
        news = 0.0;
    if (news > maxspeed)
        news = maxspeed;    
    a->speedx *= news/s;
    a->speedy *= news/s;
}

/*
 * Animate bouncing balls on the screen.
 */
void bouncing_balls(SDL_Window *window)
{
    /* Implement me */
    SDL_Event event;
    SDL_Surface *surface;
    int done = 0;
    surface = SDL_GetWindowSurface(window);
    
    //Creating list and iterator
    list_t *list = list_create();
    list_iterator_t *iterator = list_createiterator(list);
    object_t *sphere;

    //creatig spheres and adding them to list
    while(list_size(list) < 5){
        object_t *sphere = create_object(surface, sphere_model, SPHERE_NUMTRIANGLES);
        list_addfirst(list, sphere);
    }

    //Running animation loop
    while (!done) {
        clear_screen(surface);

        list_resetiterator(iterator);

        while( (sphere = list_next(iterator)) ){
            draw_object(sphere);
            sphere->rotation += 1;
            sphere->tx += sphere->speedx;
            sphere->ty += sphere->speedy;
            sphere->speedy += 0.1;

            //Checking if sphere hits walls, and alter its speed if so
            if(sphere->tx + sphere->radius > surface->w){
                sphere->speedx = -sphere->speedx;
            }
            if(sphere->tx - sphere->radius < 0){
                sphere->speedx = -sphere->speedx;
            }
            if(sphere->ty + sphere->radius > surface->h){
                sphere->speedy = -sphere->speedy;
            }
            if(sphere->ty - sphere->radius < 0){
                sphere->speedy = -sphere->speedy;
            }
        }
        list_resetiterator(iterator);

        /* Update the window surface */
        SDL_UpdateWindowSurface(window);

        /* Detect that the user tries to quit the application */
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    done = 1;
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_SHOWN)
                        SDL_SetWindowPosition(window, 50, 50);
                    break;
            }
        }
    }
}

int main(void)
{
    const size_t bufsize = 100;
    
    /* Change the screen width and height to your own liking */
    const int screen_w = 1600;
    const int screen_h = 900;

    char errmsg[bufsize];
    SDL_Window *window;

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < -1) {
        snprintf(errmsg, bufsize, "Unable to initialize SDL.");
        goto error;
    }
    
    /* Create a 1600x900 window */
    window = SDL_CreateWindow("The Amazing Bouncing Balls",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screen_w, screen_h,
                              0);
    if(!window) {
        snprintf(errmsg, bufsize, "Unable to get video surface.");
        goto error;
    }

    /* Start bouncing some balls */
    bouncing_balls(window);

    /* Shut down SDL */
    SDL_Quit();

    /* Wait a little bit jic something went wrong (so that printfs can be read) */
    SDL_Delay(5000);
    
    return 0;

    /* Upon an error, print message and quit properly */
error:
    fprintf(stderr, "%s Error returned: %s\n", errmsg, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
