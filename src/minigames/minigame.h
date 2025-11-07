#ifndef MINIGAME_H
#define MINIGAME_H

#include "raylib.h"

typedef struct MinigameAPI {
    void (*init)(void);
    void (*update)(float dt);
    void (*draw)(void);
    void (*unload)(void);
    bool (*isCompleted)(int *coinsOut);
} MinigameAPI;

#endif // MINIGAME_H


