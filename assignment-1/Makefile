compile:
	    g++ -o WhitMondayMain WhitMondayMain.cpp

checkstyle:
	    python ../cpplint.py *.cpp

test:
	    g++ -o WhitMondayTest WhitMondayTest.cpp -lgtest -lpthread
	        ./WhitMondayTest

clean:
	    rm -f WhitMondayMain
	    rm -f WhitMondayTest
