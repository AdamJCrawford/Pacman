
Pacman: food.o game.o map.o node.o sprite.o
	g++ food.o game.o map.o node.o sprite.o -o Pacman -lsfml-graphics -lsfml-window -lsfml-system

cookie.o: cookie.cpp headers/cookie.h
	g++ -c cookie.cpp

food.o: food.cpp headers/food.h
	g++ -c food.cpp

fruit.o: fruit.cpp headers/fruit.h
	g++ -c fruit.cpp

game.o: game.cpp
	g++ -c game.cpp

ghost.o: ghost.cpp headers/ghost.h
	g++ -c ghost.cpp

map.o: map.cpp headers/map.h
	g++ -c map.cpp

node.o: node.cpp headers/node.h
	g++ -c node.cpp

pacdot.o: pacdot.cpp headers/pacdot.h
	g++ -c pacdot.cpp

sprite.o: sprite.cpp headers/sprite.h
	g++ -c sprite.cpp

clean:
	rm *.o Pacman
