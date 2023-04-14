
Pacman: food.o game.o gameobject.o map.o node.o sprite.o
	g++ food.o game.o gameobject.o map.o node.o sprite.o -o Pacman

food.o: food.cpp food.h
	g++ -c food.cpp

game.o: game.cpp
	g++ -c game.cpp

gameobject.o: gameobject.cpp gameobject.h
	g++ -c gameobject.cpp

map.o: map.cpp map.h
	g++ -c map.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

sprite.o: sprite.cpp sprite.h
	g++ -c sprite.cpp

clean:
	rm *.o Pacman
