#Makefile

FLAGS = -pedantic-errors -std=c++11

main.o: main.cpp game.h
	g++ $(FLAGS) -c $<

game.o: game.cpp game.h
	g++ $(FLAGS) -c $<

game: main.o game.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f game game.o main.o

.PHONY: clean run
