# C++ Compiler (GNU)
CC=g++

# Compilation flags
CFLAGS=

indexgame_serial.exe: indexgame_serial.o
	$(CC) -o $@ $^

indexgame_serial.o: indexgame_serial.cpp
	$(CC) ${CFLAGS} -c $<

clean:
	rm -r *.o *.exe
