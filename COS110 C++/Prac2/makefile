ofiles = studentmain.o matrix.o
gpp_o = g++ -c -std=c++98

studentmain: $(ofiles)
	g++ -std=c++98 $(ofiles) -o studentmain

studentmain.o: studentmain.cpp matrix.h
	$(gpp_o) studentmain.cpp

matrix.o: matrix.cpp matrix.h
	$(gpp_o) matrix.cpp

run: studentmain
	./studentmain

clean:
	rm *.o studentmain