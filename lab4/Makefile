CC=gcc
CFLAGS=-c -Wall
SOURCES=main.c algo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=myps

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# $< - first prerequisite name (i.e. main.c)
# $@ - target name (i.e. main.o)
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# test:
# 	./$(EXECUTABLE) 

clean:
	rm -rf *.o $(EXECUTABLE)
