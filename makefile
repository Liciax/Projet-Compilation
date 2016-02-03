# définition des actions
.PHONY: clean

# définition des variables
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -I./header/
SOURCES = src/main.cpp src/generateur.cpp
OBJECTS = $(SOURCES:.cpp =.o)

# regles
all: $(OBJECTS)
	$(CXX) -o compile $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)

src/generateur.cpp: header/generateur.hpp header/typage.hpp
	@touch header/generateur.hpp header/typage.hpp

# action clean
clean:
	-rm src/*.o compile