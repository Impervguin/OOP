CC=g++

CPPFLAGS=-Werror -Wpedantic -Wall -std=c++20 -g
# CPPFLAGS= -std=c++20
CPPLIBS = -lsqlite3
CPPINCLUDE= 

main.exe : src/main.cpp src/*/*.cpp 
	$(CC) $(CPPFLAGS)  $(CPPINCLUDE) $^ -o $@ $(CPPLIBS)
