main: principal.o main.o
	g++ principal.o main.o -o main --std=c++11

principal.o: principal.cpp
	g++ -c principal.cpp --std=c++11

main.o: main.cpp
	g++ -c main.cpp --std=c++11

clean:
	rm main *.o
