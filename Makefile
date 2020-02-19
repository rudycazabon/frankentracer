
SRC=src /home/rjcazab/Projects/sandbox/cpp-smallpt/cpp-smallpt/cpp-smallpt/src
INC=/home/rjcazab/Projects/sandbox/cpp-smallpt/cpp-smallpt/cpp-smallpt/src

CC=dpcpp

cpp-smallpt:
	$(CC) src/cpp-smallpt.cpp -o cpp-smallpt -I$(INC) -O3 -std=c++17 -fopenmp

clean:
	rm -f cpp-smallpt
