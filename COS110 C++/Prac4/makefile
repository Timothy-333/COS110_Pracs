ofiles = main.o TwoDArray.o SumArray.o CountArray.o SortArray.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp
	$(gpp_o) main.cpp

TwoDArray.o: TwoDArray.cpp TwoDArray.h
	$(gpp_o) TwoDArray.cpp

SumArray.o: SumArray.cpp SumArray.h TwoDArray.h
	$(gpp_o) SumArray.cpp

CountArray.o: CountArray.cpp CountArray.h TwoDArray.h
	$(gpp_o) CountArray.cpp

SortArray.o: SortArray.cpp SortArray.h TwoDArray.h
	$(gpp_o) SortArray.cpp

run: main
	./main

clean:
	rm *.o main