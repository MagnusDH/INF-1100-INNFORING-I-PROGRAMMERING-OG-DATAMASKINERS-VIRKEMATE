/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#ifndef TIMER_H
#define TIMER_H

typedef struct Timer Timer;

/*
 * Create a timer 
 */
Timer *create_timer();


/*
 * Start the timer
 * should be called once for timer.
 */
void start_timer(Timer *timer);

/*
 * Tick the timer
 * will cause a delay since last tick, such that the
 * time since last tick is exactly fps.
 * is used to ensure that each round in the game loop takes same amount of time.
 */
void tick_timer(Timer *timer, int fps);

/* Example usage:
	
#define FPS 30

	void run_game()
	{
		Timer *timer;

		timer = create_timer();
		start_timer(timer);

		// Game loop
		while(1)
		{
			// game logic
			// move objects
			// draw objects
			// event handling

			tick_timer(timer, FPS);
		}
	}
 */

#endif