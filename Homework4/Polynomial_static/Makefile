all: polynomial.a main
	g++ main.o -o -lpolynomial -o polynomial

main: main.cc
	g++ main.cc -c -o main.o

polynomial.a: polynomial
	ar rcs libpolynomial.a polynomial.o

polynomial: polynomial.h polynomial.cc
	g++ polynomial.cc -c -o build/polynomial.o

clean:
	rm -rf build/*
