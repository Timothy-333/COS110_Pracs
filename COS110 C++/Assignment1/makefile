ofiles = main.o FitnessFunction.o GA.o RandomGenerator.o Chromosome.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Chromosome.h FitnessFunction.h GA.h RandomGenerator.h
	$(gpp_o) main.cpp

Chromosome.o: Chromosome.cpp Chromosome.h FitnessFunction.h RandomGenerator.h
	$(gpp_o) Chromosome.cpp

FitnessFunction.o: FitnessFunction.cpp FitnessFunction.h
	$(gpp_o) FitnessFunction.cpp

GA.o: GA.cpp GA.h FitnessFunction.h RandomGenerator.h Chromosome.h
	$(gpp_o) GA.cpp

RandomGenerator.o: RandomGenerator.cpp RandomGenerator.h
	$(gpp_o) RandomGenerator.cpp

run: main
	./main

clean:
	rm *.o main