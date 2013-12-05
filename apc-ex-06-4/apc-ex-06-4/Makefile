all: clean connect4

connect4: main.o game.o ai.o my_player.o my_playfield.o
	g++ main.o game.o ai.o my_player.o my_playfield.o -o connect4

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

ai.o: ai.cpp
	g++ -c ai.cpp

my_player.o: my_player.cpp
	g++ -c my_player.cpp

my_playfield.o: my_playfield.cpp
	g++ -c my_playfield.cpp

clean:
	rm -rf *.o connect4