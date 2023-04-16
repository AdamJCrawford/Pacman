
Pacman: cookie.o edge.o food.o fruit.o game.o gameobject.o ghost.o map.o node.o pacdot.o pacman.o sprite.o
	g++ cookie.o edge.o food.o fruit.o game.o gameobject.o ghost.o map.o node.o pacdot.o pacman.o sprite.o -o Pacman -lsfml-graphics -lsfml-window -lsfml-system

cookie.o: cookie.cpp headers/cookie.h
	g++ -c cookie.cpp

edge.o: edge.cpp headers/edge.h
	g++ -c edge.cpp

food.o: food.cpp headers/food.h
	g++ -c food.cpp

fruit.o: fruit.cpp headers/fruit.h
	g++ -c fruit.cpp

game.o: game.cpp
	g++ -c game.cpp

gameobject.o: gameobject.cpp headers/gameobject.h
	g++ -c gameobject.cpp

ghost.o: ghost.cpp headers/ghost.h
	g++ -c ghost.cpp

map.o: map.cpp headers/map.h
	g++ -c map.cpp

node.o: node.cpp headers/node.h
	g++ -c node.cpp

pacdot.o: pacdot.cpp headers/pacdot.h
	g++ -c pacdot.cpp

pacman.o: pacman.cpp headers/pacman.h
	g++ -c pacman.h

sprite.o: sprite.cpp headers/sprite.h
	g++ -c sprite.cpp

clean:
	rm *.o Pacman
