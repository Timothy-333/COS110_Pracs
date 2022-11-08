ofiles = mainP1.o Door.o Exit.o Floor.o Game.o Lamp.o Map.o Player.o Wall.o Object.o ObjectList.o Message.o MessageQueue.o

main: $(ofiles)
	g++ -static $(ofiles) -o main

mainP1.o: mainP1.cpp Game.h
	g++ -c mainP1.cpp

Door.o: Door.cpp Door.h Object.h
	g++ -c Door.cpp

Exit.o: Exit.cpp Exit.h Object.h
	g++ -c Exit.cpp

Floor.o: Floor.cpp Floor.h Object.h
	g++ -c Floor.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Lamp.o: Lamp.cpp Lamp.h Object.h
	g++ -c Lamp.cpp

Map.o: Map.cpp Map.h
	g++ -c Map.cpp

Player.o: Player.cpp Player.h Object.h
	g++ -c Player.cpp

Wall.o: Wall.cpp Wall.h Object.h
	g++ -c Wall.cpp

Object.o: Object.cpp Object.h
	g++ -c Object.cpp

ObjectList.o: ObjectList.cpp ObjectList.h
	g++ -c ObjectList.cpp

Message.o: Message.cpp Message.h
	g++ -c Message.cpp

MessageQueue.o: MessageQueue.cpp MessageQueue.h
	g++ -c MessageQueue.cpp

run: main
	./main

clean:
	rm *.o 