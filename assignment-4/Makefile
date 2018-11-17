CXX = g++ -g
CHECKSTYLE = python ../cpplint.py
LIBS = -lncurses
HEADERS = $(wildcard *.h)
MAIN = $(basename $(wildcard *Main.cpp))
TEST = $(basename $(wildcard *Test.cpp))

.PRECIOUS: %.o

all: compile test checkstyle

compile: $(MAIN)

test: $(TEST) 
	for T in $(TEST); do ./$$T; done

checkstyle:
	$(CHECKSTYLE) *.cpp *.h


%Main: %.o %Main.o
	$(CXX) -o $@ $^ $(LIBS)

%Test: %.o %Test.o
	$(CXX) -o $@ $^ -lgtest -lgtest_main -lpthread $(LIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) -o $@ -c $<

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test
