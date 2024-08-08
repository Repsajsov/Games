# I STILL HAVE NOT FIGURED OUT HOW TO MAKE IT COMPATIBLE FOR BOTH MAC AND LINUX!

# CC = g++
# CFLAGS = -std=c++11 -Wall -g
# LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# SOURCES = main.cpp Utilities/random_generator.cpp ball.cpp States/menuState.cpp States/gameState.cpp States/endState.cpp Components/start.cpp

# OBJECTS = $(SOURCES:.cpp=.o)

# EXECUTABLE = myGame

# all: $(EXECUTABLE)

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

# %.o: %.cpp
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJECTS) $(EXECUTABLE)

# .PHONY: all clean

CC = g++
CFLAGS = -std=c++11 -Wall -g
LIBS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -lraylib
SOURCES = main.cpp Utilities/random_generator.cpp ball.cpp States/menuState.cpp States/gameState.cpp States/endState.cpp Components/button.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = myGame

BREW_PREFIX = $$(brew --prefix)
CFLAGS += -I$(BREW_PREFIX)/include
LIBS += -L$(BREW_PREFIX)/lib

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
