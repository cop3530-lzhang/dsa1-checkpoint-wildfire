SHELL := /bin/bash
CXX := g++
CXXFLAGS := -std=c++14 -Wall -Werror=return-type -Werror=uninitialized \
		-Wno-sign-compare
RM := rm -rf
TESTS := test-1-wildfire test-2-wildfire test-3-wildfire
CATCH = test/catch/catch.o

test-all: $(TESTS)

test-1-wildfire: test/test-1-wildfire.o wildfire.o $(CATCH)
	$(CXX) -o $@ $^
	./$@
test-2-wildfire: test/test-2-wildfire.o wildfire.o $(CATCH)
	$(CXX) -o $@ $^
	./$@
test-3-wildfire: test/test-3-wildfire.o wildfire.o $(CATCH)
	$(CXX) -o $@ $^
	./$@

clean:
	$(RM) *.o *.gc* $(CATCH) test/*.o $(TESTS)
