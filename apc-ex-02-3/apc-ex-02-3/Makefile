all: fraction_exec

fraction_exec: main.o
	g++ main.o -o fraction_exec

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf main.o fraction_exec