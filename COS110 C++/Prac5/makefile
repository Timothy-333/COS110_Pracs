ofiles = main.o TesterInterface.o NumberTester.o ValueDependantTester.o ValueIndependantTester.o IsDivisable.o IsEvenOdd.o IsGreater.o IsSmaller.o IsPrimeNumber.o 
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp TesterInterface.h NumberTester.h ValueDependantTester.h ValueIndependantTester.h IsDivisable.h IsEvenOdd.h
	$(gpp_o) main.cpp

TesterInterface.o: TesterInterface.cpp TesterInterface.h NumberTester.h
	$(gpp_o) TesterInterface.cpp

NumberTester.o: NumberTester.cpp NumberTester.h
	$(gpp_o) NumberTester.cpp

ValueDependantTester.o: ValueDependantTester.cpp ValueDependantTester.h NumberTester.h
	$(gpp_o) ValueDependantTester.cpp

ValueIndependantTester.o: ValueIndependantTester.cpp ValueIndependantTester.h NumberTester.h
	$(gpp_o) ValueIndependantTester.cpp

IsDivisable.o: IsDivisable.cpp IsDivisable.h ValueDependantTester.h
	$(gpp_o) IsDivisable.cpp

IsEvenOdd.o: IsEvenOdd.cpp IsEvenOdd.h ValueIndependantTester.h
	$(gpp_o) IsEvenOdd.cpp

IsGreater.o: IsGreater.cpp IsGreater.h ValueDependantTester.h
	$(gpp_o) IsGreater.cpp

IsSmaller.o: IsSmaller.cpp IsSmaller.h ValueDependantTester.h
	$(gpp_o) IsSmaller.cpp

IsPrimeNumber.o: IsPrimeNumber.cpp IsPrimeNumber.h ValueIndependantTester.h
	$(gpp_o) IsPrimeNumber.cpp

run: main
	./main

clean:
	rm *.o main