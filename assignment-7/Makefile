CXX = g++ -g
# CXX = g++ -fno-elide-constructors
CHECKSTYLE = python ../cpplint.py
MAIN = $(basename $(wildcard *Main.cpp))
TEST = $(basename $(wildcard *Test.cpp))
OBJECTS = $(addsuffix .o, $(filter-out %Main %Test, $(basename $(wildcard *.cpp))))
HEADERS = $(wildcard *.h)
LIBS =

.PRECIOUS: %.o

all: compile test checkstyle

compile: $(MAIN)

test: $(TEST)
	for T in $(TEST); do ./$$T; done

checkstyle:
	$(CHECKSTYLE) *.cpp *.h

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

%Test: %Test.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS) -lgtest -lgtest_main -lpthread

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f *.o
	rm -f core
	rm -f $(MAIN)
	rm -f $(TEST)
