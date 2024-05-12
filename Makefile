#!make -f

CXX=clang++
CXXFLAGS=-std=c++11 -Wall -Wextra -g
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

run: demo
	./$^

demo: Demo.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test: TestCounter.o Test.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) $^ -o $@

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

tidy:
	clang-tidy $(SRCS) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) demo test