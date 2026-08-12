SHELL := /bin/bash
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare
RM = rm -rf

TESTS = test-1-wildfire test-2-wildfire test-3-wildfire
CATCH = test/catch/catch.o

all: $(TESTS)

test-all: $(TESTS)

test-1-wildfire: test/test-1-wildfire.o wildfire.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-2-wildfire: test/test-2-wildfire.o wildfire.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-3-wildfire: test/test-3-wildfire.o wildfire.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

$(CATCH): test/catch/catch.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test-mem: test-3-wildfire
	valgrind --leak-check=full --error-exitcode=1 ./test-3-wildfire

clean:
	$(RM) *.o *.gc* test/*.o *.dSYM $(TESTS) $(CATCH)

.PHONY: all test-all test-1-wildfire test-2-wildfire test-3-wildfire test-mem clean
