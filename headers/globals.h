#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobject.h"
#include <SFML/Graphics.hpp>

// Board will be 25 x 25, can change if need be.
// This needs to be odd so Pacman can start in the middle of the screen
inline int map_length = 25;
inline int map_width = 25;

inline bool scatter_mode = 0;
inline int  score        = 0;

inline int curr_key = 0;

inline std::vector<GameObject *> characters;

#endif
