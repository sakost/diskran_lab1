CC=g++
CFLAGS=-std=c++17 -O3
EXECUTABLE=solution
SRC=lab1.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

benchmark: benchmark.o
	$(CC) $(FLAGS) benchmark.o -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

benchmark.o: benchmark.cpp pair.h sort.h vector.h
	$(CC) $(CFLAGS) -c $< -o $@

lab1.o: pair.h sort.h vector.h

clean:
	rm -f *.o $(EXECUTABLE)
