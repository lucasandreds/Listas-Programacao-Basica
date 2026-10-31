CC=g++
CFLAGS=-std=c++20 -Wall -Iinclude

all: vpl_execution

pessoa.o: include/pessoa.h src/pessoa.cpp
	${CC} ${CFLAGS} -c src/pessoa.cpp -o build/pessoa.o 

funcionario.o: include/funcionario.h src/funcionario.cpp
	${CC} ${CFLAGS} -c src/funcionario.cpp -o build/funcionario.o

professor.o: include/professor.h src/professor.cpp
	${CC} ${CFLAGS} -c src/professor.cpp -o build/professor.o

main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o build/main.o

vpl_execution: main.o professor.o funcionario.o pessoa.o
	${CC} ${CFLAGS} -o vpl_execution build/main.o build/professor.o build/funcionario.o build/pessoa.o

clean:
	rm -f vpl_execution build/*.o