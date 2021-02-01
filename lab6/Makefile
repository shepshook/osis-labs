CC=g++
CFLAGS=-c -Wall
LIBFLAGS=
SOURCES=main.cpp daemon.cpp server.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tcp

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LIBFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
