run: main
	./main

main: main.o Arithmetic.o Matrix.o Vector.o
	g++ -static main.o Matrix.o Arithmetic.o Vector.o -o main

main.o:	main.cpp matrix.h arithmetic.h vector.h
	g++ -c main.cpp

Arithmetic.o: Arithmetic.cpp arithmetic.h
	g++ -c Arithmetic.cpp

Matrix.o: Matrix.cpp matrix.h
	g++ -c Matrix.cpp

Vector.o: Vector.cpp vector.h
	g++ -c Vector.cpp

clean:
	rm *.o 