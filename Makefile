main: principal.o main.o
	g++ principal.o main.o -o main --std=c++11 -O2 -larmadillo

principal.o: principal.cpp
	g++ -c principal.cpp --std=c++11 -O2 -larmadillo

main.o: main.cpp
	g++ -c main.cpp --std=c++11 -O2 -larmadillo

clean:
	rm main *.o
