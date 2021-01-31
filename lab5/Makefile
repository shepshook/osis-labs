CC=gcc
CFLAGS=-c -Wall
LIBFLAGS=-pthread
SOURCES=main.c algo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=threads

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LIBFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
