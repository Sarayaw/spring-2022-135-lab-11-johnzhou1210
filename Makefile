main: main.o profile.o
	g++ -o main main.o profile.o

tests: tests.o profile.o
	g++ -o tests tests.o profile.o

main.o: main.cpp profile.h

tests.o: tests.cpp doctest.h profile.h

profile.o: profile.cpp profile.h

clean:
	rm -f main.o tests.o profile.o
