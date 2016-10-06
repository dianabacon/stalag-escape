# Filename: makefile
# Author: Diana Bacon
# Date: 2015-12-07
# Description: compile CS162 Final Project program
#
# Command to build program: make
# Command to execute program: ./stalag_escape

CC=g++
CFLAGS=-c -g -Wall -pedantic-errors
ifeq ($(run),test)
  CFLAGS+= -DDEBUG
endif
LDFLAGS=
SOURCES = Airman.cpp Barracks.cpp Canteen.cpp Container.cpp Forest.cpp Game.cpp Library.cpp main.cpp PlayField.cpp Space.cpp Tunnel.cpp
HEADERS = Airman.hpp Barracks.hpp Canteen.hpp Container.hpp Forest.hpp Game.hpp Library.hpp PlayField.hpp Space.hpp Tunnel.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE = stalag_escape

all: $(SOURCES) $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f ${OBJECTS} ${EXECUTABLE}
