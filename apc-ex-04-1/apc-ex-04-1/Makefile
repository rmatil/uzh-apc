all: clean pvector

pvector: main.o PVector.o PSet.o
	g++ main.o PVector.o PSet.o -o pvector

main.o: main.cpp
	g++ -c main.cpp
	
PVector.o: PVector.cpp
	g++ -c PVector.cpp
	
PSet.o: PSet.cpp
	g++ -c PSet.cpp

clean:
	rm -rf *.o pvector