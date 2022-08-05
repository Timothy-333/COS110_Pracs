ofiles = main.o
gpp_0 = g++ -c -std=c++11 -static

main: $(ofiles)
	g++ -std=c++11 -static $(ofiles) -o main

main.o: main.cpp
	$(gpp_0) main.cpp

run: main
	./main

clean:
	rm -f *.o main