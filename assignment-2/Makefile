compile: WhitMondayMain

test: WhitMondayTest
	./WhitMondayTest

checkstyle:
	python ../cpplint.py *.cpp *.h

clean:
	rm -f *.o
	rm -f WhitMondayMain
	rm -f WhitMondayTest

WhitMondayMain: WhitMonday.o WhitMondayMain.o
	g++ -o WhitMondayMain WhitMondayMain.o WhitMonday.o

WhitMondayTest: WhitMonday.o WhitMondayTest.o
	g++ -o WhitMondayTest WhitMondayTest.o WhitMonday.o -lgtest -lpthread

WhitMonday.o: WhitMonday.cpp WhitMonday.h
	g++ -c WhitMonday.cpp

WhitMondayMain.o: WhitMondayMain.cpp WhitMonday.h
	g++ -c WhitMondayMain.cpp

WhitMondayTest.o: WhitMondayTest.cpp WhitMonday.h
	g++ -c WhitMondayTest.cpp
