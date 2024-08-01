#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "teapot_data.h"

/*
 * Clear the surface by filling it with 0x00000000(black)
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
 * Run the demo with the rotating teapot
 */
void demo(SDL_Window *window)
{
    int i;
    SDL_Event event;
    SDL_Surface *surface;
    int done = 0;

    unsigned int current_time;
    unsigned int last_time = 0;
    unsigned int create_frame;

    while (!done) {
        current_time = SDL_GetTicks();
        surface = SDL_GetWindowSurface(window);
        clear_screen(surface);

        /* Draw teapot */
        for (i = 0; i < TEAPOT_NUMTRIANGLES; i++) {
            /* Translate triangle into middle of screen before drawing it */
            teapot_model[i].tx = surface->w/2;
            teapot_model[i].ty = surface->h/2;
            teapot_model[i].rotation += 1;
            
            /* And draw it */
            draw_triangle(surface, &teapot_model[i]);
        }

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
        last_time = SDL_GetTicks();
        create_frame = last_time - current_time;
        printf("Time to create one frame: %d\n", create_frame);

        /////////////////////////////////////////////////CONTINUE HERE! TRY TO GET IT TO UPDATE ON A DECIDED NUMBER OF FRAMES///////////////////////////////////////////////////////////////////////////////////
        if(create_frame < 20){
            int delay = 20-create_frame;
            SDL_Delay(delay);
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
    window = SDL_CreateWindow("The Amazing Teapot",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screen_w, screen_h,
                              0);
    if(!window) {
        snprintf(errmsg, bufsize, "Unable to get video surface.");
        goto error;
    }

    /* Run the rotating teapot animation */
    demo(window);
    
    SDL_Quit();
    
    return 0;

    /* Upon an error, print message and quit properly */
error:
    fprintf(stderr, "%s Error returned: %s\n", errmsg, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}