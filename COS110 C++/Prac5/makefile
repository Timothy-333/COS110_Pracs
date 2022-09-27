ofiles = main.o TesterInterface.o ValueDependant.o CountArray.o SortArray.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp
	$(gpp_o) main.cpp

TesterInterface.o: TesterInterface.cpp TesterInterface.h
	$(gpp_o) TesterInterface.cpp

ValueDependant.o: ValueDependant.cpp ValueDependant.h TesterInterface.h
	$(gpp_o) ValueDependant.cpp

CountArray.o: CountArray.cpp CountArray.h TesterInterface.h
	$(gpp_o) CountArray.cpp

SortArray.o: SortArray.cpp SortArray.h TesterInterface.h
	$(gpp_o) SortArray.cpp

run: main
	./main

clean:
	rm *.o main