#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobject.h"

// Board will be 19 x 19, can change if need be.
// This needs to be odd so Pacman can start in the middle of the screen
inline int map_length, map_width = 25;

inline bool scatter_mode = 0;
inline int  score        = 0;

inline int curr_key = 0;

inline std::vector<GameObject *> characters;

#endif
