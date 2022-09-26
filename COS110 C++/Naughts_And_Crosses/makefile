ofiles = main.o GameChecker.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp GameChecker.h
	$(gpp_o) main.cpp

GameChecker.o: GameChecker.cpp GameChecker.h
	$(gpp_o) GameChecker.cpp

run: main
	./main

clean:
	rm *.o main