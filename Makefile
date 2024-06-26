SOURCES = main.cpp
EXE = main

all: $(EXE)
$(EXE): $(SOURCES)
	g++ $(SOURCES) -lncurses -o $(EXE)