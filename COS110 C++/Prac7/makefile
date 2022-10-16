main: main.o calendar.o Event.o
	g++ -static main.o Event.o calendar.o -o main

main.o:	main.cpp Event.h calendar.h Utils.h
	g++ -c main.cpp

calendar.o: calendar.cpp calendar.h
	g++ -c calendar.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

run: main
	./main

clean:
	rm *.o 