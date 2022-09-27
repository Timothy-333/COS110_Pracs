ofiles = main.o TesterInterface.o NumberTester.o ValueDependantTester.o ValueIndependantTester.o IsDivisable.o IsEvenOdd.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp
	$(gpp_o) main.cpp

TesterInterface.o: TesterInterface.cpp TesterInterface.h
	$(gpp_o) TesterInterface.cpp

ValueDependantTester.o: ValueDependantTester.cpp ValueDependantTester.h IsEvenOdd.h
	$(gpp_o) ValueDependantTester.cpp

ValueIndependantTester.o: ValueIndependantTester.cpp ValueIndependantTester.h IsEvenOdd.h
	$(gpp_o) ValueIndependantTester.cpp

NumberTester.o: NumberTester.cpp NumberTester.h
	$(gpp_o) NumberTester.cpp

IsDivisable.o: IsDivisable.cpp IsDivisable.h
	$(gpp_o) IsDivisable.cpp

IsEvenOdd.o: IsEvenOdd.cpp IsEvenOdd.h
	$(gpp_o) IsEvenOdd.cpp

IsEvenOdd.o: IsEvenOdd.cpp IsEvenOdd.h
	$(gpp_o) IsEvenOdd.cpp

IsEvenOdd.o: IsEvenOdd.cpp IsEvenOdd.h
	$(gpp_o) IsEvenOdd.cpp

IsEvenOdd.o: IsEvenOdd.cpp IsEvenOdd.h
	$(gpp_o) IsEvenOdd.cpp
run: main
	./main

clean:
	rm *.o main