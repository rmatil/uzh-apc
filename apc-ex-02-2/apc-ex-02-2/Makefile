all: clean exec

exec: fraction_exec
	./fraction_exec

fraction_exec: fraction-test.o Fraction.o Util.o
	g++ fraction-test.o Fraction.o Util.o -o fraction_exec

fraction-test.o: fraction-test.cpp
	g++ -c fraction-test.cpp

Fraction.o: Fraction.cpp
	g++ -c Fraction.cpp

Util.o: Util.cpp
	g++ -c Util.cpp

clean:
	rm -rf fraction-test.o Fraction.o Util.o fraction_exec