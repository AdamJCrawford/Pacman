
Pacman: node.o gameobject.o edge.o food.o cookie.o pacdot.o sprite.o ghost.o pacman.o game.o map.o
	g++ node.o gameobject.o edge.o food.o cookie.o pacdot.o sprite.o ghost.o pacman.o game.o map.o -o Pacman -lsfml-graphics -lsfml-window -lsfml-system -std=c++17

cookie.o: cookie.cpp headers/cookie.h
	g++ -c cookie.cpp -std=c++17

edge.o: edge.cpp headers/edge.h
	g++ -c edge.cpp -std=c++17

food.o: food.cpp headers/food.h
	g++ -c food.cpp -std=c++17

game.o: game.cpp
	g++ -c game.cpp -std=c++17

gameobject.o: gameobject.cpp headers/gameobject.h
	g++ -c gameobject.cpp -std=c++17

ghost.o: ghost.cpp headers/ghost.h
	g++ -c ghost.cpp -std=c++17

map.o: map.cpp headers/map.h
	g++ -c map.cpp -std=c++17

node.o: node.cpp headers/node.h
	g++ -c node.cpp -std=c++17

pacdot.o: pacdot.cpp headers/pacdot.h
	g++ -c pacdot.cpp -std=c++17

pacman.o: pacman.cpp headers/pacman.h
	g++ -c pacman.cpp -std=c++17

sprite.o: sprite.cpp headers/sprite.h
	g++ -c sprite.cpp -std=c++17

clean:
	rm *.o Pacman
