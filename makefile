# choice of compiler w/ flags
CC=gcc
FLAGS=-W -Wall -g
EXEC=lsys
OBJS=src/main.o src/window.o 
DEPS=src/window.h src/complex.h src/mandl.h src/thread.

# make dependencies to create the final executable
all: $(EXEC)

# simplified rule that makes all object files from their header and source
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c  -o $@ $<

# rule to make the final executable from the created object files
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $(OBJS) -o $(EXEC)

# clean out the object files and the final executable
clean:
	rm $(EXEC) src/*.o
