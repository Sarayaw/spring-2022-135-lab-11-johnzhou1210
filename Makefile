main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o

main.o: main.cpp profile.h network.h

tests.o: tests.cpp doctest.h profile.h network.h

profile.o: profile.cpp profile.h

network.o: network.cpp network.h profile.h

clean:
	rm -f main.o tests.o profile.o network.o
