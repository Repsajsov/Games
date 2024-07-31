CC = g++
CFLAGS = -std=c++11 -Wall -g
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SOURCES = main.cpp Utilities/random_generator.cpp ball.cpp States/menuState.cpp States/gameState.cpp States/endState.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = myGame

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
