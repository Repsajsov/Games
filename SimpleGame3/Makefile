CC = g++
CFLAGS = -std=c++14 -Wall -g
LIBS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -lraylib
SOURCES = main.cpp assets.cpp
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
