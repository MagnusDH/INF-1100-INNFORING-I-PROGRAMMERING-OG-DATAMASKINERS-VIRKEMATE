EXECUTABLE = app
CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -ISDL2 -D_REENTRANT -DSDL_MAIN_HANDLED
LIBS = -lm -L. -lSDL2

SOURCE = main.c triangle.c drawline.c object.c list.c common.c draw_figures.c timer.c vector.c
HEADER = drawline.h triangle.h object.h list.h teapot_data.h sphere_data.h common.h draw_figures.h timer.h vector.h

include Makefile.in

.PHONY: all
all: $(EXECUTABLE)
$(EXECUTABLE): $(SOURCE) $(HEADER)
	$(info === Compiling...)
	$(shell $(PRE_BUILD))
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBS)
    
.PHONY: clean
clean:
	@rm -f *.o $(EXECUTABLE) *~ SDL2.dll libSDL2-2.0.so.0
	$(info === Cleaned)
