ofiles = studentmain.o chessboard.o chesspiece.o
gpp_o = g++ -c -std=c++98

studentmain: $(ofiles)
	g++ -std=c++98 $(ofiles) -o studentmain

studentmain.o: studentmain.cpp chesspiece.h chessboard.h
	$(gpp_o) studentmain.cpp

chesspiece.o: chesspiece.cpp chesspiece.h
	$(gpp_o) chesspiece.cpp

chessboard.o: chessboard.cpp chessboard.h chesspiece.h
	$(gpp_o) chessboard.cpp

run: studentmain
	./studentmain

clean:
	rm *.o studentmain