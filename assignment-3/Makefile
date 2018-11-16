CXX = g++
LIBS = -lncurses
HEADERS = $(wildcard *.h)

all: compile test checkstyle

compile: TetrisMain

test: TetrisTest
	./TetrisTest

checkstyle:
	python ../cpplint.py *.cpp *.h


%Main: %.o %Main.o
	$(CXX) -o $@ $^ $(LIBS)

%Test: %.o %Test.o
	$(CXX) -o $@ $^ -lgtest -lgtest_main -lpthread $(LIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) -o $@ -c $<

clean:
	rm -f *.o
	rm -f TetrisMain
	rm -f TetrisTest
