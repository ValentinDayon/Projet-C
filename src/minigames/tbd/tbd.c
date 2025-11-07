#include "tbd.h"

static void mg_init(void) {}
static void mg_update(float dt) { (void)dt; }
static void mg_draw(void) {
    DrawText("Mini-jeu TBD (stub)", 40, 80, 28, RAYWHITE);
    DrawText("Backspace: retour", 40, 120, 20, LIGHTGRAY);
}
static void mg_unload(void) {}

MinigameAPI GetMinigameTBD(void) {
    MinigameAPI api = { mg_init, mg_update, mg_draw, mg_unload };
    return api;
}


