/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

#include "drawline.h"
#include "common.h"
#include "timer.h"


struct Timer
{
	// last recorded time
	unsigned int time;
};

/*
 * Create a timer 
 */
Timer *create_timer()
{
	Timer *timer;

	timer = emalloc(sizeof(Timer));
	timer->time = 0;

	return timer;
}

/*
 * Start the timer
 */
void start_timer(Timer *timer)
{
	timer->time = SDL_GetTicks();
}

/*
 * Tick the timer
 * will cause a delay since last tick, such that the
 * time since last tick is exactly fps.
 */
void tick_timer(Timer *timer, int fps)
{
	int ms_per_frame, sleep_time;

	ms_per_frame = 1000/fps;
	timer->time += ms_per_frame;
	sleep_time = timer->time - SDL_GetTicks();

	if (sleep_time > 0)
	{
		SDL_Delay(sleep_time);
	}
}