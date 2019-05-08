CFLAGS = -Wall -g -std=c++11 #definition de variable

all : mainEx1 mainEx2

PolyAbstrEx1.o: MonPolyAbstrEx1.hpp MonPolyAbstrEx1.cpp
	g++ $(CFLAGS) -c MonPolyAbstrEx1.cpp

PolyAbstrEx2.o: MonPolyAbstrEx2.hpp MonPolyAbstrEx2.cpp
	g++ $(CFLAGS) -c MonPolyAbstrEx2.cpp

mainEx1: mainEx1.cpp PolyAbstrEx1.o
	g++ $(CFLAGS) mainEx1.cpp MonPolyAbstrEx1.o -o Ex1

mainEx2: mainEx2.cpp PolyAbstrEx2.o
	g++ $(CFLAGS) mainEx2.cpp MonPolyAbstrEx2.o -o Ex2

clean:
	rm -f Ex1 Ex2 MonPolyAbstrEx1.o MonPolyAbstrEx2.o
