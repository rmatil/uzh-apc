all: clean dictionary

dictionary: main.o
	g++ main.o -o dictionary

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf main.o dictionary