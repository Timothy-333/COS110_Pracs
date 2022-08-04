main: main.o student.h student.o
	g++ -static student.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp
	
student.o: student.h student.cpp
	g++ -c student.cpp
	
run:
	./main

clean:
	rm -f *.o main