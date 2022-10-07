run: main
	./main

main: main.o Passenger.o Cargo.o SecretCargo.o
	g++ -static main.o Cargo.o Passenger.o SecretCargo.o -o main

main.o:	main.cpp Cargo.h Passenger.h SecretCargo.h Exceptions.h Controller.h Plane.h Exceptions.cpp Controller.cpp Plane.cpp
	g++ -c main.cpp

Passenger.o: Passenger.cpp Passenger.h
	g++ -c Passenger.cpp

Cargo.o: Cargo.cpp Cargo.h
	g++ -c Cargo.cpp

SecretCargo.o: SecretCargo.cpp SecretCargo.h
	g++ -c SecretCargo.cpp

clean:
	rm *.o 