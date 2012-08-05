all: test

test: main.o menu.o button.o
	g++ main.o menu.o button.o -lsfml-graphics -lsfml-window -lsfml-system -o test

main.o: src/main.cpp
	g++ -c src/main.cpp

menu.o: src/menu.cpp src/menu.hpp
	g++ -c src/menu.cpp src/menu.hpp

button.o: src/button.cpp src/menu.hpp
	g++ -c src/button.cpp src/button.hpp

clean:
	rm test

