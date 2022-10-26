ofiles = main.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp SortList.h SortNode.h SortList.cpp SortNode.h
	$(gpp_o) main.cpp

run: main
	./main

clean:
	rm *.o main