ofiles = main.o TwoDArray.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp
	$(gpp_o) main.cpp

TwoDArray.o: TwoDArray.cpp TwoDArray.h
	$(gpp_o) TwoDArray.cpp

run: main
	./main

clean:
	rm *.o main