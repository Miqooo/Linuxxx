all: polynomial main
	g++ build/polynomial.o build/main.o -o build/polynomial

main: main.cc
	g++ main.cc -c -o build/main.o

polynomial: polynomial.h polynomial.cc
	g++ polynomial.cc -c -o build/polynomial.o

clean:
	rm -rf build/*